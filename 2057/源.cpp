#include <iostream>
#include <string>
using namespace std;
//��Ȼ�������ڵ����࣬����ž�žવģ����ǻ����ɻ�Ϊʲô��WA������
//A��������
//��һ��a,b��Ϊ����ʱ��stoint������ȡ������Ӻ�ᳬ����Χ����˲����Ӻ���ȡ������Ϊ�ж�����ķ���λ
//�ڶ���intos����ж�a>16��Ϊa>=16!!!TT
void stoint(string A,unsigned long long &a)
{
	for (int i = A.size() - 1; i >= 0; --i)
	{
		if (A[i] == '+' || A[i] == '-')
			break;
		long long x;
		if (A[i] >= '0'&&A[i] <= '9')
		{
			x = A[i] - 0x30;
		}
		else if (A[i] >= 'A'&&A[i] <= 'F')
		{
			x = A[i] - 'A' + 10;
		}
		for (int j = A.size() - i - 1; j >= 1; --j)
		{
			x *= 16;
		}
		a += x;
	}
	//if (A[0] == '-')
	//	a *= -1;
}
void intos(string &A, unsigned long long a)
{
	for (int i = 0; i <= 15; ++i)
	{
		int temp = a % 16;
		char c;
		if (temp < 10)
		{
			c = temp + 0x30;
			A += c;
		}
		else if (temp >= 10)
		{
			c = temp - 10 + 'A';
			A += c;
		}
		//�˴�
		if (a >= 16)
			a /= 16;
		else
			return;	
	}
}
int main()
{
	string A;
	while (cin >> A)
	{
		string B;
		cin >> B;
		unsigned long long a = 0, b = 0;
		stoint(A, a);
		stoint(B, b);
		if (A[0] != '-')
		{
			if (B[0] != '-')
				a += b;
			else
			{
				if (a < b)
				{
					cout << '-';
					a = b - a;
				}
				else
				{
					a -= b;
				}
			}
		}
		else
		{
			if (B[0] != '-')
			{
				if (a<= b)
				{
					a = b - a;
				}
				else
				{
					a -= b;
					cout << '-';
				}
			}
			else
			{
				a += b;
				cout << '-';
			}
		}
		//bool flag = true;
		//if (a < 0)
		//{
		//	cout << '-';
		//	a *= -1;
		//}
		A = "";
		intos(A, a);
		for (int i = A.size() - 1; i >= 0; --i)
		{
			cout << A[i];
		}
		cout << endl;
	}
	return 0;
}