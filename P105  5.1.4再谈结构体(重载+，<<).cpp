//实现坐标的相加
#include<iostream>
using namespace std;
struct Point {
    int x, y;
    Point(int x = 0, int y = 0) {
        this->x = x;// this->x是传入的参数   x是成员变量
        this->y = y;
    }
};
Point operator +(const Point& A, const Point& B) {//重载＋号运算符 使编译器明白如何相加 结构体Point
    return Point((A.x) + (B.x), (A.y) + (B.y));
}
ostream& operator << (ostream& out, const Point& p) {//重载了<<运算符，使其能够将Point对象的信息输出到输出流
    out << "(" << p.x << "," << p.y << ")";//输出Point对象的坐标，格式为(x,y)
    return out;
}
//+运算符重载不需要&，因为它通常处理的是值的加法，而<<运算符重载需要&，因为它需要修改输出流的状态并支持链式调用5
int main() {
    Point a,b(1,2);//声明了两个Point对象a和b。
  //a使用默认构造函数，其坐标为(0,0)。b使用带参数的构造函数，其坐标为(1,2)。
    a.x = 3;//设定a(3,0)
    cout << a + b << endl;
    return 0;
}
