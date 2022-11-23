#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
   ll n, m; cin >> n;
   map<ll, ll>mp; ll sum = 0, ans = 0; mp[0]++;
   for(ll i = 0; i < n; i++){
       ll a; cin >> a; a%=n;
       sum+=a;sum+=n; sum%=n;
      if(mp[sum%n])ans += mp[sum%n];
       mp[sum%n]++;
   }cout << ans;
}
