#define _CRT_SECURE_NO_WARNINGS_
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
//第一行输入n表示有n个数
//第二行输入n个数字 进行排列
//然后生成这些整数的所有排列，并按字典序升序打印出来。
int main() {
    int n, p[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    sort(p, p + n);
    do {
        for (int i = 0; i < n; i++)printf("%d", p[i]);
        printf("\n");
    } while (next_permutation(p, p + n));
    //next_permutation 是 C++ 标准库中的一个函数
    //用于生成给定序列的下一个字典序排列
    //返回值为bool  成功生成下一个排列返回true 否则返回false
    return 0;
}
//3
//1 2 3
//123
//132
//213
//231
//312
//321
