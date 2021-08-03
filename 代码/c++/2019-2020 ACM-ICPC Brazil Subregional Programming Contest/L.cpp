#include <iostream>
using namespace std;
typedef long long ll;

ll sor(ll n)
{
    if (n <= 1)
        return n + 1;
    else
        return sor(n / 2) << n % 2;
}

int main()
{
    ll n;
    cin >> n;
    cout << sor(n) << endl;
    return 0;
}