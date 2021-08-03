#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 1; i < 10; i++)
    {
        cout << (((a * b * i )+9)/ 10) << " ";
    }
    cout << endl;
return 0;
}