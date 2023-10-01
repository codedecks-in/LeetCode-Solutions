#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string &s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (s[l++] != s[r--])
            return false;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    isPalindrome(s) ? cout << "Yes" : cout << "No";

    return 0;
}