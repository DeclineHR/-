#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main() {
    int n, kase = 0;
    //kase 用于记录已经输出的解的个数，初始值为 0。
    char buf[99];//用于存储拼接后的十位数
    while (scanf("%d", &n) == 1 && n) {
        int cnt = 0;
        if (kase++) printf("\n");
        //如果 kase 不为 0（即之前已经输出过解），则在输出新的解之前打印一个换行符。
        for (int fghij = 1234; ; fghij++) {
            int abcde = fghij * n;
            sprintf(buf, "%05d%05d", abcde, fghij);
            //sprintf 将 abcde 和 fghij 格式化为字符串 并拼接到 buf 中。
            if (strlen(buf) > 10) break;//abcde和fghij的总长度大于10则退出循环
            sort(buf, buf + 10);
            bool ok = true;
            for (int i = 0; i < 10; i++)
                if (buf[i] != '0' + i) ok = false;
            //判断buf中元素是否为0123456789;
            if (ok) {
                cnt++;
                printf("%05d / %05d = %d\n", abcde, fghij, n);
            }
        }
        if (!cnt) printf("There are no solutions for %d.\n", n);
    }
    return 0;
}
