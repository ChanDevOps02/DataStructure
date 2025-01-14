#include <iostream>
#include <vector>
#include <string>
using namespace std;
string Preorder(vector<int>node, int idx)
{
	if (idx < node.size())
	{
		string ret = to_string(node[idx]) + " ";
		ret += Preorder(node, 2 * idx + 1);
		ret += Preorder(node, 2 * idx + 2);
		return ret;
	}
	return "";
}
string Inorder(vector<int>node, int idx)
{
	if (idx < node.size())
	{
		string ret = Inorder(node, 2 * idx + 1);
		ret += to_string(node[idx]) + " ";
		ret += Inorder(node, 2 * idx + 2);
		return ret;
	}
	return "";
}
string Postorder(vector<int>node, int idx)
{
	if (idx < node.size())
	{
		string ret = Inorder(node, 2 * idx + 1);
		ret += Inorder(node, 2 * idx + 2);
		ret += to_string(node[idx]) + " ";
		return ret;
	}
	return "";
}
vector<string> Solution(vector<int>& node)
{
	vector<string>result(3);
	string Preordr = Preorder(node, 0);
	string Inordr = Inorder(node, 0);
	string Postordr = Postorder(node, 0);
	Preordr.pop_back();
	Inordr.pop_back();
	Postordr.pop_back();
	result.push_back(Preordr);
	result.push_back(Inordr);
	result.push_back(Postordr);
	return result;
}
int main(void)
{
	int count;
	cin >> count;
	vector<int>node(count);
	for (int i = 0; i < count; i++)
	{
		cin >> node[i];
	}
	vector<string>answer = Solution(node);
	for (const string& temp : answer)
	{
		cout << temp << endl;
	}
	return 0;
}