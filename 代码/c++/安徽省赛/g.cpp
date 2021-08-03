#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10e6 + 10;
int n1, m, top = 0;
int t[MAXN];
int a[MAXN];

void dele(int u)
{
    for (int i = u; i < top; i++)
    {
        a[i] = a[i + 1];
    }
    top--;
}

int main()
{
    cin >> n1 >> m;
    memset(a, -1, sizeof(a));
    for (int i = 0; i < m; i++)
    {
        cin >> t[i];
    }
    sort(t, t + m);
    int n;
    for (int i = 0; i < n1; i++)
    {
        cin >> n;
        int tmp = 0;
        if (n == -1)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (t[j] <= top)
                {
                    a[t[i]] = -1;
                    tmp++;
                }
            }
        }
        else if (n == 0)
        {
            a[top++] = 0;
        }
        else if (n == 1)
        {
            a[top++] = 1;
        }
        }
    if (top == 0)
        cout << "Poor stack!";
    else
    {
        for (int i = 0; i < top; i++)
        {
            cout << a[i];
        }
    }

    return 0;
}