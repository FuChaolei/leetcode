#include <bits/stdc++.h>
using namespace std;
// 字符串处理，是字母重复一次，数字重复两次，其他字符删除

// 例如：输入，abc.1*2-3

// 输出，aabbcc111222333
class Solution
{
public:
    string get_s(string s)
    {
        if (s == "")
        {
            return s;
        }
        int n = s.size();
        int l = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                l += 3;
            }
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                l += 2;
            }
        }
        if (l == 0)
        {
            return "";
        }
        if (l > n)
        {
            s.resize(l, '*');
        }
        int tmp = l - 1;
        int flag = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                s[tmp--] = s[i];
                s[tmp--] = s[i];
                s[tmp--] = s[i];
                flag = i;
            }
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                s[tmp--] = s[i];
                s[tmp--] = s[i];
                flag = i;
            }
        }
        return s.substr(flag, l - flag);
    }
};
int main()
{
    string s = "abc.1*2-3";
    Solution obj;
    string res = obj.get_s(s);
    cout << res;
    return 0;
}
