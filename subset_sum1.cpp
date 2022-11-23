#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int ans = 0;
bool fun(int a[], int n, int m){
     bool dp[m];
     memset(dp, false, m);
     for(int i = 0; i < n; i++){
        if(dp[0])return true;
        bool tmp[m];
     memset(tmp, false, m);
     for(int j = 0; j < m; j++){
         if(dp[j]){
            if(!dp[(j+a[i])%m]){
                tmp[(j+a[i])%m] = true;
            }
         }
     }

     for(int ii = 0; ii < m; ii++){
        if(tmp[ii])dp[ii] = true;
     }
     dp[a[i]%m] = true;
  }
  return dp[0];
}
int main()
{
    int n, m; cin >> n >> m;
    int a[n+1];
    for(int i = 0; i < n; i++){cin >> a[i]; if(!a[i])ans= 1;
    }
    if(ans or n >= m)cout << "YES" ;
    else {

    fun(a,n,m)?cout << "YES":cout << "NO";}

}

