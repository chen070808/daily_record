#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1000010;
int father[MAXN];

int dfs(int num)
{
    queue<int> q;
    int u;
    q.push(num);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        if (u == 1)
            return 1;
        else if (u >= 0 && u < MAXN && !father[u])
        {
            father[u] = 1;
            if ((u - 13) % 5 == 0)
            {
                q.push((u - 13) / 5);
            }
            if ((u - 5) % 13 == 0)
            {
                q.push((u - 5) / 13);
            }
            if ((u + 13) % 5 == 0)
            {
                q.push((u + 13) / 5);
            }
            if ((u + 5) % 13 == 0)
            {
                q.push((u + 5) / 13);
            }
        }
    }
    return 0;
}
int T;
int main()
{
    cin >> T;
    while (T--)
    {
        memset(father, 0, sizeof(father));
        int n;
        cin >> n;
        if (dfs(n))
            cout << "Yes\n";
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}