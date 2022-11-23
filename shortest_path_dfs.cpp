#include<bits/stdc++.h>
using namespace std;
int vis[200005], from[200005], n, m;
vector<int>v[200005], ans, ans1;
void dfs(int p){
  queue<int>q;
  q.push(1);
  while(!q.empty()){
        p = q.front();
  q.pop();
  if(p == n)break;
  for(auto x : v[p]){
    if(!vis[x]){
        vis[x] = 1;
        from[x] = p;
       q.push(x);
    }
  }
  }
}
int main(){


    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

  dfs(1);
  if(vis[n] == 1){
     ans.push_back(n);
     int a = n;
     while(a != 1){
        a = from[a];
        ans.push_back(a);
     }
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for(auto x : ans)cout << x << " ";
  }
  else cout << "IMPOSSIBLE";

}
