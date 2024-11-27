//归并排序
//归并排序是一种分治算法，它将数组分成两半，对每一半进行排序，然后将排序好的两半合并在一起。
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int T[10000];//临时空间
void merge_sort(int* A, int x, int y, int* T) {
    //int* A：这是一个指向整数的指针，它指向要排序的数组
    //int x：这是数组 A 中要排序部分的起始索引
    //int y：这是数组 A 中要排序部分的结束索引
    //int * T 在归并排序中，T 用于存储合并过程中的中间结果
    if (y - x > 1) {
        //如果当前子数组的长度大于 1，则需要排序
        int m = x + (y - x) / 2;
        int  p = x, q = m, i = x;
        //初始化两个指针 p 和 q 分别指向左右两个子数组的开始位置，i 指向临时数组 T 的开始位置。
        merge_sort(A, x, m, T);
        merge_sort(A, m, y, T);
        while (p < m || q < y) {
            if (q >= y || (p < m && A[p] <= A[q]))T[i++] = A[p++];//左半数组复制到临时空间
            else T[i++] = A[q++];//右半数组复制到临时空间
        }
        for (int i = x; i < y; i++) {
            A[i] = T[i];
        }//用于将临时数组 T 中的元素复制回原数组 A。这个过程是在合并两个已排序子数组之后进行的
    }
}
int main() {
   
    return 0;
}
