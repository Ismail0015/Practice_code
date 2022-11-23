//                       ***BISMILLAHIR RAH MANIR RAHIM***
#include<bits/stdc++.h>
using namespace std;
#define   MP      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define   ll      long long int
#define   point   fixed << setprecision
#define   YES     printf("YES\n")
#define   NO     printf("NO\n")
#define   Yes     printf("Yes\n")
#define   No     printf("No\n")
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
#define   gsort   sort(s.begin(),s.end(),greater<int>())
#define   tsort   sort(t.begin(),t.end())
#define   ei      s.erase(unique(s.begin(),s.end()),s.end())
#define   tlwr    transform(s.begin(),s.end(),s.begin(),::tolower);
#define   tupr    transform(s.begin(),s.end(),s.begin(),::toupper);
#define   rot     rotate(arr.begin(), arr.begin() + 3, arr.end());
#define   psum    partial_sum
/*bool s[10000000];
ll a[10000000], c = 0;
void seive()
 {
     for(ll i = 1; i <= 10000000; i+=2)s[i] = 1;s[1] = 0, s[2] = 1;
    for(ll i = 1; i <= 10000000; i++)
    {if(s[i]){
        a[++c] = i;
        for(ll j = i*i ; j <= 10000000; j += i)
            {
                s[j] = 0;
            }
            }
        }
 }*/

int main()
{
   MP;

    string s; cin >> s;
        int n = s.size();
        string t = "";
        if(n == 1)t = s;
        else if(n == 0)t = t;
        else{
        int dp[n + 1][n + 1];
        for(int i = 0; i <= n; i++)dp[0][i] = dp[1][i] = 1;
        int resE = 1, resL = 1;
        for(int i = 2; i <= n; i++)
        {
            for(int j = i; j <= n; j++)
            {
        if(s[j - 1] == s[j - i] and dp[i - 2][j - 1] == 1)dp[i][j] = 1, resE = i, resL = j;
                else dp[i][j] = 0;
            }
        }
        for(int i = resL - resE + 1; i <= resL; i++)t += s[i - 1];
        }
        cout << t;

   End;
}


