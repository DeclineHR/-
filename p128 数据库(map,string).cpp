#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<sstream>
using namespace std;

typedef pair<int, int> PII;

const int maxr = 10000 + 5;
const int maxc = 10 + 5;

int m, n, db[maxr][maxc], cnt;

map<string, int> id;
int ID(const string& s) {
    if (!id.count(s)) {
        id[s] = ++cnt;
    }
    return id[s];
}
void find() {
    for (int c1 = 0; c1 < m; c1++)//遍历每一列，c1 是第一列的索引。
        for (int c2 = c1 + 1; c2 < m; c2++) {
            //遍历 c1 之后的所有列，c2 是第二列的索引。
            map<PII, int> d;
            //映射 d 用于存储每一行中两列的值对。
            // 对于每一对列 (c1, c2)，d 会存储该对列中每一行的值对 (db[i][c1], db[i][c2])。
            //PII 是 pair<int, int> 的别名，表示一个包含两个整数的对
            for (int i = 0; i < n; i++) {
                PII p = make_pair(db[i][c1], db[i][c2]);
                //创建一个包含当前列 c1 和 c2 的值的键值对。
                if (d.count(p)) {
                  //如果 d 中已经存在某个值对，
                  // 这意味着至少有两行在这对列中的值是相同的，因此可以确定列 c1 和 c2 是相同的。
                    printf("NO\n");
                    printf("%d %d\n", d[p] + 1, i + 1);
                    printf("%d %d\n", c1 + 1, c2 + 1);
                    return;
                }
                d[p] = i;
            }
        }
    printf("YES\n");
}
int main() {
    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        if (!(ss >> n >> m)) break;
        cnt = 0;
        id.clear();
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            int lastpos = -1;//初始化 lastpos 变量，它用于记录上一次找到逗号的位置。
            //初始值为 -1 表示还没有找到逗号。
            for (int j = 0; j < m; j++) {
                int p = s.find(',', lastpos + 1);//在字符串 s 中查找逗号 , 的位置，从 lastpos + 1 开始搜索。
                //lastpos 是上一次找到逗号的位置，这样就能够找到下一个逗号的位置。
                //当你使用 std::string 的 find 方法来搜索一个子串，
                // 如果该子串不存在于主字符串中，find 方法就会返回 string::npos。
                if (p == string::npos) p = s.length();
                //如果没有找到逗号，则将 p 设置为字符串 s 的长度。
                //记录该完整的值。
                db[i][j] = ID(s.substr(lastpos + 1, p - lastpos - 1));
                //使用 substr 方法提取从 lastpos + 1 到 p - lastpos - 1（不包括 p）的子串，
                //然后调用 ID 函数将这个子串转换为一个唯一的整数 ID。这个 ID 被存储在 db[i][j] 中
                lastpos = p;
                //更新 lastpos 为当前找到的逗号的位置，为下一次迭代准备。
            }
        }
        find();
    }
    return 0;
}
