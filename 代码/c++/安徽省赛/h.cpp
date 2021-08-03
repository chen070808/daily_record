#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ch[30];
    int hh1[30], mm1[30], ss1[30], tt1[30];
    int hh2[30], mm2[30], ss2[30], tt2[30];
    int n = 0;
    string str[30];
    while (cin >> ch[n])
    {
        if (ch[n] == '#')
            break;
        scanf("%d:%d:%d,%d --> %d:%d:%d,%d\n", &hh1[n], &mm1[n], &ss1[n], &tt1[n], &hh2[n], &mm2[n], &ss2[n], &tt2[n]);
        getline(cin, str[n]);
        n++;
    }
    int chan;
    cin >> chan;
    int chh = 0, cm = 0, cs = 0, ct = 0;
    ct = chan % 1000;
    chan /= 1000;
    cs = chan % 60;
    chan /= 60;
    cm = chan % 60;
    chan /= 60;
    chh = chan % 60;
    chan /= 60;
    for (int i = 0; i < n; i++)
    {
        cout << ch[i] << "\n";
        int th1 = 0, tm1 = 0, ts1 = 0;
        int th2 = 0, tm2 = 0, ts2 = 0;
        if (tt1[i] + ct >= 1000)
        {
            ts1 = 1;
            tt1[i] -= 1000;
        }
        if (tt1[i] + ct < 0)
        {
            ts1 = -1;
            tt1[i] += 1000;
        }

        if (tt2[i] + ct >= 1000)
        {
            ts2 = 1;
            tt2[i] -= 1000;
        }
        if (tt2[i] + ct < 0)
        {
            ts2 = -1;
            tt2[i] += 1000;
        }

        if (ss1[i] + cs + ts1 >= 60)
        {
            tm1 = 1;
            ss1[i] -= 60;
        }
        if (ss1[i] + cs + ts1 < 0)
        {
            tm1 = -1;
            ss1[i] += 60;
        }

        if (ss2[i] + cs + ts2 >= 60)
        {
            tm2 = 1;
            ss2[i] -= 60;
        }
        if (ss2[i] + cs + ts2 < 0)
        {
            tm2 = -1;
            ss2[i] += 60;
        }

        if (mm1[i] + cm + tm1 >= 60)
        {
            th1 = 1;
            mm1[i] -= 60;
        }
        if (mm1[i] + cm + tm1 < 0)
        {
            th1 = -1;
            mm1[i] += 60;
        }

        if (mm2[i] + cm + tm2 >= 60)
        {
            th2 = 1;
            mm2[i] -= 60;
        }
        if (mm2[i] + cm + tm2 < 0)
        {
            th2 = -1;
            mm2[i] += 60;
        }

        if (hh1[i] + chh + th1 >= 60)
        {
            hh1[i] -= 60;
        }
        if (hh1[i] + chh + th1 < 0)
        {
            hh1[i] += 60;
        }

        if (hh2[i] + chh + th2 >= 60)
        {
            hh2[i] -= 60;
        }
        if (hh2[i] + chh + th2 < 0)
        {
            hh2[i] += 60;
        }
        printf("%02d:%02d:%02d,%03d --> %02d:%02d:%02d,%03d\n", hh1[i] + chh + th1, mm1[i] + cm + tm1, ss1[i] + cs + ts1, tt1[i] + ct, hh2[i] + chh + th2, mm2[i] + cm + tm2, ss2[i] + cs + ts2, tt2[i] + ct);
        cout << str[i] << "\n";
    }
    cout << "#" << endl;
    return 0;
}