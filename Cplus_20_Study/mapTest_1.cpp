
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <iostream>

#define TEST_CASE_1
//#define TEST_CASE_2
//#define TEST_CASE_3

/**
 * マップの登録と更新順を確認する
 */

int main()
{
	std::map<int, std::string> nameList;
	std::unordered_map <int, std::string>  nameList_Unorederd;

	std::vector<std::string> AllNameList
	{
		"いのうえ",
		"うえしま",
		"かとう",
		"きのした",
		"ことうげ"
	};


	//登録
#ifdef TEST_CASE_1
	constexpr static int RegisterNum = 2;
	for (int num = 0; num < RegisterNum; num++)
	{
		nameList[1] = AllNameList[num];
		nameList_Unorederd[1] = AllNameList[num];
	}
#endif 

#ifdef TEST_CASE_2
	nameList[0] = AllNameList[0];
	nameList[3] = AllNameList[3];
	nameList[2] = AllNameList[2];
	nameList[1] = AllNameList[1];

	nameList_Unorederd[0] = AllNameList[0];
	nameList_Unorederd[3] = AllNameList[3];
	nameList_Unorederd[2] = AllNameList[2];
	nameList_Unorederd[1] = AllNameList[1];
#endif

#ifdef TEST_CASE_3
	std::map<std::string, int> nameList_2;
	std::unordered_map <std::string,int>  nameList_Unorederd_2;
	
	nameList_2[AllNameList[0]] = 0;
	nameList_2[AllNameList[3]] = 3;
	nameList_2[AllNameList[2]] = 2;
	nameList_2[AllNameList[1]] = 1;

	nameList_Unorederd_2[AllNameList[0]] = 0;
	nameList_Unorederd_2[AllNameList[3]] = 3;
	nameList_Unorederd_2[AllNameList[2]] = 2;
	nameList_Unorederd_2[AllNameList[1]] = 1;

	//map
	std::cout << "Open Name List (Map)" << std::endl;
	for (auto index : nameList_2)
	{
		std::cout << index.first << ":" << index.second << std::endl;
	}

	//unordered_map
	std::cout << "\nOpen Name List (Unorederd_Map)" << std::endl;
	for (auto index : nameList_Unorederd_2)
	{
		std::cout << index.first << ":" << index.second << std::endl;
	}

	return 0;
#endif


	//map
	std::cout << "Open Name List (Map)" << std::endl;
	for (auto name : nameList)
	{
		std::cout << name.first << ":" << name.second << std::endl;
	}

	//unordered_map
	std::cout << "\nOpen Name List (Unorederd_Map)" << std::endl;
	for (auto name : nameList_Unorederd)
	{
		std::cout << name.first << ":" << name.second << std::endl;
	}

}





