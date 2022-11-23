#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

   int t;
   for(cin >> t; t--;){
       int n, m; cin >> n >> m;
       ll ans = 0;
        int a[n+1]; map<ll,ll>mp;
        for(int i = 0; i < n; i++){cin >> a[i];}

        ll sum = 0; mp[0]++;
        for(int i = 0; i < n; i++){
            sum+=a[i];
            if(mp[sum%m])ans += mp[sum%m];
            mp[sum%m]++;
        }

        cout << ans << endl;
   }

}




