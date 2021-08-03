#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll al, bl;
int na, nb;
int a[11], b[11];
int v[11];

ll num(int num1, int num2)
{
}

int main()
{
    cin >> al >> bl;

    while (al && bl)
    {
        a[na] = al % 10;
        b[nb] = bl % 10;
        al /= 10;
        bl /= 10;
        na++;
        nb++;
    }
    int flag = 0;
    string str = "";
    if (al > bl)
    {
        cout << "-1" << endl;
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
            for (int i = nb - 1; i >= 0; i--)
            {
                for (int j = na - 1; j >= 0; j--)
                {
                    if (flag && !v[j])
                    {
                        cout << a[j];
                        v[j] = 1;
                        break;
                    }
                    if (a[j] == b[i] && !v[j])
                    {
                        cout << a[j];
                        v[j] = 1;
                        break;
                    }
                    if (a[j] < b[i] && !v[j])
                    {
                        cout << a[j];
                        flag = 1;
                        v[j] = 1;
                        break;
                    }
                }
            }
    }
    cout << endl;
    return 0;
}