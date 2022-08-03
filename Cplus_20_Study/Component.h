#pragma
#include "ComponentTest.h"

class Component
{
protected:
public:
	Component() {}
	virtual ~Component() {}
	Object* Parent;
	virtual void Start() {}
	virtual void Update() {}
	virtual void Draw() {}
};



class Object
{
public:
	Object() {}
	~Object() {
		for (auto com : ComponentList)
			delete com;
	}

	std::list<Component*> ComponentList;
	void Update()
	{
		auto buff = ComponentList;
		for (auto com : buff)
			com->Update();
	}
	void Draw()
	{
		for (auto com : ComponentList)
			com->Draw();
	}

	//�I�u�W�F�N�g�������Ă���R���|�[�l���g���擾
	template<class T>
	T* GetComponent()
	{
		for (auto com : ComponentList) {
			T* buff = dynamic_cast<T*>(com);
			if (buff != nullptr)
				return buff;
		}
		return nullptr;
	}

	//�I�u�W�F�N�g�������Ă���R���|�[�l���g��ǉ�
	template<class T>
	T* AddComponent()
	{
		T* buff = new T();
		buff->Parent = this;
		ComponentList.push_back(buff);
		buff->Start();
		return buff;
	}
};


//�ꏊ�������R���|�[�l���g
class Position : public Component
{
public:
	int x, y;
};

//�G�R���|�[�l���g
class Enemy : public Component
{
	Position* pos = nullptr;
public:
	void Draw()
	{
		if (pos == nullptr)
			pos = Parent->GetComponent<Position>();
		g_ScreenBuffer.buffer2[pos->x][pos->y] = 'E';
	}
};

//�e�R���|�[�l���g
class Bullet : public Component
{
	Position* pos = nullptr;
public:
	void Update()
	{
		if (pos == nullptr)
			pos = Parent->GetComponent<Position>();
		pos->x--;
		//��ʊO�ɏ����Ă��玩��������
		if (pos->x < 0)
		{
			Parent->ComponentList.remove(this);
			delete this;
			return;
		}

		//ObjectList����Enemy���������ē����蔻����s���폜������B
		auto buff = g_ObjectList;
		for (auto obj : buff)
		{
			//�S�̂���Enemy��T��
			if (obj->GetComponent<Enemy>() == nullptr)
				continue;
			if (obj->GetComponent<Position>()->x == pos->x && obj->GetComponent<Position>()->y == pos->y) {
				g_ObjectList.remove(obj);
				delete obj;
			}
		}
	}
	void Draw()
	{
		if (pos == nullptr)
			pos = Parent->GetComponent<Position>();
		g_ScreenBuffer.buffer2[pos->x][pos->y] = 'b';
	}
};

class Player : public Component
{
	Position* pos = nullptr;
public:
	void Start()
	{
		if (pos == nullptr)
			pos = Parent->GetComponent<Position>();
		pos->x = 5; pos->y = 8;
	}
	void Draw()
	{
		if (pos == nullptr)
			pos = Parent->GetComponent<Position>();
		g_ScreenBuffer.buffer2[pos->x][pos->y] = 'p';
	}

	void Update()
	{
		if (pos == nullptr)
			pos = Parent->GetComponent<Position>();
		//�ړ�
		if (InputData::KeyCheck('d') && pos->y < SCREE_NLENGTH - 1)
			pos->y++;
		if (InputData::KeyCheck('a') && pos->y > 0)
			pos->y--;
		if (InputData::KeyCheck('s') && pos->x < SCREE_NLENGTH - 1)
			pos->x++;
		if (InputData::KeyCheck('w') && pos->x > 0)
			pos->x--;

		//������
		if (InputData::KeyCheck(' '))
		{
			Object* obj = new Object;
			Position* posb = obj->AddComponent<Position>();
			obj->AddComponent<Bullet>();
			posb->y = pos->y;
			posb->x = pos->x - 1;
			g_ObjectList.push_back(obj);
		}
	}
};

