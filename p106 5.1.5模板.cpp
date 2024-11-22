#include<iostream>
using namespace std;
template<typename T>
struct Point {
    T x, y;
    Point(T x = 0, T y = 0) {
        this->x = x;
        this->y = y;
    }
};
template<typename T>
Point<T> operator +(const Point<T>& A, const Point<T>& B) {
    return Point<T>((A.x) + (B.x), (A.y) + (B.y));
}
template<typename T>
ostream& operator << (ostream& out, const Point<T>& p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}
template<typename T>
T sum(T *begin, T *end) {//数组累加
    T ans = 0;
    for (T* p = begin; p != end; p++)ans = ans + *p;
    return ans;
}
int main() {
    Point<int> a(2,3), b(1, 2);//实现Point里的 整形 浮点数 自定义类型的加法
    Point<double> c(2.2,3.3), d(1.1, 2.2);
    Point<int> m[] = { Point<int>(1,2),Point<int>(2,3),Point<int>(3,4),Point<int>(4,5) };
    cout << a + b << endl;
    cout << c + d << endl;
    cout << sum(m,m + 4) << endl;
    return 0;
}
