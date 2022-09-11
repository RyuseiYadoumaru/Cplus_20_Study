//******************************************************************************
//* @file   Loadcsv_Sample.cpp
//* @brief  csv�����[�h����T���v���R�[�h
//* @note   HEDEC�z�z�p�̃T���v���R�[�h�ł�
//* @note   C++�x�[�X�ŋL�q���܂�
//* 
//* @author YadoumaruRyusei
//* @date   September 2022
// 
// https://qiita.com/shirosuke_93/items/d5d068bb15c8e8817c34
// https://programming.pc-note.net/cpp/filestream.html
//*****************************************************************************

/**
 * �C���N���[�h.
 */
#include <iostream>
#include <string>
#include <map>

/**
 * �t�@�C���̓ǂݏ����ɕK�v�ȃC���N���[�h.
 */
#include <fstream>
#include <sstream>


#define TRUE	(1)
#define FALSE	(0)

/**
 * TRUE�ɂ���ƃT���v�������s���Ă���܂�.
 */
#define LOAD_TEXT		(FALSE)
#define INPUT_PARAM		(FALSE)
#define PRINT_PARAM		(TRUE)
#define OUTPUT_PARAM	(FALSE)


//csv�f�[�^��ǂݍ��ޏ���
enum CSV_DATA
{
	ID			= 0,
	NAME		= 1,
	SPEED		= 2,
	JUMP_FORCE	= 3
};

/**
 * �v���C���[�N���X
 * ����̓v���C��-�̃p�����[�^��CSV�ŊǗ����܂�.
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
	 * csv����f�[�^����͂���T���v��.
	 */
	void InputCSV()
	{
		//�ǂݏ������ł���W�����C�u����
		std::fstream fs;

		//�t�@�C���I�[�v���i�ǂݎ���p�j
		std::string filePath("./Resource/charaParam.csv");
		fs.open(filePath, std::ios::in);

		if (!fs)
		{
			std::cout << "�ǂݍ��݂Ɏ��s" << std::endl;
			return;
		}

		//�i�[�����f�[�^���ꎞ�I�ɂ܂Ƃ߂�Map�R���e�i
		//csv�͕�����f�[�^�Ŏ擾����
		std::map<CSV_DATA, std::string> dataList;

		//getline��1�s���f�[�^����Ƃ���
		//�w�b�_�[�͎g�p���Ȃ��̂Ŏ擾�O�ɂ���Ă���
		std::string lineBuffer;
		std::getline(fs, lineBuffer);

		//�ǂݍ��ލs���Ȃ��Ȃ�܂ŌJ��Ԃ�
		while (std::getline(fs, lineBuffer))
		{
			//[ , ]��؂�Ńf�[�^��ǂݍ��ނ��߂�
			//�s�o�b�t�@��isstringstream�^�ɂ���
			std::istringstream stream(lineBuffer);
			std::string commaBuffer;

			int csvData = CSV_DATA::ID;
			while (std::getline(stream, commaBuffer, ','))
			{
				//int�^��CSV_DATA�ɃL���X�g���邵�Ď擾����
				dataList[static_cast<CSV_DATA>(csvData)] = commaBuffer;
				
				//���̃f�[�^���擾����
				csvData++;
			}
		}

		//�{���ł���΃N���[�Y�����̓f�X�g���N�^�ōs����̂ŏ����Ȃ��Ă�����
		//�����̍D�݂Ŗ����I�ɍs���Ă���
		fs.close();

		//�f�[�^���
		//�I�[�gFor���i�����ŃR���e�i��S�Q�Ƃ��Ă����j
		for (auto data : dataList)
		{
			switch (data.first)
			{
			case CSV_DATA::ID:
				//������int�^
				m_id = stoi(data.second);
				break;

			case CSV_DATA::NAME:
				m_name = data.second;
				break;

			case CSV_DATA::SPEED:
				//������float�^
				m_speed = stof(data.second);
				break;

			case CSV_DATA::JUMP_FORCE:
				//������float�^
				m_jumpForce = stof(data.second);
				break;
			}
		}



	}



	/**
	*  �R���X�g���N�^�ŏ����������p�����[�^���o�͂���T���v��.
	* !@brief �ėp�I�ɂ��邽�߂ɕʓr�t�@�C���̓��o�̓N���X����������������B
	* !@param fileName
	*/
	void OutputCSV(std::string fileName)
	{
		std::string filePath;
		filePath = "./Resource/" + fileName + ".csv";

		//��������csv�t�@�C�����J��(�������݃��[�h)
		std::fstream fs;
		fs.open(filePath, std::ios::out);

		if (!fs)
		{
			std::cout << "�ǂݍ��݂Ɏ��s" << std::endl;
			return;
		}

		//�������ރf�[�^�쐬
		//�w�b�_�[�ɏ������ރf�[�^�쐬
		std::map<CSV_DATA, std::string> header;
		header[CSV_DATA::ID] = "ID";
		header[CSV_DATA::NAME] = "���O";
		header[CSV_DATA::SPEED] = "�X�s�[�h";
		header[CSV_DATA::JUMP_FORCE] = "�W�����v��";

		for (auto data : header)
		{
			//�J���}��؂�ŏ�������
			fs << data.second << ',';
		}

		//���s����
		fs << std::endl;

		std::map<CSV_DATA, std::string> dataList;
		dataList[CSV_DATA::ID] = std::to_string(m_id);
		dataList[CSV_DATA::NAME] = m_name;
		dataList[CSV_DATA::SPEED] = std::to_string(m_speed);
		dataList[CSV_DATA::JUMP_FORCE] = std::to_string(m_jumpForce);

		for (auto data : dataList)
		{
			//�J���}��؂�ŏ�������
			fs << data.second << ',';
		}

		fs.close();
	}



	/**
	 *  �v���C���[������.
	 * 
	 * !@param speed
	 * !@param m_jumpForce
	 */
	void Init(std::string name, float speed, float jumpForce)
	{
		SetName(name);
		SetSpeed(speed);
		SetJumpForce(jumpForce);
		std::cout << "����������" << std::endl;
	}

	/**
	 *  �e�p�����[�^�[�̃Z�b�^�[.
	 */
	void SetName(std::string name) noexcept { m_name = name; }
	void SetID(int id) noexcept { m_id = id; }
	void SetSpeed(float speed) noexcept { m_speed = speed;}
	void SetJumpForce(float jumpForce) noexcept { m_jumpForce = jumpForce; }


	/**
	 * �v���C���[�̃X�e�[�^�X���o�͂���.
	 */
	void PrintPlayerState() 
	{
		std::cout << "ID �F " << m_id << std::endl;
		std::cout << "���O�� �F " << m_name << std::endl;
		std::cout << "�X�s�[�h �F " << m_speed << std::endl;
		std::cout << "�W�����v�� �F " << m_jumpForce << std::endl;
	}

