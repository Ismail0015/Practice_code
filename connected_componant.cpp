#include<bits/stdc++.h>
using namespace std;
vector<int>v[100005];
int vis[100005];
void dfs(int node){
   vis[node] = 1;
   for(auto x : v[node]){
    if(!vis[x]){
        vis[x]  =1;
        dfs(x);
    }
   }

}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt = 0;

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            cnt++;
        }
    }cout <<cnt;
}
