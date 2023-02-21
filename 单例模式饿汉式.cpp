#include <bits/stdc++.h>
using namespace std;
class Hungry
{
public:
    static Hungry *getInstance()
    {
        return a;
    }

private:
    Hungry() {}
    static Hungry *a;
};
Hungry *Hungry::a = new Hungry;
int main()
{
    Hungry *tmp = Hungry::getInstance();
    Hungry *tmp2 = Hungry::getInstance();
    if (tmp == tmp2)
    {
        cout << "equal" << endl;
        cout << tmp << endl;
        cout << tmp2 << endl;
    }
    return 0;
}