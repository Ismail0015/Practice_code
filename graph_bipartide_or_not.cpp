#include<bits/stdc++.h>
using namespace std;
vector<int>v[2001];
int vis[2001], c, col[2001];
bool dfs(int node, int c){
    vis[node] = 1;
    col[node] = c;
    for(auto child : v[node]){
        if(!vis[child]){
            if(dfs(child, c^1) == false)return false;
        }
        else {
            if(col[child] == col[node])return false;
        }
    }
    return true;

}
int main(){
    int t;cin >>t;
    for(int j = 1; j <= t; j++){
        int n, m;
        cin >> n >> m;

         for(int i = 1; i<= n; i++)v[i].clear();

        for(int i = 1; i <= m; i++){
            int a, b;
            cin >> a>> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        for(int i = 1; i<= n; i++)vis[i] = 0;

        cout << "Scenario #" << j << ':' << endl;
        bool f = true;
        for(int i = 1; i<= n; i++){
            if(!vis[i]){
                if(dfs(i, 0) == false)f = false;
            }
        }
        if(!f){
            cout << "Suspicious bugs found!" <<endl;
        }
        else cout << "No suspicious bugs found!" << endl;

    }

}
