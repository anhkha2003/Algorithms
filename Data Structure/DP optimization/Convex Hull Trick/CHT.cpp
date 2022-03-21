// dp[i] = min(dp[j] + b[j] * a[i] + C)

// line: y = x * a + b
//       dp[i] = a[i] * b[j] + dp[j] + C
// addLine(a, b) => addLine(b[i], dp[i]) (after calc dp[i])
// y = getMin(x) => dp[i] = getMin(a[i]) + C

// Example: 
// dp[i] = dp[j] + (h[i] - h[j])^2 + C
//       = dp[j] + h[j]^2 - 2 * h[j] * h[i] + h[i]^2 + C
// addLine(-2 * h[i], dp[i] + h[i]^2)
// dp[i] = getMin(h[i]) + h[i]^2 + C

// complexity: O(n)

// when the array is sorted
// return the minimum value
// add line in increasing order of a (slope)

// Min-decreasing order: add(-a, b)  ___  min = query(-x)
// Max-decreasing order: add(-a, -b) ___  max = -query(x)
// Max-increasing order: add(a, -b)  ___  max = -query(-x)

struct Point {
    long long x, y;
};

struct CHT {
    vector<Point> pts;

    double cross (Point a, Point b) {return (double)(b.y - a.y) / (b.x - a.x);}

    void addLine(long long x, long long y) {
        if (pts.size() && pts.back().x == x && pts.back().y == y) return;

        while(pts.size() >= 2 && cross(pts[pts.size()-2], pts.back()) > cross(pts.back(), (Point){x, y})){
            pts.pop_back();   
        }
        pts.push_back({x, y});
    }

    long long query(long long x) {
        int s = 0, e = (int) pts.size()-1;
        auto f = [&](int p) {
            return pts[p].x * x + pts[p].y;
        };

        while(s != e){
            int m = (s + e) / 2;
            if(f(m) <= f(m + 1)) e = m;
            else s = m + 1;
        }
        return pts[s].x * x + pts[s].y;
    }
};