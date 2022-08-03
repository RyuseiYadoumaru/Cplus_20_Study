#include <iostream>

//　双方向リスト
//　リストの各要素が前と後ろの要素の情報を
//　持つようにリンクさせたデータ構造
//　要素の削除や挿入を定数時間で行える。
//　要素のアクセス時間：O(N)


/****	ノード	****/
class Node
{
public:
	int m_key;

	Node* m_prev;	//前ノード
	Node* m_next;	//次ノード

};

/****	双方向リスト	****/
class LinledList
{

public:
	LinledList()
	{
		nil = new Node;
		nil->m_prev = nil;
		nil->m_next = nil;
	}

	//Keyを先頭に挿入
	void insert(int key)
	{
		Node* x;	//新しいノードがさすポインタ

		x = new Node;
		x->m_key = key;

		//ノードをつなぎ直す
		//①旧先頭ノードのアドレスを保存
		x->m_next = nil->m_next;

		//②旧先頭ノードの後ろに新しいノードを追加
		nil->m_next->m_prev = x;

		//③先頭アドレスに新しいノードを記録
		nil->m_next = x;

		//④先頭アドレスの前ノードを番兵にする
		x->m_prev = nil;

	}

	//ノード削除
	void DeleteKey(int key)
	{
		DeleteNode(ListSearch(key));
	}

	//先頭を削除
	void DeleteFront()
	{
		DeleteNode(nil->m_next);
	}

	//末尾を削除
	void DeleteBack()
	{
		DeleteNode(nil->m_prev);
	}

	//リスト表示
	void PrintList()
	{
		int cnt = 0;
		//先頭ノード
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

	//番兵法
	//データ列の最後に終端を表すダミーのデータ
	Node* nil;

	//Keyを持つ最初のポインタを返す
	Node* ListSearch(int key)
	{
		Node* current = nil->m_next;

		//キー探索
		while (current != nil && current->m_key != key)
		{
			//現在のノードから次のノードにアクセスする
			current = current->m_next;
		}

		return current;
	}

	//ノード削除
	void DeleteNode(Node* node)
	{
		//ノードが番兵の時は何もしない
		if (node == nil) return;

		//ノードをつなぎ直す
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

	//末尾削除
	list.PrintList();
	list.PrintList();

	//先頭削除
	list.DeleteFront();
	list.PrintList();

	//任意ノード削除
	list.DeleteKey(3);
	list.PrintList();

	return 0;
}