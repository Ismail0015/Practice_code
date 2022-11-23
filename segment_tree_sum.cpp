#include <bits/stdc++.h>
#define ll long long int
using namespace std;

  ll a[1000001];
  unsigned ll st[1000001];


void build (int si , int ss , int se){

    if(ss == se){
        st[si] = a[ss];
        return;
    }
     int mid = (ss+se)/2;
    build(si * 2 , ss , mid);
    build(si * 2 + 1,  mid + 1, se );
    st[si] = st[si * 2] + st[si * 2 + 1];
    return;
}

void update (int si , int ss , int se , int qs , ll val){

    if(ss == se){
        st[si] = val;
        return;
    }
    int mid = (ss + se)/2;
    if(qs <= mid ){
        update(si * 2 , ss , mid, qs, val);
    } else {
        update(si * 2 + 1, mid + 1 , se , qs, val);
    }
      st[si] = st[si * 2] + st[si * 2 + 1];
      return;
}
void add (int si , int ss , int se , int qs , ll val){

    if(ss == se){
        st[si] += val;
        return;
    }
    int mid = (ss + se)/2;
    if(qs <= mid ){
        update(si * 2 , ss , mid, qs, val);
    } else {
        update(si * 2 + 1, mid + 1 , se , qs, val);
    }
      st[si] = st[si * 2] + st[si * 2 + 1];
      return;
}

ll query (int si , int ss , int se , int qs , int qe){

   if(ss > qe || se < qs) return 0;

    if(ss >= qs && se <=qe){
        return st[si]-st[si+2];
    }
    int mid = (ss + se) / 2;

    return query(si * 2, ss ,mid, qs  ,  qe)+ query(si * 2 + 1, mid + 1, se , qs  ,  qe);

}


int main()
{
    int t , n, m  , q;
    int c;
      cin >> n;

      for(int i = 1; i <= n; i++)cin >> a[i];
      build(1 ,1 , n);
      cin >> m;
      for(int i = 0; i < m; i++)
      {
          ll x, l , r;
          cin >> x;
          if(x == 1){
                cin >> l;
                update(1, 1, n, 1, r);
          }
          else if(x==2){
              cin >> l >> r;
             add(1, 1, n, l, r);
          }
          else {
                cin >> l;
                cout << query(1, 1, n, 1, l) << endl;
          }
      }


    return 0;
}
