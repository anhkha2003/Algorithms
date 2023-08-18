#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-8;

struct Point {
    double x, y;
    int id;
};

double sq(double a) {
    return a * a;
}

double dist(Point a, Point b) {
    return sqrt(sq(b.x - a.x) + sq(b.y - a.y));
}

bool cmpX(const Point &a, const Point &b) {
    if (abs(a.x - b.x) < EPS) return a.y < b.y;
    return a.x < b.x;
}

bool cmpY(const Point &a, const Point &b) {
    return a.y < b.y;
}

vector<Point> p, t;
double minDist;
pair<int, int> best_pair;

void upd_ans(const Point &a, const Point &b) {
    double d = dist(a, b);
    if (d < minDist) {
        minDist = d;
        best_pair = {a.id, b.id};
    }
}

void calc(int l, int r) {
    if (r - l <= 3) {
        for (int i = l; i < r; i++) {
            for (int j = i + 1; j < r; j++) {
                upd_ans(p[i], p[j]);
            }
        }
        sort(p.begin() + l, p.begin() + r, cmpY);
        return;
    }

    int mid = (l + r) / 2;
    int midX = p[mid].x;
    calc(l, mid);
    calc(mid, r);

    merge(p.begin() + l, p.begin() + mid, p.begin() + mid, p.begin() + r, t.begin(), cmpY);
    copy(t.begin(), t.begin() + r - l, p.begin() + l);

    int num = 0;
    for (int i = l; i < r; i++) {
        if (abs(p[i].x - midX) < minDist) {
            for (int j = num - 1; j >= 0 && p[i].y - t[j].y < minDist; j--) {
                upd_ans(p[i], t[j]);
            }
            t[num++] = p[i];
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    p.resize(n);
    t.resize(n);

    // 0 - indexed
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
    }

    sort(p.begin(), p.end(), cmpX);

    minDist = 1e18;

    calc(0, n);

    if (best_pair.first > best_pair.second) swap(best_pair.first, best_pair.second);
    
    cout << best_pair.first << ' ' << best_pair.second << ' ';
    cout << fixed << setprecision(6) << minDist;

    return 0;
}