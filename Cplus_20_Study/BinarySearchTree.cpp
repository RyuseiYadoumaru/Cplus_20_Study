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
	//データXを持つノードを探索する
	Node* Find(Node* node, int searchData)
	{
		while (node != nullptr)
		{
			if (searchData == node->data)
			{
				//データ発見
				return node;
			}

			else if (searchData < node->data)
			{
				//データ左部分木
				return Find(node->left, searchData);

			}

			else
			{
				//データ右部分木
				return Find(node->right, searchData);
			}

			//データがないとき
			return nullptr;

		}
	}
};