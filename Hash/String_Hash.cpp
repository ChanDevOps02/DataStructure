#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
long long Polynomial(const string& mystring) //�ؽð��� ���ϴ� �Լ�
{
	const int p = 31; //�����Ҽ� 
	const long long m = 1000000007; //ū �Ҽ�
	long long hash_value = 0;//�ؽð�
	for (const char& c : mystring)
	{
		hash_value = (hash_value * p + c) % m;
	}
	return hash_value;
}
vector<bool> Solution(vector<string>& string_list, vector<string>& query_list)
{
	unordered_set<long long>hash; //�ؽð��� ������ �ؽ� ���̺�
	for (const string& temp1 : string_list)
	{
		long long hash_value = Polynomial(temp1);
		hash.insert(hash_value);
	}
	vector<bool>result;
	for (const string& temp2 : query_list) //�� ���ڿ��� �ؽð��� ���� �� �ؽ� ���̺�� ��
	{
		long long hash_value = Polynomial(temp2);
		bool result_value = (hash.find(hash_value) != hash.end());
		result.push_back(result_value);
	}
	return result;
}
int main(void)
{
	int count1, count2;
	cin >> count1;
	vector<string>string_list; //�־��� ���ڿ�
	for (int i = 0; i < count1; i++)
	{
		string temp;
		cin >> temp;
		string_list.push_back(temp);
	}
	cin >> count2;
	vector<string>query_list; //���� ���ڿ�
	for (int i = 0; i < count2; i++)
	{
		string temp;
		cin >> temp;
		query_list.push_back(temp);
	}
	vector<bool>answer = Solution(string_list, query_list); //bool �� ���
	for (int i = 0; i < count2; i++)
	{
		if (answer[i])
		{
			cout << "TRUE" << " ";
		}
		else if (!answer[i])
		{
			cout << "FALSE" << " ";
		}
	}
	return 0;
}