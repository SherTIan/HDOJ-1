//��n��������ǰ���n-1���ཻ����4��n-1�������㣬�����������߼�4(n-1)���߶Σ��������ߵĶ��㴦�������߶�ֻ����һ����������hn=hn-1+4(n-1)-1+2����hn=2n^2-n+1;
#include <iostream>
using namespace std;
int main()
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		cout << 2 * n*n - n + 1 << endl;
	}
	return 0;
}