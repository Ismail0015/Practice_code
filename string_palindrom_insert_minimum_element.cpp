#include<bits/stdc++.h>
using namespace std;
int main(){

   string s, t; cin >> s;
   t = s;
   reverse(s.begin(), s.end());
   int n = t.size();
   int dp[n+1][n+1];
   for(int i = 0; i <= n; i++){
    for(int j = 0; j <= n; j++)if(i==0 or j == 0)dp[i][j] = 0;
   }

   for(int i = 1; i <= n; i++){
     for(int j = 1; j <= n; j++){
        if(t[i-1] == s[j-1]){
            dp[i][j] = 1+ dp[i-1][j-1];
        }
        else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
     }
   }
   cout << n-dp[n][n];
}
