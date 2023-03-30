#include <bits/stdc++.h>
using namespace std;
class String
{
public:
    String(const char *str = nullptr);
    String(const String &str);
    ~String();

    String &operator+=(const String &str);
    char &operator[](int n) const;
    bool operator==(const String &str) const;
    int size() const;
    String &operator=(const String &str);
    const char *c_str() const;
    friend ostream &operator<<(ostream &os, const String &str);
    String operator+(const String &str) const;

private:
    char *data;
    int len;
};
bool String::operator==(const String &str) const
{
    if (len != str.size())
    {
        return false;
    }
    return strcmp(str.c_str(), data) ? false : true;
}
char &String::operator[](int n) const
{
    if (n >= len)
    {
        return data[len - 1];
    }
    return data[n];
}
String &String::operator+=(const String &str)
{
    len += str.size();
    char *newdata = new char[len + 1];
    strcpy(newdata, data);
    strcat(newdata, str.c_str());
    delete[] data;
    data = newdata;
    return *this;
}
String::String(const String &str)
{
    len = str.size();
    data = new char[len + 1];
    strcpy(data, str.data);
}
String::~String()
{
    delete[] data;
    len = 0;
}
String String::operator+(const String &str) const
{
    String newString;
    newString.len = str.len + len;
    newString.data = new char(newString.len + 1);
    strcpy(newString.data, data);
    strcat(newString.data, str.data);
    return newString;
}
ostream &operator<<(ostream &os, const String &str)
{
    os << str.data;
    return os;
}
String::String(const char *str)
{
    if (str == nullptr)
    {
        len = 0;
        data = new char[1];
        *data = '\0';
    }
    else
    {
        len = strlen(str);
        data = new char[len + 1];
        strcpy(data, str);
    }
}
int String::size() const
{
    return len;
}
const char *String::c_str() const
{
    return data;
}
String &String::operator=(const String &str)
{
    if (this == &str)
    {
        return *this;
    }
    delete[] data;
    len = str.size();
    data = new char[len + 1];
    strcpy(data, str.c_str());
    return *this;
}
int main()
{
    String s = "0";
    s += "123";
    String b = "0123";
    String d = b + s + b;
    cout << d << endl;
    if (s == b)
    {
        cout << "333" << endl;
    }
    cout << s << b << endl;
    cout << s.size() << endl;
    cout << s << endl;
    cout << s[6] << endl;
    return 0;
}
