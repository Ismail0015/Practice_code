#include<bits/stdc++.h>
#define int long long int
#define mod 1000000007
using namespace std;
const int mx = 200005;
vector<int>v[mx]; int vis[mx],node,dis[mx], c;
void dfs(int x){
   vis[x] = 1; c++;
  if(!vis[x]) dis[x] = c;
   for(auto i:v[x]){
     if(!vis[i]){
        dis[i] += dis[x]+1;
        dfs(i);
     }
   }
}
int32_t main(){
       int n; cin >> n;
       for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
         v[a].push_back(b);
         v[b].push_back(a);
       }
       dfs(1);

       int m = 0, mi = 0, nm;
       for(int i = 1; i <= n; i++){
          if(m < dis[i])m= dis[i], node = i;
       }
       for(int i = 1; i <= n; i++){
          dis[i] = 0, vis[i] = 0;
       }

      dfs(node);

      m = 0;
      for(int i = 1; i <= n; i++){
          if(m < dis[i])m= dis[i], node = i;
       }
       int d[n];
       for(int i = 1; i <= n; i++){
         d[i] = dis[i], dis[i] = 0, vis[i] = 0;
       }

      dfs(node);


      for(int i = 1; i <= n; i++){
        cout << max(d[i], dis[i]) << " ";
      }


}



