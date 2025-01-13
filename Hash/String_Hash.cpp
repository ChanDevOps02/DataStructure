#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
long long Polynomial(const string& mystring) //해시값을 구하는 함수
{
	const int p = 31; //작은소수 
	const long long m = 1000000007; //큰 소수
	long long hash_value = 0;//해시값
	for (const char& c : mystring)
	{
		hash_value = (hash_value * p + c) % m;
	}
	return hash_value;
}
vector<bool> Solution(vector<string>& string_list, vector<string>& query_list)
{
	unordered_set<long long>hash; //해시값을 저장할 해시 테이블
	for (const string& temp1 : string_list)
	{
		long long hash_value = Polynomial(temp1);
		hash.insert(hash_value);
	}
	vector<bool>result;
	for (const string& temp2 : query_list) //비교 문자열의 해시값을 구한 후 해시 테이블과 비교
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
	vector<string>string_list; //주어진 문자열
	for (int i = 0; i < count1; i++)
	{
		string temp;
		cin >> temp;
		string_list.push_back(temp);
	}
	cin >> count2;
	vector<string>query_list; //비교할 문자열
	for (int i = 0; i < count2; i++)
	{
		string temp;
		cin >> temp;
		query_list.push_back(temp);
	}
	vector<bool>answer = Solution(string_list, query_list); //bool 값 출력
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