private:
	std::string m_name;
	int m_id;
	float m_speed;
	float m_jumpForce;
};

/**
 * �e�L�X�g�̃T���v�����ꉞ��낤�c.
 */
class TextFileLoader
{
public:

	/**
	 *  �t�@�C���o��.
	 * 
	 * !@param fileName
	 */
	static void  Output(std::string fileName)
	{

		//�t�@�C���p�X�𐶐�����
		//����͑��΃p�X�ŕۑ�����w�肵�Ă��܂�
		std::string filePath;
		filePath = "./Resource/" + fileName + ".txt";


		std::string text;
		std::cout << "�o�͂��镶������͂��Ă�������" << std::endl;
		std::cin >> text;

		//�t�@�C������
		//[std::ofstream]�t�@�C�����o�͂��邽�߂̕W�����C�u����
		std::ofstream ofs;

		//�t�@�C���I�[�v��
		//��Q�����ŃI�[�v�����[�h�̐ݒ肪�\
		//�w�肵�Ȃ��ꍇ�͏������݃��[�h�ɂȂ�
		ofs.open(filePath);

		if (!ofs)
		{
			//�G���[����
			std::cout << "�t�@�C�����J���܂���" << std::endl;
			return;
		}

		//�t�@�C����������
		ofs << text;

		//�t�@�C���N���[�Y
		ofs.close();
	}

	/**
	 * �e�L�X�g�t�@�C������͂��܂�
	 * �t�@�C���p�X�������ɓ���Ă�������.
	 */
	static void Input(std::string filePath)
	{
		//�t�@�C�����o�̓N���X
		//[std::fstream]�F�t�@�C������o�͂��Ă����W�����C�u����
		std::fstream fs;

		//�t�@�C���I�[�v��
		//�ǂݎ�胂�[�h�ŊJ���i�������݂�j�~���邽�߁j
		fs.open(filePath, std::ios::in);

		if (!fs)
		{
			//�G���[����
			std::cout << "�t�@�C�����J���܂���" << std::endl;
			return;
		}


		//�i�[�f�[�^
		std::string inputData;

		while (1)
		{
			//�t�@�C��������s�܂Ńf�[�^��ǂݍ���
			//�e�L�X�g�f�[�^�Ȃ̂ŕ�����Ŏ󂯎��
			//�p�����[�^�Ȃǂɂ���Ƃ��͂�������ϐ��ɉ��H���Ĉ���
			std::string buffer;
			std::getline(fs, buffer);
			//�s���Ƃɒǉ�����
			inputData += buffer + "\n";


			//�t�@�C���I�[����
			if (fs.eof() == true) break;

		}

		//�t���O�N���A
		fs.clear();
		
		//�t�@�C���ʒu���Z�b�g
		fs.seekp(std::ios::beg);

		//�t�@�C���N���[�Y
		fs.close();
		
		//�o��
		std::cout << inputData;
	}
};


/**
 *  ���s����
 * Player�N���X�ɏ������܂Ƃ߂Ă��܂�.
 */
int main()
{
#if LOAD_TEXT
	
	//�t�@�C���o��
	//TextFileLoader::Output("test");

	//�t�@�C������
	//txt�t�@�C���̃p�X��ݒ肵����ǂݍ���ł����
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
	std::cout << "�o�̓t�@�C���̖��O�����߂Ă�������" << std::endl;
	std::string fileName;
	std::cin >> fileName;
	player->OutputCSV(fileName);
#endif // OUTPUT_PARAM

	int ret = getchar();
	return ret;
}
