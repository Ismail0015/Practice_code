#include<bits/stdc++.h>
#define ll long long int
using namespace std;
char ar[1001][1001]; int vis[1001][1001];
int n, m;
int dx[]={-1, 1, 1, 0};
int dy[]={ 1, -1, 0, 1};

bool valid(int x, int y)
{
    if(x < 1 or x > n or y < 1 or y > m)return false;

    if(vis[x][y] or ar[x][y] == '#')return false;

    return true;
}
void dfs(int x, int y)
{
    vis[x][y] = 1;

    if(valid(x, y+1))dfs(x, y+1);
    if(valid(x, y-1))dfs(x, y-1);
    if(valid(x+1, y))dfs(x+1, y);
    if(valid(x - 1, y))dfs(x-1, y);
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> ar[i][j];
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(!vis[i][j] and ar[i][j] == '.')
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
}
