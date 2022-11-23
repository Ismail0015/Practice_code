 #include<bits/stdc++.h>
using namespace std;
int vis[100005];
vector<int>v[100005];
bool dfs(int node){
   vis[node] = 1;
   for(auto x : v[node]){
    if(vis[x] == 0){
        if(dfs(x) == true)return true;
    }
    else
    if(vis[x] == 1)return true;
   }
   vis[node] = 2;
   return false;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        //v[b].push_back(a);
    }

    cout << "This is cycle ? --> " << dfs(1);
}

