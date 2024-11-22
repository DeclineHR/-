#include<iostream>
#include<sstream>
#include<set>
#include<string>
using namespace std;
set<string> dirctory;
int main() {
	string s, buf;
	while (cin >> s) {
		for (int i = 0; i < s.size(); i++)//s.size() 和s.length()结果一样
			if (isalpha(s[i])) s[i] = tolower(s[i]); else s[i] = ' ';
		//isalpha()检查字符串 s 中的每个字符，如果字符是字母，返回ture否则返回false
		//tolower()判断字母是否为大写,是则返回其小写,否则返回其自身;
		//else 如果字符不是字母，则将其替换为空格

			stringstream abc (s);
			//这行代码的作用是创建一个 stringstream 对象，
			//它允许您对字符串 s 进行流式操作，
			//即将字符串 s 当作一个流来处理，从中读取或写入数据
			
			while (abc >> buf)dirctory.insert(buf);//接受string流中的全部单词
			//从当前位置开始，stringstream 读取字符，直到遇到一个空白字符
			//插入到名为dirctory的set容器中 实现去重 排序;
	}
	//for (set<string>::iterator it = dirctory.begin(); it != dirctory.end(); it++) {
	//	cout << *it << endl;
	//}
	for (const auto& b : dirctory) {
		cout << b << endl;
	}//使用auto更加简便 注意 const 和 &

	return 0;
}
