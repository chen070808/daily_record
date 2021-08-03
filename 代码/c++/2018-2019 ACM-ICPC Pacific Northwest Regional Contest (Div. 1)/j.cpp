#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, s, t;
    int maxn = 0;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        maxn = max(maxn, t);
    }
    cout << ceil(maxn * s / 1000.0) << endl;
    return 0;
}
