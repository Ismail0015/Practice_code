#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
ll big_mod(ll x, ll y){
  ll res = 1;
  while(y){
    if(y&1)res = (res*x)%mod;
    x = (x*x)%mod;
    y /= 2LL;
  }
  return res;
}
using namespace std;
int main()
{
    ll n;
    cin >> n;
    map<ll, ll>mp;
    ll ans = 0;
    while(n--){
        ll m;cin >> m;
        mp[m]++;
    }
    for(auto x : mp){
        ans += big_mod(2LL,x.second)-1LL;
        ans %= mod;
    }cout << ans;
}
