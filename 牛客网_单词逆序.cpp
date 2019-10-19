
/*********************
[编程题]单词逆序
时间限制：1秒

空间限制：65536K

对于一个字符串，请设计一个算法，只在字符串的单词间做逆序调整，也就是说，字符串由一些由空格分隔的部分组成，你需要将这些部分逆序。
给定一个原字符串A，请返回逆序后的字符串。例，输入"I am a boy!", 输出"boy! a am I"

输入描述:
输入一行字符串str。(1<=strlen(str)<=10000)

输出描述:
返回逆序后的字符串。

输入例子1:
It's a dog!

输出例子1:
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
		//则a+1到b-1为单词
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
	//这样就能存入每一个单词
	//如何获取最后一个单词？
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