#include <iostream>
#include <math.h>
using namespace std;
//����:i*(i+1)/2=m�ĵ�i<sqrt(2m)
int main()
{
	long long N, M;
	while (cin >> N >> M&&N&&M)
	{
		for (int len = (int)sqrt(double(2 * M)); len >= 1; --len)
		{
			//���Ϊbeg������Ϊlen�����к�ΪM�����beg
			//��ѧ��������������ô��5555555555555555
			long long beg = (2 * M / len + 1 - len) / 2;
			long long end = beg + len - 1;
			if ((beg + end)*len == 2 * M)
				cout << '[' << beg << ',' << end << ']' << endl;
		}
		cout << endl;
	}
	return 0;
}
//long long sum = 0;
//for (int i = 1; i <= M / 2; ++i)
//{
//	for (int j = i; j <= M; ++j)
//	{
//		sum += j;
//		if (sum == M)
//		{
//			cout << '[' << i << ',' << j << ']' << endl;
//			sum = 0;
//			break;
//		}
//		else if (sum > M)
//		{
//			sum = 0;
//			break; 
//		}
//	}
//}
//cout << '[' << M << ',' << M<< ']' << endl;