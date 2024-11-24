#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<set>
#include<cstdio>
using namespace std;
const int coeff[3] = {2,3,5};
typedef long long LL;
int main() {
	priority_queue<LL, vector<LL>, greater<LL> >pq;
	set<LL>s;
	pq.push(1);
	s.insert(1);//set起统计是否出现的作用
	for (int i = 0;; i++) {
		LL x = pq.top(); pq.pop();//取出最小的 并且出列 
		//第一次最小为1 生成2 3 5
		//第二次最小为2 生成4 6 10 以此类推 将不重复的数加入set容器 便能找出所有的丑数
		if (i == 1500) {//找到第1500个丑数
			cout << "The 1500'th ugly number is " << x << ".\n";
			break;
		}
		for (int j = 0; j < 3; j++) {
			LL x2 = x * coeff[j];
			if (!s.count(x2)) { s.insert(x2); pq.push(x2); }
		}
	}
	return 0;
}
