#include <iostream>
#include <string>
#include <map>
using namespace std;
map<int, int> m;
void shenqing()
{
	cout << "����������������������,��ʽ�磨2,3����" << endl;
	char c;
	int a, b;
	cin >> c >> a >> c >> b >> c;
	if (a > b)
	{
		int temp = a;
		a = b;
		b = a;
	}
	for (int i = a; i <= b; ++i)
	{
		if (m[i])
		{
			cout << i << "����̨�Ѿ���ռ���ˣ�����������" << endl;
			return;
		}
	}
	for (int i = a; i <= b; ++i)
		++m[i];
	cout << "����ɹ���ף��������" << endl;
}
void tui()
{
	cout << "��������Ҫ�˻����������,��ʽ�磨2,3����" << endl;
	char c;
	int a, b;
	cin >> c >> a >> c >> b >> c;
	if (a > b)
	{
		int temp = a;
		a = b;
		b = a;
	}
	for (int i = a; i <= b; ++i)
	{
		if (!m[i])
		{
			cout << i << "����̨û�б�ռ�ã�����������" << endl;
			return;
		}
	}
	for (int i = a; i <= b; ++i)
		--m[i];
	cout << "�˻��ɹ�����ӭ�ٴι���" << endl;
}
int main()
{
	for (int i = 1; i <= 100; ++i)
		m[i] = 0;
	while (1)
	{
		cout << "�����밴1���»��밴2,�˳������밴3��" << endl;
		int cmd;
		cin >> cmd;
		switch (cmd)
		{
		case 1:	shenqing(); break;
		case 2:	tui(); break;
		case 3: return 0; break;
		default:cout << "ָ�������������" << endl; break;
		}
	}
}

//void fun1()
//{
//	cout << "����������������������뷶Χ����ʽ��1 10����";
//	int beg, ed;
//	cin >> beg >> ed;
//	if (beg > ed)
//	{
//		int temp = ed;
//		ed = beg;
//		beg = temp;
//	}
//	bool flag = true;
//	int t;
//	for (int i = beg; i <= ed; ++i)
//	{
//		if (a[i] == 1)
//		{
//			flag = false;
//			t = i;
//			break;
//		}
//	}
//	if (flag)
//	{
//		for (int i = beg; i <= ed; ++i)
//		{
//			a[i] = 1;
//		}
//		cout << "����ɹ���" << endl;
//	}
//	else
//	{
//		cout << t << "�������Ѿ���ռ�ã�" << endl;
//	}
//}
//void fun2()
//{
//	cout << "�����������˶����������뷶Χ����ʽ��1 10����";
//	int beg, ed;
//	cin >> beg >> ed;
//	if (beg > ed)
//	{
//		int temp = ed;
//		ed = beg;
//		beg = temp;
//	}
//	bool flag = true;
//	int t;
//	for (int i = beg; i <= ed; ++i)
//	{
//		if (a[i] == 0)
//		{
//			flag = false;
//			t = i;
//			break;
//		}
//	}
//	if (flag)
//	{
//		for (int i = beg; i <= ed; ++i)
//		{
//			a[i] = 0;
//		}
//		cout << "�˶��ɹ���" << endl;
//	}
//	else
//	{
//		cout << t << "������û�л�û�б���Ŷ�ף�" << endl;
//	}
//}
//int main()
//{
//	memset(a, 0, sizeof(a));
//	while (1)
//	{
//		cout << "����1����������" << endl;
//		cout << "����2���˶�����" << endl;
//		int t;
//		cin >> t;
//		if (t == 1)
//			fun1();
//		else if (t == 2)
//			fun2();
//		else
//			cout << "��������룡" << endl;
//	}
//}