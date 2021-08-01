#include <bits/stdc++.h>
using namespace std;
const int MAXN=10e5+10;
int sum[MAXN];

int main() {
    ios::sync_with_stdio(false);
    set<int> s;
    int n, a, ans;
    cin>>n;
    sum[0]= ans = 0;
    for (int i=0;i<n;i++) {
        cin>>a;
        sum[i+1]=a+sum[i];
        s.insert(sum[i+1]);
    }
    int len = sum[n]/3;
    if (sum[n]%3==0) {
        for (int i=1;i<=n;i++) {
            if (s.find(len+sum[i])!=s.end()&&s.find(2*len+sum[i])!=s.end())
                ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}