//******************************************************************************
//* @file   Loadcsv_Sample.cpp
//* @brief  csvをロードするサンプルコード
//* @note   HEDEC配布用のサンプルコードです
//* @note   C++ベースで記述します
//* 
//* @author YadoumaruRyusei
//* @date   September 2022
// 
// https://qiita.com/shirosuke_93/items/d5d068bb15c8e8817c34
// https://programming.pc-note.net/cpp/filestream.html
//*****************************************************************************

/**
 * インクルード.
 */
#include <iostream>
#include <string>
#include <map>

/**
 * ファイルの読み書きに必要なインクルード.
 */
#include <fstream>
#include <sstream>


#define TRUE	(1)
#define FALSE	(0)

/**
 * TRUEにするとサンプルを実行してくれます.
 */
#define LOAD_TEXT		(FALSE)
#define INPUT_PARAM		(FALSE)
#define PRINT_PARAM		(TRUE)
#define OUTPUT_PARAM	(FALSE)


//csvデータを読み込む順番
enum CSV_DATA
{
	ID			= 0,
	NAME		= 1,
	SPEED		= 2,
	JUMP_FORCE	= 3
};

/**
 * プレイヤークラス
 * 今回はプレイヤ-のパラメータをCSVで管理します.
 */
class Player
{

public:
	Player() :
		m_name("noname"),
		m_id(-1),
		m_speed(5.0f),
		m_jumpForce(5.0f) {}

	~Player() = default;

public:

	/**
	 * csvからデータを入力するサンプル.
	 */
	void InputCSV()
	{
		//読み書きができる標準ライブラリ
		std::fstream fs;

		//ファイルオープン（読み取り専用）
		std::string filePath("./Resource/charaParam.csv");
		fs.open(filePath, std::ios::in);

		if (!fs)
		{
			std::cout << "読み込みに失敗" << std::endl;
			return;
		}

		//格納したデータを一時的にまとめるMapコンテナ
		//csvは文字列データで取得する
		std::map<CSV_DATA, std::string> dataList;

		//getlineで1行分データを主とする
		//ヘッダーは使用しないので取得前にやっておく
		std::string lineBuffer;
		std::getline(fs, lineBuffer);

		//読み込む行がなくなるまで繰り返す
		while (std::getline(fs, lineBuffer))
		{
			//[ , ]区切りでデータを読み込むために
			//行バッファをisstringstream型にする
			std::istringstream stream(lineBuffer);
			std::string commaBuffer;

			int csvData = CSV_DATA::ID;
			while (std::getline(stream, commaBuffer, ','))
			{
				//int型をCSV_DATAにキャストするして取得する
				dataList[static_cast<CSV_DATA>(csvData)] = commaBuffer;
				
				//次のデータを取得する
				csvData++;
			}
		}

		//本来であればクローズ処理はデストラクタで行われるので書かなくていいが
		//自分の好みで明示的に行っている
		fs.close();

		//データ代入
		//オートFor分（自動でコンテナを全参照してくれる）
		for (auto data : dataList)
		{
			switch (data.first)
			{
			case CSV_DATA::ID:
				//文字列→int型
				m_id = stoi(data.second);
				break;

			case CSV_DATA::NAME:
				m_name = data.second;
				break;

			case CSV_DATA::SPEED:
				//文字列→float型
				m_speed = stof(data.second);
				break;

			case CSV_DATA::JUMP_FORCE:
				//文字列→float型
				m_jumpForce = stof(data.second);
				break;
			}
		}



	}



	/**
	*  コンストラクタで初期化したパラメータを出力するサンプル.
	* !@brief 汎用的にするために別途ファイルの入出力クラスを作った方がいい。
	* !@param fileName
	*/
	void OutputCSV(std::string fileName)
	{
		std::string filePath;
		filePath = "./Resource/" + fileName + ".csv";

		//書き込むcsvファイルを開く(書き込みモード)
		std::fstream fs;
		fs.open(filePath, std::ios::out);

		if (!fs)
		{
			std::cout << "読み込みに失敗" << std::endl;
			return;
		}

		//書き込むデータ作成
		//ヘッダーに書き込むデータ作成
		std::map<CSV_DATA, std::string> header;
		header[CSV_DATA::ID] = "ID";
		header[CSV_DATA::NAME] = "名前";
		header[CSV_DATA::SPEED] = "スピード";
		header[CSV_DATA::JUMP_FORCE] = "ジャンプ力";

		for (auto data : header)
		{
			//カンマ区切りで書き込む
			fs << data.second << ',';
		}

		//改行する
		fs << std::endl;

		std::map<CSV_DATA, std::string> dataList;
		dataList[CSV_DATA::ID] = std::to_string(m_id);
		dataList[CSV_DATA::NAME] = m_name;
		dataList[CSV_DATA::SPEED] = std::to_string(m_speed);
		dataList[CSV_DATA::JUMP_FORCE] = std::to_string(m_jumpForce);

		for (auto data : dataList)
		{
			//カンマ区切りで書き込む
			fs << data.second << ',';
		}

		fs.close();
	}



