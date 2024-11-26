#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main() {
    long long b;
    while (cin >> b && b) {
        long long ans = 1;

        long long * p = new long long[b];
        for (int i = 0; i < b; i++) {
            cin >> p[i];
        }
        sort(p, p + b);
        for (int i = 0; i < b; i++) {
            if (p[i] > 0) {
                ans *= p[i];
            }
        }
        if (ans < 0) {
            cout << 0 << endl;
            return 0;
        }
        else { cout << ans << endl; }
    }

    return 0;
}
