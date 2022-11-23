#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int a[200005], st[4*200005];

 void build(int si, int ss, int se)
 {
     if(ss == se)
     {
         st[si] = a[ss];
         return;
     }

     int mid = (ss + se) / 2;

     build(si * 2, ss, mid);
     build(si * 2 + 1, mid + 1, se);

     st[si] = max(st[si*2], st[si*2 + 1]);

     return;
 }

 int query(int si, int ss, int se, int qs, int qe)
 {
     if(ss > qe || se < qs)return INT_MIN;
     if(ss >= qs and se <= qe)return st[si];

     int mid = (ss + se) / 2;

     return max(query(si*2,ss,mid, qs, qe), query(si*2+1, mid + 1, se, qs, qe));
 }

int main()
{
    int n, m, t;
    cin >> t;
    for(int j = 1; j <= t; j++){
    cin >> n >> m;
    //st.clear();
    //a.resize(n), st.resize(n);
   for(int i = 0; i < n; i++)cin >> a[i];


     build(1, 0, n);
    cout << "Case " << j << ':' << endl;
    while(m--)
    {
            int l, r, c = 0;
            cin >> l >> r;

            int x = query(1, 0, n, l, r);
           for(int i = l; i<= r; i++){
             if(a[i] == x)c++;
           }
           cout << c << endl;
    }
  }
}
