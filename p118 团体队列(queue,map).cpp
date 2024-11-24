#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<map>
#include<cstdio>
using namespace std;
const int maxt = 1000 + 10;

int main() {
	int t, kase = 0;
	while (scanf("%d", &t) == 1 && t) {
		printf("Scenario #%d\n", ++kase);
		//记录所有人的团队编号
		map<int, int>team;
		for (int i = 0; i < t; i++) {
			int n, x;
			scanf("%d", &n);
			while(n--){
				scanf("%d", &x); team[x] = i;//x为key值 i为对应数
			}
		}
		queue<int>q, q2[maxt];//q为全部团队的队列 q2为每个队列的队列
		for (;;) {
			int x;
			char cmd[10];
			scanf("%s", cmd);
			if (cmd[0] == 'S')break;//STOP：停止模拟。
			else if (cmd[0] == 'D') {//DEQUEUE：长队的 队首 出队。
				int t = q.front();
				printf("%d\n", q2[t].front()); q2[t].pop();
				if (q2[t].empty()) q.pop();//团体t全体出队列
			}
			else if (cmd[0] == 'E') {//ENQUEUE x：编号为 xx 的人进入长队。
				scanf("%d", &x);
				int t = team[x];//根据team的key值来查找  t = 返回数值0或者1
				//如输入
				//2 团队数
				//3 101 102 103 则团队0成员 :101 102 103
				//3 201 202 203 则团队1成员 :101 102 103
				if (q2[t].empty())q.push(t);// 如果没有该队列 则在q中创建这个队列q2[t]
				q2[t].push(x);
			}
		}
		printf("\n");
	}
	return 0;
}
