//二分查找:只使用于有序序列
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int b_search(int* A, int x, int y, int v) {//数组A,范围在x ~ y之间,要查找的数字v
    int m;
    while (x < y) {
        m = x + (y - x) / 2;
        if (A[m] == v) return m;//若找到了 返回v所在的坐标
        else if (A[m] > v)y = m;//如果A[m]大于v  则让y = m折中
        else x = m + 1;
    }
    return -1;
}
int main() {
    int A[10] = { 0,1,2,3,4,5,6,7,8,9 };
    cout << b_search(A, 0, 9, 6);
    return 0;
}
