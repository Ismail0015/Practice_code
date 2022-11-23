
//                       ***BISMILLAHIR RAH MANIR RAHIM***
#include<bits/stdc++.h>
using namespace std;
#define   MP      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define   int      long long int
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
int Dx[] = {-2,-1, 1, 2, 2, 1, -1,-2};
int Dy[] = { 1, 2, 2, 1,-1, -2,-2,-1};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
/*bool s[10000000];ll a[10000000], c = 0;
void seive(){for(ll i = 1; i <= 10000000; i+=2)s[i] = 1;s[1] = 0, s[2] = 1;
    for(ll i = 1; i <= 10000000; i++){if(s[i]){a[++c] = i;for(ll j = i*i ; j <= 10000000; j += i){s[j] = 0;}}}}*/
//int fact(int n) {
//   if (n == 0 || n == 1)return 1;else return n * fact(n - 1);}comb = fact(n) / (fact(r) * fact(n-r));
int fun(vector<int>&v, int n)
{
    int c = 0, sum = 0;
    for(int i = n-1; i >= 0; i--)
    {
        if(v[i] == 0)
        {
            c++;
        }
        else
        {
            sum+=c;
        }
    }
    return sum;
}
void solve(){
  int n;
        cin >> n;
        vector<int>a(n),b(n), c(n);
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i], sum += a[i];
            b[i] = a[i],c[i] = a[i];
        }
        for(int i = 0; i < n; i++)
        {
            if(a[i] == 0)
            {
                b[i] = 1;
                break;
            }
        }
        for(int i = n-1; i >= 0; i--)
        {
            if(a[i] == 1)
            {
                c[i] = 0;
                break;
            }
        }
        int x = 0, y = 0, z = 0;


        if(sum == 0)
        {
            a[0] = 1;
            int cc = 0;
            for(int i = n-1; i >= 0; i--)
            {
                if(a[i] == 0)
                {
                    cc++;
                }
                else
                {
                    x+=cc;
                }
            }
        }
        else if(sum == n)
        {
            a[n-1] = 0;
             int cc = 0;
    for(int i = n-1; i >= 0; i--){
        if(a[i] == 0){
            cc++;
        }
        else {
            y+=cc;
        }
    }
        }
        int p1 = fun(a, n);
        int p2 = fun(b, n);
        int p3 = fun(c, n);
        cout << max({x,y,z,p1,p2,p3}) << endl;

}

int32_t main()
{
   MP;
      int t;
      //t = 1;
     cin >> t;
     while(t--){
        solve();
     }


   End;
}




