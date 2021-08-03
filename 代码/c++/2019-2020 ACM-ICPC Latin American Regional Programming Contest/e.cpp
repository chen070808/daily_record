#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
string str = "";
long long ans, s;

int main()
{
    cin >> str;
    cin >> s;
    int l = 0, r = 0;
    int c = 0;
    int n = str.length() - 1;
    while (l < n)
    {
        while (r < l + n - 1 && (!c))
        {
            if (str[r + 1] == 'E')
                c = 1;
            r++;
        }
        ans += max(l + n - r+1, 0);
        if (str[l] == 'E')
            c = 0;
        l++;
    }
    cout << ans << endl;
    return 0;
}