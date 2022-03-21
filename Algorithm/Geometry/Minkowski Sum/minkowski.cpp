// Minkowski Sum

struct Point {
    long double x, y;
    
    Point operator + (Point other) const {
        return Point{x + other.x, y + other.y};
    }

    Point operator - (Point other) const {
        return Point{x - other.x, y - other.y};
    }

    long double cross(Point other) const {
        return x * other.y - y * other.x;
    }
};

bool cmp(const Point &a, const Point &b) {
    if (abs(a.y - b.y) < EPS) return a.x < b.x;
    return a.y < b.y;
}

void reorder_polygon(vector<Point> &a) {
    int pos = 0;
    for (int i = 1; i < a.size(); i++) {
        if (cmp(a[i], a[pos])) pos = i;
    }

    rotate(a.begin(), a.begin() + pos, a.end());
}

vector<Point> minkowski(vector<Point> &p, vector<Point> &q) {
    // the first vector must be the lowest
    reorder_polygon(p);
    reorder_polygon(q);

    // we must ensure cyclic indexing
    p.push_back(p[0]);
    p.push_back(p[1]);
    q.push_back(q[0]);
    q.push_back(q[1]);

    // main part
    vector<Point> res;
    int i = 0, j = 0;
    while (i < p.size() - 2 || j < q.size() - 2) {
        res.push_back(p[i] + q[j]);
        auto cross = (p[i + 1] - p[i]).cross(q[j + 1] - q[j]);
        if (cross >= 0) i++;
        if (cross <= 0) j++;
    }

    // if there if an array of polygons
    // p.pop_back();
    // p.pop_back();

    // q.pop_back();
    // q.pop_back();

    return res;
}

// Distance of 2 polygons
// O(0, 0) -> P + (-Q)

long double sq(long double a) {
    return a * a;
}

long double sqDist(Point a, Point b) {
    return sq(b.x - a.x) + sq(b.y - a.y);
}

long double dist(Point a, Point b) {
    return sqrt(sq(b.x - a.x) + sq(b.y - a.y));
}

long double area(Point a, Point b, Point c) {
    return abs((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));
}

bool valid(Point a, Point b, Point c) {
    // 2 góc dưới của tam giác là góc nhọn
    long double ab = sqDist(a, b);
    long double ac = sqDist(a, c);
    long double bc = sqDist(b, c);

    return (ab < ac + bc && ac < ab + bc);
}

long double distPoly(vector<Point> &p, vector<Point> &q) {
    long double res = INF;
    auto a = minkowski(p, q);

    Point root = {0, 0};
    for (auto i: a) {
        res = min(res, dist(root, i));
    }

    int n = a.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;

        if (!valid(root, a[i], a[j])) continue;

        long double altitude = area(root, a[i], a[j]) / dist(a[i], a[j]);
        res = min(res, altitude);  
    }

    return res;
}