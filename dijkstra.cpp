#include<bits/stdc++.h>
#define sz 100001
#define inf 1e18
#define ll long long int
using namespace std;

ll d[sz], p[sz];
vector < ll > v[sz];
map<pair<ll,ll>, ll>mp;

void f(ll x)
{
    if(x != 1)f(p[x]);
    cout << x << " ";
}

int main()
{
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= m; i++)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        v[a].push_back(b);
        v[b].push_back(a);
        mp[{a,b}] = w;
        mp[{b,a}] = w;
    }

    for(ll i = 2; i <= sz; i++)d[i] = inf;

    priority_queue<ll>q;
    q.push(1);

    while(!q.empty())
    {
        ll k = q.top();
        q.pop();

        for(ll i = 0; i < v[k].size(); i++)
        {
            ll z = v[k][i];
            ll w = mp[{k,z}];

            if(d[k]+w < d[z])d[z] = d[k]+w, q.push(z), p[z] = k;
        }
    }

    if(d[n] == inf)cout << -1 << endl;
    else f(n);
    //cout << endl;
    //cout << d[n];
}

