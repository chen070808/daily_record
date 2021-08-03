#include <bits/stdc++.h>
using namespace std;

double x, y;

double d(double x1, double y1, double x2, double y2)
{
    double cross = (x2 - x1) * (x - x1) + (y2 - y1) * (y - y1);
    if (cross <= 0)
        return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));

    double d2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    if (cross >= d2)
        return sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));

    double r = cross / d2;
    double px = x1 + (x2 - x1) * r;
    double py = y1 + (y2 - y1) * r;
    return sqrt((x - px) * (x - px) + (y - py) * (y - py));
}

int main()
{
    ios::sync_with_stdio(false);
    double x1, x2, y1, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    double ans = 1e30;
    ans = min(ans, d(x1, y1, x2, y1));
    ans = min(ans, d(x1, y1, x1, y2));
    ans = min(ans, d(x1, y2, x2, y2));
    ans = min(ans, d(x2, y1, x2, y2));
    printf("%.3f", ans);
    return 0;
}