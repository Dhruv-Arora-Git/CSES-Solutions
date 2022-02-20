#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int maxi = -1, len = 1;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == s[i + 1])
        {
            len++;
        }
        else
        {
            maxi = max(maxi, len);
            len = 1;
        }
    }
    cout << maxi << '\n';

    return 0;
}