#include <bits/stdc++.h>
using namespace std;
class A
{
public:
    static A *getInstance()
    {
        return a;
    }
private:
    A()
    {
        a = new A;
    }
    static A *a;
};
A *A::a = nullptr;
int main()
{
    A *tmp = A::getInstance();
    return 0;
}
// 实现单例步骤
// 1.构造函数私有化
// 2.增加静态私有的当前类的指针变量
// 3.提供静态对外接口，可以让用户获得单例对象