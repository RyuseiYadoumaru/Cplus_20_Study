#include "Component.h"
#include "ComponentTest.h"

//�I�u�W�F�N�g�̃��X�g���`
std::list<Object*> g_ObjectList;
int main()
{
	//�ǉ�
	Object* obj = new Object;
	obj->AddComponent<Position>();
	obj->AddComponent<Player>();
	g_ObjectList.push_back(obj);

	for (int i = 0; i < 10; i++)
	{
		obj = new Object;
		Position* pos = obj->AddComponent<Position>();
		pos->x = 1;
		pos->y = i;
		obj->AddComponent<Enemy>();
		g_ObjectList.push_back(obj);
	}

	while (!InputData::KeyCheck('p'))
	{
		//��ʂ̏�����
		system("cls");
		g_ScreenBuffer.Clear();
		InputData::Update();

		//���ۂ̏���
		//Update����ObjectList���������ăC�e���[�V�����o�O��̂����
		auto buff = g_ObjectList;
		for (auto obj : buff)
			obj->Update();

		for (auto obj : g_ObjectList)
			obj->Draw();

		//Buffer�\��
		printf("%s", g_ScreenBuffer.buffer);
		_sleep(100);
	}

	//�ǉ�
	for (auto obj : g_ObjectList)
		delete obj;
	g_ObjectList.clear();

	return 0;
}