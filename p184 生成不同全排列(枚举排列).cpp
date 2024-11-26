#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

int a[1000] = { 0 };
void print(int n, int * a, int cunrent) {
    if (cunrent == n) {
        for (int i = 0;i < n; i++)printf("%d", a[i]);
        printf("\n");
    }
    else {
        for (int i = 1; i <= n; i++) {
            int ok = 1;
            for(int j = 0;j < cunrent;j++)   if (a[j] == i) ok = 0;//使用过了则不执行输出

                if (ok) {
                    a[cunrent] = i;//未使用 存储
                    print(n, a, cunrent + 1);
                }
    }
    }
}
int main() {
    int n;
    cin >> n;
    print(n,a,0);//cunrent一开始为0 用于标记元素位置 0 1 2 .....
    return 0;
}
