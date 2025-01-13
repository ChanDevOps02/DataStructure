#include <iostream>
#include <vector>
using namespace std;
void Mapping(vector<int>& hash, vector<int>& arr, int target) //�ؽ� ���̺� ���� �Լ�
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > target)
		{
			continue;
		}
		else
		{
			hash[arr[i]] = 1;
		}
	}
}
bool Solution(vector<int>& arr, int target) //�ؽ����̺�� num���� �� �Լ�
{
	int num;
	vector<int>hash(target + 1, 0);
	Mapping(hash, arr, target);
	for (int i = 0; i < arr.size(); i++)
	{
		num = target - arr[i];
		if (num == arr[i])
		{
			cout << "Integer Collision!" << endl;
			continue;
		}
		else if (num < 0)
		{
			continue;
		}
		else if (hash[num] == 1)
		{
			return true;
		}
	}
	return false;
}
int main(void)
{
	int capacity;
	cin >> capacity;
	vector<int>arr;
	for (int i = 0; i < capacity; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}
	int target;
	cin >> target;
	bool answer = Solution(arr, target);
	if (answer)
	{
		cout << "TRUE" << endl;
	}
	else if (!answer)
	{
		cout << "FALSE" << endl;
	}
	return 0;
}