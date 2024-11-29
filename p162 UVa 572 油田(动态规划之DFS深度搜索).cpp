//https://www.luogu.com.cn/problem/UVA572
//动态规划之 DFS深度搜索的思想体现
/*1.递归函数调用：dfs 函数通过递归调用自身来探索与当前格子(r, c) 连通的所有格子。
这是 DFS 的核心特征，即通过递归深入探索尽可能深的路径。

2.连通分量编号：在 dfs 函数中，当找到一个未访问的 "@" 格子时，会将其标记为已访问（idx[r][c] = id）
，并分配一个连通分量编号 id。这个编号确保了所有通过递归调用访问到的连通格子都会被分配相同的编号。

3.遍历相邻格子：在 dfs 函数中，通过两层嵌套循环遍历当前格子的四个相邻格子（上、下、左、右）。
如果相邻格子是未访问的 "@" 格子，就递归调用 dfs 函数继续探索。
这个过程体现了 DFS 的“深入”特性，即沿着一个方向尽可能深地探索，直到没有更多的格子可以访问。

4.终止条件：DFS 的终止条件包括：
超出地图边界（r < 0 || r >= m || c < 0 || c >= n）。
	当前格子已经被访问过（idx[r][c] > 0）。
	当前格子不是 "@" 格子（pic[r][c] != '@'）。
5.连通分量计数：在 main 函数中，通过一个计数器 cnt 来跟踪发现的连通分量数量。
每次找到一个未访问的 "@" 格子时，cnt 会增加，然后传递给 dfs 函数作为连通分量编号。*/
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
char pic[maxn][maxn];
int m, n, idx[maxn][maxn];
void dfs(int r, int c, int id) {
	if (r < 0 || r >= m || c < 0 || c >= n) return;
	//这行代码检查当前格子 (r, c) 是否超出了地图的边界。
	//如果超出边界，则直接返回，不进行进一步处理。
	if (idx[r][c] > 0 || pic[r][c] != '@')return;
	// 不是"@" 或者 不是已经访问过的格子
	idx[r][c] = id;//连通分量编号
	//这行代码将当前格子标记为已访问(!= 0)，并且分配一个连通分量编号 id。

	//开始一个循环，遍历当前格子的上下左右四个方向。
	for (int dr = -1; dr <= 1; dr++) {
		for (int dc = -1; dc <= 1; dc++) {
			if (dr != 0 || dc != 0) dfs(r + dr, c + dc, id);
			//这个 dfs 函数的目的是
			//递归地标记所有与起始格子 (r, c) 连通的 "@" 格子，
			//并给它们分配 相同 的连通分量编号。
			//这样可以确保所有连通的 "@" 格子都被归为同一个连通分量。
		}
	}
}
int main() {
	while (scanf("%d%d", &m, &n) == 2 && m && n) {//读取行数m 列数n
		for (int i = 0; i < m; i++) scanf("%s", pic[i]);
		//二维字符数组 pic 来存储地图的每个格子
		memset(idx, 0, sizeof(idx));
		//使用 memset 函数将 idx 数组初始化为 0，表示所有格子都未被访问过。
		int cnt = 0;//cnt（连通分量计数器） 各自区块代号
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (idx[i][j] == 0 && pic[i][j] == '@') dfs(i, j, ++cnt);
			}
		}
				printf("%d\n", cnt);
	}
	return 0;
}
