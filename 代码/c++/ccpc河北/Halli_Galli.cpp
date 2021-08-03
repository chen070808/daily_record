#include <bits/stdc++.h>
using namespace std;
int T;
const int MAXN = 110;
const int MAXK = 7;
typedef struct Halli_Galli
{
    char card;
    int num;
} peo;

int fn[4];
char c;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        memset(fn, 0, sizeof(fn));
        int N, K, i = 0, ans = 0;
        cin >> N >> K;
        peo p[K];
        char ch, nu;
        while (N--)
        {
            cin >> c >> n;
            if (i >= K)
            {
                ch = p[(i - K) % K].card;
                nu = p[(i - K) % K].num;
                if (ch == 'A')
                    fn[0] -= nu;
                else if (ch == 'B')
                    fn[1] -= nu;
                else if (ch == 'G')
                    fn[2] -= nu;
                else if (ch == 'P')
                    fn[3] -= nu;
            }
            p[i % K].card = c;
            p[i % K].num = n;
            if (c == 'A')
                fn[0] += n;
            else if (c == 'B')
                fn[1] += n;
            else if (c == 'G')
                fn[2] += n;
            else if (c == 'P')
                fn[3] += n;
            for (int j = 0; j < 4; j++)
            {
                if (fn[j] == 5)
                    ans++;
            }
            i++;
        }
        cout << ans << endl;
    }

    return 0;
}