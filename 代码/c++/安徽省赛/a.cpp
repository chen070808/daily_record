#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll al, bl, bn;
int na, nb;
int a[11], b[11];
int v[11];
int ans[10000000];
int ax = 0;
void dfs(int u, ll num, int f)
{
    v[u] = 1;
    num *= 10;
    num += a[u];
    if (num > bn)
        return;
    if (!f)
    {
        ans[ax] = num;
        ax++;
        return;
    }
    for (int i = na - 1; i >= 0; i--)
    {
        if (!v[i])
        {
            dfs(i, num, f - 1);
            v[i] = 0;
        }
    }
    v[u] = 0;
}

bool cmp(ll a, ll b)
{

    return a > b;
}

int main()
{
    cin >> al >> bl;
    bn = bl;
    while (al && bl)
    {
        a[na] = al % 10;
        b[nb] = bl % 10;
        al /= 10;
        bl /= 10;
        na++;
        nb++;
    }
    // int flag = 0;
    //string str = "";
    if (al > bl)
    {
        cout << "-1";
        return 0;
    }
    else
    {
        sort(a, a + na);
        if (bl > al)
        {
            for (int i = na - 1; i >= 0; i--)
                cout << a[i];
        }
        else
        {
            // for (int i = nb - 1; i >= 0; i--)
            // {
            //     for (int j = na - 1; j >= 0; j--)
            //     {
            //         if (flag && !v[j])
            //         {
            //             cout << a[j];
            //             v[j] = 1;
            //             break;
            //         }
            //         if (a[j] == b[i] && !v[j])
            //         {
            //             cout << a[j];
            //             v[j] = 1;
            //             break;
            //         }
            //         if (a[j] < b[i] && !v[j])
            //         {
            //             cout << a[j];
            //             flag = 1;
            //             v[j] = 1;
            //             break;
            //         }
            //     }
            // }
            for (int i = na - 1; i >= 0; i--)
                dfs(i, 0, na - 1);
            if (ax == 0)
            {
                cout << "-1";
                return 0;
            }
            sort(ans, ans + ax, cmp);
            for (int i = 0; i < ax; i++)
            {
                if (ans[i] <= bn)
                {
                    cout << ans[i];
                    break;
                }
            }
        }
    }
    return 0;
}