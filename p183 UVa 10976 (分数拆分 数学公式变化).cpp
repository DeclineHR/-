#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
using namespace std;

int main() {
    int k;
    while (scanf("%d", &k) == 1 && k) {
        vector<int> X, Y;
        for (int y = k + 1; y <= k * 2; y++) {
            //由于 1/k = 1/x + 1/y 则 y > k , y(min) = k + 1
            //y <= 2k
            // 1/k = 1/x + 1/y => x = ky/(y-k)
            if (k * y % (y - k) == 0)//取模为0 则得到的x为整数
                //如72 % 10 = 2 则72 / 10 = 7.2不为整数
            {
                X.push_back(k * y / (y - k)); Y.push_back(y);
            }
        }
        printf("%d\n", X.size());//通过X.size()判断有多少个等式
        for (int i = 0; i < X.size(); i++)
            printf("1/%d = 1/%d + 1/%d\n", k, X[i], Y[i]);
    }
    return 0;
}
