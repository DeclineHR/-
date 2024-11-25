https://www.luogu.com.cn/problem/UVA400
#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
	const int maxcol = 60;//定义一行最多60个字符
	const int maxn = 105;//文件数量 1 ~ 100
	string filenames[maxn];
void print(const string& s, int len,char extra){//打印单个文件名 默认extra = ' '
	cout << s;
	for (int i = 0; i < len - s.size(); i++) {
		cout << extra;
	}
}
int main() {
	int n;
	while (cin >> n) {
		int M = 0;
		for (int i = 0; i < n; i++) {
			cin >> filenames[i];
			M = max(M, (int)filenames[i].length());//M = 最长文件名的长度
		}
		// 计算列数cols和行数rows
		//一行最多60个字符 最长文件名有M 字符   maxcol - M 得到剩余的可用字符
		//M + 2为每个文件名占用的字符大小
		//(maxcol - M) / (M + 2）得到一行的文件个数 即列数
		int cols = ( (maxcol - M) / (M + 2) ) + 1; //cols为文件一行的个数
		//加上1 是因为至少需要一列来打印文件名
		int	rows = (n - 1) / cols + 1;
		//(n - 1) / cols 计算在给定列数的情况下，
		//cols 加1  则文件数量 - 1 
		//需要多少行来打印所有文件名，但这个结果可能不包括最后一行

		print("", 60, '-');
		cout << "\n";

		sort(filenames, filenames + n);
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				int idx = c * rows + r;
				//当rows = 5
				//print 0  5  10  15
				//print 1  6  11  16
				//print 2  8  13  18
				//print 3  9  14  19
				//print 4  10 15  20
				if (idx < n) print(filenames[idx], c == cols - 1 ? M : M + 2, ' ');
				//c == cols - 1 ? M : M + 2 当c等于cols - 1即最后一个文件名时 len = M  否则len = M + 2
			}
			cout << "\n";
		}
	}
	return 0;
}
