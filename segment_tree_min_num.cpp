#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int a[1000001], st[1000001];

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

     st[si] = min(st[si*2], st[si*2 + 1]);

     return;
 }

 void update(int si, int ss, int se, int qs, int val)
 {
    if(se == ss){
            st[si] = val;
            return;
    }

      int mid = (ss + se) / 2;
    if(qs <= mid) update(si * 2, ss, mid, qs, val);
    else update(si * 2 + 1, mid + 1, se, qs, val);

    st[si] = min(st[si * 2], st[si * 2 + 1]);

    return;
 }

 int query(int si, int ss, int se, int qs, int qe)
 {
     if(ss > qe || se < qs)return INT_MAX;
     if(ss >= qs and se <= qe)return st[si];

     int mid = (ss + se) / 2;

     return min(query(si*2,ss,mid, qs, qe), query(si*2+1, mid + 1, se, qs, qe));
 }

int main()
{
    int n, m;
    cin >> n >> m;
   for(int i = 1; i <= n; i++)cin >> a[i];


     build(1, 1, n);

    while(m--)
    {
        int x;
        cin >> x;
        if(x == 1)
        {
            int val;
            cin >> x >> val;

            update(1, 1, n, x+1, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l+1, r) << endl;
        }
    }
}
