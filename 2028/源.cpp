#include <iostream>
using namespace std;
int aaa(int a,int b)
{
	int a1, b1;
	if (a < b)
	{
		a1 = b;
		b1 = a;
	}
	else
	{
		a1 = a;
		b1 = b;
	}
	//�����Լ���������b1
	int temp = a1%b1;
	while (temp)
	{
		a1 = b1;
		b1 = temp;
		temp = a1%b1;
	}
	//���￪ʼ�ּ���a*b����һ�����ţ�a*b���ܻᳬ��32λ�ķ�Χ
	return a*(b/b1);
}
int main()
{
	int n;
	while (cin >> n)
	{
		int a, b;
		cin >> a;
		for (int i = 1; i < n; ++i)
		{
			cin >> b;
			a = aaa(a, b);
		}
		cout << a << endl;
	}
	return 0;
}