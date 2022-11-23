

#include<bits/stdc++.h>
using namespace std;
#define   MP      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define   ll      long long int
#define   point    fixed << setprecision
#define   PI      acos(-1)
#define   End     return 0
#define   mod     1000000007
#define   g       greater<int>()
#define   amax    *max_element
#define   amin    *min_element
#define   forn    for(int i = 0; i < n; i++)
#define   sz      size()
#define   pb      push_back
#define   asort   sort(a,a+n)
#define   ssort   sort(s.begin(),s.end())
#define   vsort   sort(v.begin(),v.end())
#define   gsort   sort(s.begin(),s.end(),greater<int>())
#define   tsort   sort(t.begin(),t.end())
#define   ei      s.erase(unique(s.begin(),s.end()),s.end())
#define   tlwr    transform(s.begin(),s.end(),s.begin(),::tolower);
#define   tupr    transform(s.begin(),s.end(),s.begin(),::toupper);
#define   rot     rotate(arr.begin(), arr.begin() + 3, arr.end());
#define   psum    partial_sum
#define   acsum   accumulator()
int Dx[] = {-2,-1, 1, 2, 2, 1, -1,-2};
int Dy[] = { 1, 2, 2, 1,-1, -2,-2,-1};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char ar[31][31]; bool vis[31][31]; int  dis[31][31], n;
bool valid(int x, int y)
{
    if(x < 1 or x > n or y < 1 or y > n)return false;
    if(vis[x][y] or ar[x][y] == 'T')return false;

    return true;
}
void bfs(int x, int y)
{
    queue<pair<int,int>>q;
    q.push({x, y});
    vis[x][y] = 1;
    dis[x][y] = 0;

    while(!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            if(valid((cur_x + dx[i]), (cur_y + dy[i])))
               {
                   x = cur_x + dx[i]; y = cur_y + dy[i];
                   dis[x][y] = dis[cur_x][cur_y] + 1;
                   vis[x][y] = 1;
                   q.push({x, y});
               }
        }
    }
}
int main()
{
   MP;


        cin >> n;
        int starti, startj, endi, endj;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> ar[i][j];

                if(ar[i][j] == 'S')starti = i, startj = j;
                if(ar[i][j] == 'E')endi = i, endj = j;
            }
        }
        bfs(starti, startj);

        cout << dis[endi][endj];
   End;
}
