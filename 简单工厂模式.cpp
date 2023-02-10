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
class Factory
{
public:
    static AbstractFruit *Createfruit(string s)
    {
        if (s == "apple")
        {
            return new Apple;
        }
        else if (s == "banana")
        {
            return new Banana;
        }
        else
        {
            return nullptr;
        }
    }
};
void test()
{
    Factory *factory = new Factory;
    AbstractFruit *fruit = factory->Createfruit("apple");
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
