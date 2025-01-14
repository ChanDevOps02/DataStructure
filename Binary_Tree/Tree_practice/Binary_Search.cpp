#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
	int value;
	Node* left;
	Node* right;
	Node(int key):value(key),left(nullptr),right(nullptr){}
};
class BST
{
private:
	Node* root;
	Node* insertNode(Node* node, int key)
	{
		if (node == nullptr)
		{
			return new Node(key);
		}
		else if (key < node->value)
		{
			node->left = insertNode(node->left, key);
		}
		else if (key >= node->value)
		{
			node->right = insertNode(node->right, key);
		}
		return node;
	}
	bool searchNode(Node* node, int key)
	{
		if (node == nullptr)
		{
			return false;
		}
		else if (node->value == key)
		{
			return true;
		}
		return key < node->value ? searchNode(node->left, key) : searchNode(node->right, key);
	}
public:
	BST():root(nullptr){} //root는 초기값 nullptr로 초기화
	void insert(int key)
	{
		root = insertNode(root, key); //key값을 트리에 삽입
	}
	bool search(int key)
	{
		return searchNode(root, key); //해당값을 트리구조에서 탐색
	}
};
vector<bool> Solution(vector<int>& lst, vector<int>& search_list)
{
	BST bst;
	vector<bool>result;
	for (const int& temp : lst)
	{
		bst.insert(temp); //Binary tree 생성
	}
	for (const int& temp : search_list)
	{
		result.push_back(bst.search(temp)); //Binary tree에서 search_list를 탐색한 후 값이 존재하면 true, 아니면 false
	}
	return result;
}
int main(void)
{
	int count1; //lst의 개수
	cin >> count1;
	vector<int>lst;
	for (int i = 0; i < count1; i++)
	{
		int num;
		cin >> num;
		lst.push_back(num);
	}
	int count2;//search_list의 개수
	cin >> count2;
	vector<int>search_list;
	for (int i = 0; i < count2; i++)
	{
		int num;
		cin >> num;
		search_list.push_back(num);
	}
	vector<bool>answer = Solution(lst, search_list);
	for (const bool temp : answer)
	{
		if (temp)
		{
			cout << "TRUE" << " ";
		}
		else if (!temp)
		{
			cout << "FALSE" << " ";
		}
	}
	return 0;
}