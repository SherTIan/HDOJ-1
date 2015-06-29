//���ر��������Ѻ��Ѻ���
#include <iostream>
#include <algorithm>
using namespace std;
int tol, dp[60000], num[7];
const int INF = 10000005;
void pack(int value)//01����
{
	for (int i = tol; i >= value; --i)
		dp[i] = max(dp[i], dp[i - value] + value);
}
void complete(int value)//��ȫ����
{
	for (int i = value; i <= tol; ++i)
		dp[i] = max(dp[i], dp[i - value] + value);
}
void multipack(int value, int ans)
{
	if (value*ans >= tol)
		complete(value);
	else
	{
		int k = 1;
		while (k < ans)//�����Ʒֽ�
		{
			pack(value*k);
			ans -= k;
			k <<= 1;
		}
		if (ans)
			pack(ans*value);
	}
}
int main()
{
	int flag = 1;
	while (cin >> num[1] >> num[2] >> num[3] >> num[4] >> num[5] >> num[6])
	{
		if (!num[1] && !num[2] && !num[3] && !num[4] && !num[5] && !num[6])
			break;
		cout << "Collection #" << flag++ << ":" << endl;
		tol = 0;
		for (int i = 1; i <= 6; ++i)
			tol += (num[i] * i);
		if (tol & 1)
		{
			cout << "Can't be divided." << endl << endl;
			continue;
		}
		tol /= 2;
		//װ�����dp[0]���ʼ��ΪINF����һ��װ����ʼ��Ϊ0���˴�������ã
		for (int i = 1; i <= tol; ++i)
			dp[i] = -INF;
		dp[0] = 0;
		for (int i = 1; i <= 6; ++i)
			multipack(i, num[i]);
		if (dp[tol] == tol)
			cout << "Can be divided." << endl << endl;
		else
			cout << "Can't be divided." << endl << endl;
	}
	return 0;
}