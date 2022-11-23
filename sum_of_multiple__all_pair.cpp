#include <bits/stdc++.h>
#define int long long int
#define mod 1000000007
using namespace std;


int32_t main()
{

     int n; cin >> n;
     int a[n+1];
    for(int i = 0; i < n; i++)cin >> a[i];
    int ans = 0,sum = 0;

    for (int i = 0; i < n; i++) {
        ans += (sum * a[i]) % mod;
        ans %= mod;
        sum += a[i];
        sum %= mod;
    }
  cout << ans;
}


