#include <bits/stdc++.h>
using namespace std;
class Lazy
{
public:
    static Lazy *getInstance()
    {
        if (a == nullptr)
        {
            a = new Lazy;
            cout << "success" << endl;
        }
        return a;
    }

private:
    Lazy() {}
    static Lazy *a;
};
Lazy *Lazy::a = nullptr;
int main()
{
    Lazy *tmp = Lazy::getInstance();
    Lazy *tmp2 = Lazy::getInstance();
    if (tmp == tmp2)
    {
        cout << "equal" << endl;
        cout << tmp << endl;
        cout << tmp2 << endl;
    }
    // delete tmp2;
    // tmp2 = nullptr;
    // delete tmp;
    // tmp = nullptr;
    return 0;
}