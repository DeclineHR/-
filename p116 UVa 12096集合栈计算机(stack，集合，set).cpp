#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
//定义宏  类似函数
#define ALL(x) x.begin(),x.end()//定义了迭代器的区间
#define INS(x) inserter(x,x.begin())//定义插入宏 
//inserter 的典型用法是 std::inserter(container, container.begin())，
//这会创建一个插入迭代器，该迭代器将元素插入到 container 的 begin() 位置。

//inserter 是一个创建插入迭代器的函数模板，而 insert 是容器类的成员函数，用于在容器中插入元素。
//inserter 通常与算法一起使用，而 insert 直接在容器上调用。
using namespace std;
	typedef set<int> Set;
	//这行代码为 set<int> 创建了一个别名 s，使得在代码中可以使用 s 来代替set<int>。
	map<Set, int> IDcache;//一个map，用于缓存集合和它们的ID之间的映射
	vector<Set>setcache; //一个vector，用于缓存所有的集合。
	int ID(Set x) {//这个函数用于将一个集合转换为一个唯一的ID。
		if (IDcache.count(x)) return IDcache[x];
		//如果集合已经在IDcache中，则直接返回其ID；
		setcache.push_back(x);	
		//如果不在，则将集合添加到setcache中，并在IDcache中创建一个新的映射。
		return IDcache[x] = setcache.size() - 1;
}//size() - 1 实际上是最后一个元素的索引

int main(){
	int T;
	cin >> T;
	while (T--) {//轮数
		stack<int>sk;
		int n; cin >> n;//指令的个数
		for (int i = 0; i < n; i++) {
			string op;
			cin >> op;//通过开通首字母即可区分指令
			//使用if else 分为两类 一类需要弹出2给栈顶元素 另一类不需要
			if (op[0] == 'P')sk.push(  ID(  Set()  )  );
			//PUSH：将空集{}压栈 DUP：
			//Set()：这是一个空的 set<int> 类型的集合。
			//在 C++ 中，Set 是set<int>的别名,所以Set()就是创建了一个空的整数集合。
			else if (op[0] == 'D') sk.push(sk.top());
			// DUP：将栈顶元素复制一份压入栈中
			else {
				//从栈sk中取出两个整数索引（每次取出后都弹出栈顶元素）
				Set x1 = setcache[sk.top()]; sk.pop();
				Set x2 = setcache[sk.top()]; sk.pop();
				Set ans;//创建了名为x的set容器来存储结果
				if (op[0] == 'U') set_union(ALL(x1), ALL(x2), INS(ans));//取x1和x2的并集 然后存储在x中
				//UNION：先进行两次弹栈，将获得的集合A和B取并集，将结果压栈
				if (op[0] == 'I') set_intersection(ALL(x1), ALL(x2), INS(ans));
				//INTERSECTION：先进行两次弹栈，将获得的集合A和B取交集，将结果压栈 
				if (op[0] == 'A') { ans = x2; ans.insert(ID(x1)); }
				//ADD：先进行两次弹栈，在获得的集合A和B中，
				//先出栈的集合(此处是x1先出)，加入到后出栈(x2)的集合，将结果压栈
				sk.push(ID(ans));
			}
			cout << setcache[sk.top()].size() << endl;
		}
		cout << "***" << endl;
	}
	return 0;
}  
