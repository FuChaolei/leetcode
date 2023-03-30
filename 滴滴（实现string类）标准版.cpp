#include <iostream>
#include <cstring>
using namespace std;

class String
{
public:
    String(const char *str = NULL); // 通用构造函数,String("abc")
    String(const String &str);      // 拷贝构造
    ~String();

    String &operator=(const String &str); // 赋值运算符。返回引用
    String operator+(const String &str) const;
    String &operator+=(const String &str); //+=操作符。返回引用
    char &operator[](int n) const;         // 下标操作符。返回引用
    bool operator==(const String &str) const;

    int size() const;          // 字符串实际大小，不包括结束符
    const char *c_str() const; // 将string转为char *
    friend ostream &operator<<(ostream &os, const String &str);

private:
    char *data;
    int length;
};

String::String(const char *str) // 通用构造
{
    if (!str)
    { // 为空。String a()
        length = 0;
        data = new char[1];
        *data = '\0';
    }
    else
    {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str); // 会拷贝源的结束符
    }
}

String::String(const String &str) // 拷贝构造，深拷贝
{
    length = str.size();
    data = new char[length + 1];
    strcpy(data, str.c_str());
}

String::~String()
{
    delete[] data;
    length = 0;
}

String &String::operator=(const String &str) // 赋值操作符4步
{
    if (this == &str)
        return *this; // 1 自我赋值，返回自身引用

    delete[] data; // 2 删除原有数据

    length = str.size(); // 3 深拷贝
    data = new char[length + 1];
    strcpy(data, str.c_str());

    return *this; // 4 返回自身引用
}
String String::operator+(const String &str) const //+操作符3步
{                                                 // 新建对象包括新空间，拷贝两个数据，返回新空间
    String newString;
    newString.length = length + str.size();
    newString.data = new char[newString.length + 1];
    strcpy(newString.data, data);
    strcat(newString.data, str.data);
    return newString;
}

String &String::operator+=(const String &str) //+=操作符5步
{                                             // 重分配新空间，拷贝两个数据，删除自己原空间，赋值为新空间，返回引用
    length += str.size();                     // 成员length是实际长度
    char *newdata = new char[length + 1];
    strcpy(newdata, data);
    strcat(newdata, str.c_str());
    delete[] data;
    data = newdata;
    return *this;
}

char &String::operator[](int n) const
{ // 下标操作符，返回引用
    if (n >= length)
        return data[length - 1]; // 如果越界，返回最后一个字符
    else
        return data[n];
}

bool String::operator==(const String &str) const
{
    if (length != str.size())
        return false;
    return strcmp(data, str.c_str()) ? false : true;
}

int String::size() const
{
    return length;
}

const char *String::c_str() const
{
    return data;
}
ostream &operator<<(ostream &os, const String &str)
{
    os << str.data;
    return os;
}
int main()
{
    string s;
    char a[] = "Hello", b[] = "World!";
    String s1(a), s2(b);
    cout << s1.c_str() << endl;
    cout << s2.c_str() << endl;
    s1 += s2;
    cout << s1.c_str() << endl;
    s1 = s2;
    cout << s1.c_str() << endl;
    cout << (s1 + s2).c_str() << endl;
    cout << s1.size() << endl;
    cout << s1[1] << endl;
    cout << s1 << endl;

    if (s1 == s2)
        cout << "相等" << endl;
}
// 另一个版本:https://www.cnblogs.com/alantu2018/p/8471060.html