#include "Component.h"
#include "ComponentTest.h"

//オブジェクトのリストを定義
std::list<Object*> g_ObjectList;
int main()
{
	//追加
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
		//画面の初期化
		system("cls");
		g_ScreenBuffer.Clear();
		InputData::Update();

		//実際の処理
		//Update中にObjectListがいじられてイテレーションバグるのを回避
		auto buff = g_ObjectList;
		for (auto obj : buff)
			obj->Update();

		for (auto obj : g_ObjectList)
			obj->Draw();

		//Buffer表示
		printf("%s", g_ScreenBuffer.buffer);
		_sleep(100);
	}

	//追加
	for (auto obj : g_ObjectList)
		delete obj;
	g_ObjectList.clear();

	return 0;
}