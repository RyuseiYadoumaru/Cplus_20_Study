#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	int data;
	Node* parent;
	Node* left;
	Node* right;
};


class BinarySearchTree
{

public:
	Node* root;
	Node* NIL;

public:
	//�f�[�^X�����m�[�h��T������
	Node* Find(Node* node, int searchData)
	{
		while (node != nullptr)
		{
			if (searchData == node->data)
			{
				//�f�[�^����
				return node;
			}

			else if (searchData < node->data)
			{
				//�f�[�^��������
				return Find(node->left, searchData);

			}

			else
			{
				//�f�[�^�E������
				return Find(node->right, searchData);
			}

			//�f�[�^���Ȃ��Ƃ�
			return nullptr;

		}
	}
};