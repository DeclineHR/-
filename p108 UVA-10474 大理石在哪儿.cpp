//Uva10474 大理石在哪儿
//https://www.luogu.com.cn/problem/UVA10474
//MoloXuanhe版本
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int N, Q;
    bool flag = false;
    int round = 0;
    do {   
        cin >> N >> Q;
        if (!N && !Q) {
            return 0;
        }
        int p = 0;
        vector<int>v(N);
        vector<int>v2(Q + 1);
        round++;
        for (int i = 0; i < N; i++) {//输入
            cin >> v[i]; 
        }
        for (int i = 0; i < Q; i++) {//输入
            cin >> v2[i]; 
        }
        sort(v.begin(), v.end());
        cout << "CASE# " << round << ":" << endl;
        for (int i = 0; i < Q; i++) {
            flag = false;
            for (int j = 0; j < N; j++) {//判断 + 输出
                if (p > Q) {
                    break;
                }
                if (v[j] == v2[p]) {
                    cout << v2[p] << " found at " << j + 1 << endl;
                    p++;
                    flag = true;
                    continue;
                }
                else if (j == N - 1 && !flag) {
                    cout << v2[p] << " not found" << endl;
                    p++;
                }
            }
        }
        v.clear();
        v2.clear();
    } while (1);
    return 0;
}
//jiaru Lui版本
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 10000;

int main() {
    int n, q, x, a[maxn], kase = 0;
    while (scanf("%d%d", &n, &q) == 2 && n) {
        printf("CASE# %d:\n", ++kase);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a + n); // 排序
        while (q--) {
            scanf("%d", &x);//每输入一个元素 判断一次；
            int p = lower_bound(a, a + n, x) - a; // 在已排序数组a中寻找x
            //lower_bound 会返回指向第一个不小于 x 的元素的迭代器，
            //然后通过减去数组的起始地址 a 来计算位置 p。
            if (p < n && a[p] == x) printf("%d found at %d\n", x, p + 1);
            else printf("%d not found\n", x);
        }
    }
    return 0;
}
