#include <iostream>
#include <string>
using namespace std;
string str_add(string a, string b)
{
	int j = a.size() - 1;
	int temp = 0;//��λ��־
	for (int i = b.size() - 1; i >= 0; --i, --j)
	{
		int x = a[j] - 0x30 + b[i] - 0x30 + temp;
		a[j] = x % 10 + 0x30;
		temp = x / 10;
	}
	while (temp&&j >= 0)
	{
		int x = a[j] - 0x30 + temp;
		a[j] = x % 10 + 0x30;
		temp = x / 10;
		--j;
	}
	if (temp)
	{
		char c = temp + 0x30;
		a = c + a;
	}
	return a;
}
int main()
{
	string h[2010];//�����쳲�������������
	h[1] = "1";
	h[2] = "2";
	for (int i = 3; i <= 2000; ++i)
	{
		h[i] = str_add(h[i - 1], h[i - 2]);//�ַ�������Ӻ���
	}
	string s1, s2,s3="0";
	while (cin>>s1>>s2)
	{
		if (s1 == s3&&s2 == s3)//�����Ϊ��0�����˳�����
			break;
		if (s1.size() > s2.size() || (s1.size() == s2.size() && s1 > s2))
		{
			string temp = s1;
			s1 = s2;
			s2 = temp;
		}
		int i = 1;
		while (h[i].size() < s1.size() || (h[i].size() == s1.size() && h[i] < s1))//�ҵ���һ��>=s1���ַ���
			++i;
		int sum = 0;
		while (h[i].size() < s2.size() || (h[i].size()==s2.size()&&h[i] <=s2))//�ҳ�����<=s2���ַ���
		{
			++i;
			++sum;
		}
		cout << sum << endl;
	}
	return 0;
}