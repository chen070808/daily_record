#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int a[N], n, x, ans = 1;

int main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 1, r = 1;
    while (r <= n)
    {
        while (a[r + 1] - a[r] <= x && r < n)
            r++;
        ans = max(ans, r - l + 1);
        l = r = r + 1;
    }
    cout << ans << endl;
}