	/**
	 *  プレイヤー初期化.
	 * 
	 * !@param speed
	 * !@param m_jumpForce
	 */
	void Init(std::string name, float speed, float jumpForce)
	{
		SetName(name);
		SetSpeed(speed);
		SetJumpForce(jumpForce);
		std::cout << "初期化完了" << std::endl;
	}

	/**
	 *  各パラメーターのセッター.
	 */
	void SetName(std::string name) noexcept { m_name = name; }
	void SetID(int id) noexcept { m_id = id; }
	void SetSpeed(float speed) noexcept { m_speed = speed;}
	void SetJumpForce(float jumpForce) noexcept { m_jumpForce = jumpForce; }


	/**
	 * プレイヤーのステータスを出力する.
	 */
	void PrintPlayerState() 
	{
		std::cout << "ID ： " << m_id << std::endl;
		std::cout << "名前を ： " << m_name << std::endl;
		std::cout << "スピード ： " << m_speed << std::endl;
		std::cout << "ジャンプ力 ： " << m_jumpForce << std::endl;
	}

private:
	std::string m_name;
	int m_id;
	float m_speed;
	float m_jumpForce;
};

/**
 * テキストのサンプルも一応作ろう….
 */
class TextFileLoader
{
public:

	/**
	 *  ファイル出力.
	 * 
	 * !@param fileName
	 */
	static void  Output(std::string fileName)
	{

		//ファイルパスを生成する
		//今回は相対パスで保存先を指定しています
		std::string filePath;
		filePath = "./Resource/" + fileName + ".txt";


		std::string text;
		std::cout << "出力する文字を入力してください" << std::endl;
		std::cin >> text;

		//ファイル生成
		//[std::ofstream]ファイルを出力するための標準ライブラリ
		std::ofstream ofs;

		//ファイルオープン
		//第２引数でオープンモードの設定が可能
		//指定しない場合は書き込みモードになる
		ofs.open(filePath);

		if (!ofs)
		{
			//エラー処理
			std::cout << "ファイルが開けません" << std::endl;
			return;
		}

		//ファイル書き込み
		ofs << text;

		//ファイルクローズ
		ofs.close();
	}

	/**
	 * テキストファイルを入力します
	 * ファイルパスを引数に入れてください.
	 */
	static void Input(std::string filePath)
	{
		//ファイル入出力クラス
		//[std::fstream]：ファイルを入出力してくれる標準ライブラリ
		std::fstream fs;

		//ファイルオープン
		//読み取りモードで開く（書き込みを阻止するため）
		fs.open(filePath, std::ios::in);

		if (!fs)
		{
			//エラー処理
			std::cout << "ファイルが開けません" << std::endl;
			return;
		}


		//格納データ
		std::string inputData;

		while (1)
		{
			//ファイルから改行までデータを読み込む
			//テキストデータなので文字列で受け取る
			//パラメータなどにするときはここから変数に加工して扱う
			std::string buffer;
			std::getline(fs, buffer);
			//行ごとに追加する
			inputData += buffer + "\n";


			//ファイル終端判定
			if (fs.eof() == true) break;

		}

		//フラグクリア
		fs.clear();
		
		//ファイル位置リセット
		fs.seekp(std::ios::beg);

		//ファイルクローズ
		fs.close();
		
		//出力
		std::cout << inputData;
	}
};


/**
 *  実行処理
 * Playerクラスに処理をまとめています.
 */
int main()
{
#if LOAD_TEXT
	
	//ファイル出力
	//TextFileLoader::Output("test");

	//ファイル入力
	//txtファイルのパスを設定したら読み込んでくれる
	TextFileLoader::Input("Resource/test.txt");

#endif 


	Player* player = new Player();
#if INPUT_PARAM
	player->InputCSV();
#endif 


#if PRINT_PARAM
	player->PrintPlayerState();
#endif


#if OUTPUT_PARAM
	std::cout << "出力ファイルの名前を決めてください" << std::endl;
	std::string fileName;
	std::cin >> fileName;
	player->OutputCSV(fileName);
#endif // OUTPUT_PARAM

	int ret = getchar();
	return ret;
}
