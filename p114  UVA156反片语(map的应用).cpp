https://www.luogu.com.cn/problem/UVA156
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
	map<string, int>mp;//map<键，值> 因此 这里 string是键 而int是关联的值
	vector<string>v;
string setting(const string& s) {
	string s2 = s;
	for (int i = 0; i < s.size(); i++) {
		s2[i] = tolower(s2[i]);//通过tolower() 把单词小写化
	}
	sort(s2.begin(), s2.end());
	return s2;
}
//通过函数把单词标准化 用s保存
//输入字符串后，把字符全部转成小写，然后排序，
//这样符合条件的字符串(比如zyx和XYZ)就会得到同样的串了。
int main() {
	string s;
	while (cin >> s) {
		if (s[0] == '#') break;//遇到#则退出循环
		v.push_back(s);//将原始的单词存入v中，然后通过setting来判断是否重复 
		string r = setting(s);
		if (!mp.count(r))mp[r] = 0;//如果这个r单词(key)还没有出现过，就把其对应的值设置为0
		mp[r]++;//然后string（键）对应的数值+1
		//map 提供了 [] 操作符，它可以用来插入新元素或修改现有元素的值
		//例如myMap["five"] = 1; 这将插入一个新的键值对 {"five", 5}。{键，值}
		//setting("ladder") -> "addler"
		//mp["addler"] = 0
		//mp["addler"]++  ->   mp["addler"] = 1
	}
	vector<string>answer;
	for (int i = 0; i < v.size(); i++)
		if (mp[setting(v[i])] == 1) answer.push_back(v[i]);//保存所有数值为1的字符串(单词)到answer数组
	sort(answer.begin(), answer.end());//排序
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
	return 0;
}
