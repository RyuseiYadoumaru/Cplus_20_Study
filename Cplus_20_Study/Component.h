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

	//オブジェクトが持っているコンポーネントを取得
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

	//オブジェクトが持っているコンポーネントを追加
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


//場所を示すコンポーネント
class Position : public Component
{
public:
	int x, y;
};

//敵コンポーネント
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

//弾コンポーネント
class Bullet : public Component
{
	Position* pos = nullptr;
public:
	void Update()
	{
		if (pos == nullptr)
			pos = Parent->GetComponent<Position>();
		pos->x--;
		//画面外に消えてたら自分を消す
		if (pos->x < 0)
		{
			Parent->ComponentList.remove(this);
			delete this;
			return;
		}

		//ObjectListからEnemyを検索して当たり判定を行い削除もする。
		auto buff = g_ObjectList;
		for (auto obj : buff)
		{
			//全体からEnemyを探す
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
		//移動
		if (InputData::KeyCheck('d') && pos->y < SCREE_NLENGTH - 1)
			pos->y++;
		if (InputData::KeyCheck('a') && pos->y > 0)
			pos->y--;
		if (InputData::KeyCheck('s') && pos->x < SCREE_NLENGTH - 1)
			pos->x++;
		if (InputData::KeyCheck('w') && pos->x > 0)
			pos->x--;

		//球発射
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

