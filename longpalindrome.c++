#include <iostream>
using namespace std;
// abcdedcba
int main()
{
    string s = "a";
    int lon = 0;
    int longest = 0;
    int pre, p;
    int next, n;
    for (int i = 0; i < s.length(); i++)
    {
        n = i + 1;
        p = i;
        while (p >= 0 && n < s.length() && s[n] == s[p])
        {
            n++;
            p--;
        }
        n--;
        p++;
        lon = n - p;
        if (lon > longest)
        {
            longest = lon;
            next = n;
            pre = p;
        }
        n = i;
        p = i;
        while (p >= 0 && n < s.length() && s[n] == s[p])
        {
            n++;
            p--;
        }
        n--;
        p++;
        lon = n - p;
        if (lon > longest)
        {
            longest = lon;
            next = n;
            pre = p;
        }
    }
    // cout<<longest;
    for (int w = pre; w <= next; w++)
    {
        cout << s[w];
    }
}