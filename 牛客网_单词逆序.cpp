
/*********************
[�����]��������
ʱ�����ƣ�1��

�ռ����ƣ�65536K

����һ���ַ����������һ���㷨��ֻ���ַ����ĵ��ʼ������������Ҳ����˵���ַ�����һЩ�ɿո�ָ��Ĳ�����ɣ�����Ҫ����Щ��������
����һ��ԭ�ַ���A���뷵���������ַ�������������"I am a boy!", ���"boy! a am I"

��������:
����һ���ַ���str��(1<=strlen(str)<=10000)

�������:
�����������ַ�����

��������1:
It's a dog!

�������1:
dog! a It's

*@Problem Link:
*@Problem ID :
*@Author :LOVESHEART
*@Language :MS C++ 2017
*********************/
#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
#define endl "\n"
#define mn 405000
#define INF 0x3f3f3f3f
#define LINF 9223372036854775807
#define ri register int
#define f(i,x,y) for(ri i=x;i<=y;i++)
#define df(i,y,x) for(ri i=y;i>=x;i--)
#define m(a, b) memset(a, b, sizeof a)
#define I inline
typedef long long ll;
#define LL ll
#define log(x) cout<<x<<endl
using namespace std;

int a, b;
string s;
vector<int> aa, bb;
char res[10000];
I void init() {
	getline(cin, s);
}
I void solve() {
	int l = s.length(), cnt = 0;
	a = -1; b = -1;
	f(i, 0, l - 1) {
#ifdef DEBUG
		if (i == 1995)
			cout << endl;
#endif
		if (cnt == 0)cnt++;
		//if (i == 0) {
		//	cnt++;
		//	//a = i;
		//}
		else if (s[i] == ' ' || i == l - 1)cnt++;
		if (a == -1 && cnt == 1)a = i;
		else if (b == -1 && cnt == 2)b = i;
		if (i == l - 1)b++;
		//��a+1��b-1Ϊ����
		if (cnt == 2) {
			cnt = 0;
			bb.push_back(b - 1);
			aa.push_back(a);
			a = -1; b = -1;
		}
		if (cnt == 1 && i == l - 1) {
			cnt = 0;
			bb.push_back(a);
			aa.push_back(a);
			a = -1; b = -1;
		}
	}
	//�������ܴ���ÿһ������
	//��λ�ȡ���һ�����ʣ�
	int resCnt = 0;
	while (!aa.empty()) {
		int i2 = aa.back();
		int i3 = bb.back();
		aa.pop_back();
		bb.pop_back();
		f(i, i2, i3) {
			res[resCnt] = s[i];
			resCnt++;
		}
		/*if (res[resCnt-1] != ' ') */ {
			res[resCnt] = ' ';
			resCnt++;
		}
	}
	res[resCnt] = '\0';
	log(res);
}

int main() {
	ios::sync_with_stdio(false);//'\n'
	cin.tie(0);
	cout.tie(0);
	init();
	solve();
	return 0;
}