#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll vis[50000], k; ll dp[54444][501], ans;
vector<ll>v[50000], vec;
void dfs(ll node, ll par){
    dp[node][0] = 1;

   for(auto child : v[node]){
       if( child != par){
          dfs(child, node);

          for(ll i = 0; i  < k; i++){
            ans += (dp[node][i] * dp[child][k-i]);
            dp[node][i] += dp[child][i];
          }
       }
   }
   for(ll i = k; i >= 0; i--)dp[node][i] = dp[node][i-1];
   dp[node][0] = 0;

}
int main(){

     int n;
     cin >> n >> k;
     for(int i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
     }
    dfs(1, 0);
   cout << ans;
}


