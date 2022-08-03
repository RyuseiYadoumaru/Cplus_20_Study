#include <iostream>

//�@�o�������X�g
//�@���X�g�̊e�v�f���O�ƌ��̗v�f�̏���
//�@���悤�Ƀ����N�������f�[�^�\��
//�@�v�f�̍폜��}����萔���Ԃōs����B
//�@�v�f�̃A�N�Z�X���ԁFO(N)


/****	�m�[�h	****/
class Node
{
public:
	int m_key;

	Node* m_prev;	//�O�m�[�h
	Node* m_next;	//���m�[�h

};

/****	�o�������X�g	****/
class LinledList
{

public:
	LinledList()
	{
		nil = new Node;
		nil->m_prev = nil;
		nil->m_next = nil;
	}

	//Key��擪�ɑ}��
	void insert(int key)
	{
		Node* x;	//�V�����m�[�h�������|�C���^

		x = new Node;
		x->m_key = key;

		//�m�[�h���Ȃ�����
		//�@���擪�m�[�h�̃A�h���X��ۑ�
		x->m_next = nil->m_next;

		//�A���擪�m�[�h�̌��ɐV�����m�[�h��ǉ�
		nil->m_next->m_prev = x;

		//�B�擪�A�h���X�ɐV�����m�[�h���L�^
		nil->m_next = x;

		//�C�擪�A�h���X�̑O�m�[�h��ԕ��ɂ���
		x->m_prev = nil;

	}

	//�m�[�h�폜
	void DeleteKey(int key)
	{
		DeleteNode(ListSearch(key));
	}

	//�擪���폜
	void DeleteFront()
	{
		DeleteNode(nil->m_next);
	}

	//�������폜
	void DeleteBack()
	{
		DeleteNode(nil->m_prev);
	}

	//���X�g�\��
	void PrintList()
	{
		int cnt = 0;
		//�擪�m�[�h
		Node* current = nil->m_next;

		while (current != nil)
		{
			cnt++;
			if (cnt > 0) std::cout << " ";

			std::cout << current->m_key;
			current = current->m_next;
		}

		std::cout << std::endl;

	}

private:

	//�ԕ��@
	//�f�[�^��̍Ō�ɏI�[��\���_�~�[�̃f�[�^
	Node* nil;

	//Key�����ŏ��̃|�C���^��Ԃ�
	Node* ListSearch(int key)
	{
		Node* current = nil->m_next;

		//�L�[�T��
		while (current != nil && current->m_key != key)
		{
			//���݂̃m�[�h���玟�̃m�[�h�ɃA�N�Z�X����
			current = current->m_next;
		}

		return current;
	}

	//�m�[�h�폜
	void DeleteNode(Node* node)
	{
		//�m�[�h���ԕ��̎��͉������Ȃ�
		if (node == nil) return;

		//�m�[�h���Ȃ�����
		node->m_prev->m_next = node->m_next;
		node->m_next->m_prev = node->m_prev;

		delete node;
	}

};


int main()
{
	LinledList list;
	for (int i = 10; i > 0; i--) list.insert(i);
	list.PrintList();

	//�����폜
	list.PrintList();
	list.PrintList();

	//�擪�폜
	list.DeleteFront();
	list.PrintList();

	//�C�Ӄm�[�h�폜
	list.DeleteKey(3);
	list.PrintList();

	return 0;
}