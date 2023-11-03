#include<bits/stdc++.h>
using namespace std;

const int N = 1010;


struct BIT2D {
  vector<vector<vector<long long>>> M, A;
  int N;

  BIT2D(int n, int m) : N(n + 1) {
    M = vector<vector<vector<long long>>>(N, vector<vector<long long>>(N, vector<long long>(2, 0)));
    A = vector<vector<vector<long long>>>(N, vector<vector<long long>>(N, vector<long long>(2, 0)));
  }

  void upd2(vector<vector<vector<long long>>>& t, int x, int y, long long mul, long long add) {
    for(int i = x; i < N; i += i & -i) {
      for(int j = y; j < N; j += j & -j) {
        t[i][j][0] += mul;
        t[i][j][1] += add;
      }
    }
  }

  void upd1(int x, int y1, int y2, long long mul, long long add) {
    upd2(M, x, y1, mul, -mul * (y1 - 1));
    upd2(M, x, y2, -mul, mul * y2);
    upd2(A, x, y1, add, -add * (y1 - 1));
    upd2(A, x, y2, -add, add * y2);
  }

  void upd(int x1, int y1, int x2, int y2, long long val) {
    upd1(x1, y1, y2, val, -val * (x1 - 1));
    upd1(x2, y1, y2, -val, val * x2);
  }

  long long query2(const vector<vector<vector<long long>>>& t, int x, int y) {
    long long mul = 0, add = 0;
    for(int i = y; i > 0; i -= i & -i) {
      mul += t[x][i][0];
      add += t[x][i][1];
    }
    return mul * y + add;
  }

  long long query1(int x, int y) {
    long long mul = 0, add = 0;
    for(int i = x; i > 0; i -= i & -i) {
      mul += query2(M, i, y);
      add += query2(A, i, y);
    }
    return mul * x + add;
  }

  long long query(int x1, int y1, int x2, int y2) {
    return query1(x2, y2) - query1(x1 - 1, y2) - query1(x2, y1 - 1) + query1(x1 - 1, y1 - 1);
  }
};

int main() {
  if(fopen("input.txt", "r")) {
      freopen("input.txt","r",stdin);
      // freopen("output.txt","w",stdout);
  }

  ios::sync_with_stdio(0);
  cin.tie(NULL);
  
  int n, m;
  cin >> n >> m;
  BIT2D t(n,m);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      int k;
      cin >> k;
      t.upd(i, j, i, j, k);
    }
  }

  int q;
  cin >> q;
  
  while(q--) {
    int ty, x1, y1, x2, y2;
    cin >> ty;
    if(ty == 1) {
      long long val;
      cin >> x1 >> y1 >> x2 >> y2 >> val;
      t.upd(x1, y1, x2, y2, val); // add val from top-left(x1, y1) to bottom-right (x2, y2);
    } 
    else {
      cin >> x1 >> y1 >> x2 >> y2;
      cout << t.query(x1, y1, x2, y2) << '\n'; // output sum from top-left(x1, y1) to bottom-right (x2, y2);
    }
  }
  return 0;
}