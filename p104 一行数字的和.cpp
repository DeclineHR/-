#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main() {
    //实现一行数字的和
    //输入10 20 30
    //输出60
    string line1;
    while (getline(cin, line1)) {
        long long sum = 0, x;
        stringstream ss (line1);//创建字符串流ss
        //会自动获取元素 遇到空格终止 进行下个获取
        while (ss >> x) sum += x;
        cout << sum << endl;
    }
    return 0;
}
