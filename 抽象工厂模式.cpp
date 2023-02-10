#include <bits/stdc++.h>
using namespace std;
class AbstactApple
{
public:
    virtual void ShowName() = 0;
};
class ChinaApple : public AbstactApple
{
public:
    virtual void ShowName()
    {
        cout << "I'm China apple" << endl;
    }
};
class USAApple : public AbstactApple
{
public:
    virtual void ShowName()
    {
        cout << "I'm USA apple" << endl;
    }
};
class AbstactBanana
{
public:
    virtual void ShowName() = 0;
};
class ChinaBanana : public AbstactBanana
{
public:
    virtual void ShowName()
    {
        cout << "I'm China Banana" << endl;
    }
};
class USABanana : public AbstactBanana
{
public:
    virtual void ShowName()
    {
        cout << "I'm USA Banana" << endl;
    }
};
class AbstactFactory
{
public:
    virtual AbstactApple *CreateApple() = 0;
    virtual AbstactBanana *CreateBanana() = 0;
};
class ChinaFactory : public AbstactFactory
{
public:
    virtual AbstactApple *CreateApple()
    {
        return new ChinaApple;
    }
    virtual AbstactBanana *CreateBanana()
    {
        return new ChinaBanana;
    }
};
class USAFactory : public AbstactFactory
{
public:
    virtual AbstactApple *CreateApple()
    {
        return new USAApple;
    }
    virtual AbstactBanana *CreateBanana()
    {
        return new USABanana;
    }
};
void test()
{
    AbstactFactory *factory = new ChinaFactory;
    AbstactApple *apple = factory->CreateApple();
    apple->ShowName();
    delete apple;
    delete factory;
    apple = nullptr;
    factory = nullptr;
}
int main()
{
    test();
    return 0;
}