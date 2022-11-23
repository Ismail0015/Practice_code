#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int ans = 0;
void fun(int n, int a[], int sum, int idx, int m){
     if(idx >= n){
        if(sum > 0 and sum % m == 0){
            ans = 1;
        }return;
     }
     //sum += a[idx];
     fun(n, a, sum+a[idx], idx+1, m);
    // sum += a[idx];
     fun(n, a, sum, idx+1, m);
}
int main()
{
    int n, m; cin >> n >> m;
    int a[n+1];
    for(int i = 0; i < n; i++){cin >> a[i]; if(!a[i])ans= 1;
    }
    if(ans)cout << "YES" ;
    else {fun(n, a, 0, 0, m);
    ans?cout << "YES":cout << "NO";

}
}

