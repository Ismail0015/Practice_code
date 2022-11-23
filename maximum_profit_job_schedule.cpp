#include<bits/stdc++.h>
#define int long long int
using namespace std;
int dp[500005];
int solve(int i, vector<int>&start, vector<int>&End, vector<int>&profit, int n){
    if(i == n-1)return profit[i];

    if(i > n-1)return 0;
    if(dp[i] != -1)return dp[i];
    int pos = lower_bound(start.begin()+i+1, start.end(), End[i])-start.begin();
    return dp[i] = max(profit[i]+solve(pos,start,End,profit,n),solve(i+1,start,End,profit,n));
}
int32_t main(){
    int n;
    cin >> n;

    vector<int>start(n), End(n), profit(n);
    vector<vector<int>>v(n);
    for(int i = 0; i < n; i++){
        cin >> start[i] >> End[i] >> profit[i];
    }
    for(int i = 0; i < n; i++){
        v[i].push_back(start[i]);
        v[i].push_back(End[i]);
        v[i].push_back(profit[i]);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        start[i] = v[i][0];
        End[i] = v[i][1];
        profit[i] = v[i][2];
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0, start, End, profit, n);
}
