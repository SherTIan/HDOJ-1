//�������ǽʾ���֭�ˣ�һ��AC˼�ܴ����
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string addstring(string s1,string s2)
{
	if (s1.size() > s2.size())
	{
		string temp = s1;
		s1 = s2;
		s2 = temp;
	}
	int flag = s2.size() - 1,up=0;
	for (int i = s1.size() - 1; i >= 0; --i,--flag)
	{
		int temp = s2[flag] - 0x30 + s1[i] - 0x30 + up;
		s2[flag] = temp % 10 + 0x30;
		up = temp / 10;
	}
	while (up)
	{
		if (flag < 0)
		{
			char c = up + 0x30;
			s2 = c + s2;
			break;
		}
		else
		{
			int temp = s2[flag] - 0x30 + up;
			s2[flag] = temp % 10 + 0x30;
			up = temp / 10;
			--flag;
		}
	}
	return s2;
}
string multistring(string s2,string si)
{
	string st = si;
	vector<string> vec;
	for (int i = st.size() - 1; i >= 0; --i)
	{
		string st1 = s2;
		//����ע�͵�Ӧ����������Ϊ0�����
		//if (st[i] == '0')
		//	continue;
		int up = 0;
		for (int j = st1.size() - 1; j >= 0; --j)
		{
			int temp = (st1[j] - 0x30)*(st[i] - 0x30) + up;
			st1[j] = temp % 10 + 0x30;
			up = temp / 10;
		}
		if (up)
		{
			char c = up + 0x30;
			st1 = c + st1;
		}
		for (int j = st.size() - 1 - i; j > 0; --j)
			st1 += '0';
		vec.push_back(st1);
	}
	string s = vec[0];
	for (int i = 1; i < vec.size(); ++i)
	{
		s = addstring(s, vec[i]);
	}
	return s;
}
int main()
{
	string s;
	int num;
	while (cin >> s >> num)
	{
		int i = 0,pt=0;
		string st;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '.')
			{
				pt = s.size() - 1 - i;
			}
			else
				st += s[i];
		}
		s = st;
		if (num == 0)//0�η���������Բ������ǣ���Ŀ�и���0<n<=25
		{
			bool flag = false;
			//�Ƿ�ȫ0
			for (int i = 0; i < s.size(); ++i)
			{
				if (s[i] != '0')
				{
					flag = true;
					break;
				}
			}
			if (flag)//������벻Ϊȫ0�����1
				cout << '1' << endl;
			else
				cout << '0' << endl;
			continue;
		}
		pt*=num;
		for (int i = 1; i < num; ++i)
		{
			s = multistring(s, st);
		}
		if (pt == 0)//������С����
		{
			int k = 0;
			while (s[k] == '0')//ȥ����ʼ��0
				++k;
			for (int i = k; i < s.size(); ++i)
				cout << s[i];
		}
		else
		{
			pt = s.size() - pt;
			if (s[0] == '0'&&pt==1)//����ڶ�λΪС�����ҵ�һλΪ0������ĿҪ��ȥ����0��������0.4321
			{
				//��ʱ����������ǵ�����ΪXX.0
				//cout << '.';
			}
			else
			{
				int k = 0;
				while (s[k] == '0')//ȥ����ʼ��0��������01.4321��00.4321
					++k;
				for (int i = k; i < pt; ++i)
					cout << s[i];
				//��ʱ����������ǵ�����ΪXX.0
				//cout << '.';
			}
			int k = s.size() - 1;
			while (s[k] == '0')//ȥ��β0
			{
				--k;
			}
			if (k >= pt)//�������ΪXX.0����K<pt���������С���㣬�������
				cout << '.';
			for (int i = pt; i <= k; ++i)
			{
				cout << s[i];
			}
		}
		cout << endl;
	}
	return 0;
}