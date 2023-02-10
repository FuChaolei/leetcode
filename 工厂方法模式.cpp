#include <bits/stdc++.h>
using namespace std;
class AbstractFruit
{
public:
    virtual void ShowName() = 0;
};
class Apple : public AbstractFruit
{
public:
    virtual void ShowName()
    {
        cout << "I'm apple!" << endl;
    }
};
class Banana : public AbstractFruit
{
public:
    virtual void ShowName()
    {
        cout << "I'm banana!" << endl;
    }
};
class AbstractFactory
{
public:
    virtual AbstractFruit *Createfruit() = 0;
};
class AppleFactory : public AbstractFactory
{
public:
    virtual AbstractFruit *Createfruit()
    {
        return new Apple;
    }
};
class BananaFactory : public AbstractFactory
{
public:
    virtual AbstractFruit *Createfruit()
    {
        return new Banana;
    }
};
void test()
{
    AbstractFactory *factory = new AppleFactory;
    AbstractFruit *fruit = factory->Createfruit();
    fruit->ShowName();
    delete fruit;
    delete factory;
    fruit = nullptr;
    factory = nullptr;
}
int main()
{
    test();
    return 0;
}
