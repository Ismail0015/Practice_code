#include<bits/stdc++.h>
#define sz 100005
using namespace std;
vector<int>v[sz];
int vis[sz], dis[sz], mi;
void bfs(int x)
{
    queue<int>q;
    q.push(x);
    vis[x] = 1;
    dis[x] = 0;

    while(!q.empty()){
            int p = q.front();
            q.pop();
    for(auto i : v[p])
    {
        if(!vis[i])
        {
            q.push(i);

            dis[i] = (dis[p] + 1);
            vis[i] = 1;

        }
    }
    }
}

int main()
{
    int t;
    for(cin >> t; t--;)
    {
        int n, m;
        cin >> n >> m;
       for(int i = 0; i <= n; i++)v[i].clear(), vis[i] = 0,dis[i] = 0;
        for(int i = 1; i <= m; i++)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
       bfs(1);

       //for(int i = 1; i <= n; i++)cout << dis[i] << " ";
       cout <<dis[n]<< endl;
    }
}
