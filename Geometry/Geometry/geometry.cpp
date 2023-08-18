// EPS: <= 1e-9 for long double
// EPS: <= 1e-8 for double

// long long -> long double
//   >= 0    ->     > -EPS
//   > 0     ->     > EPS

const double PI = acos(-1.0);

double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }

struct Point {
    long double x, y;
    Point (long double x = 0, long double y = 0): x(x), y(y){}
    Point operator+(const Point& a) const{
        return {x + a.x, y + a.y};
    }
    Point operator-(const Point& a) const{
        return {x - a.x, y - a.y};
    }
    long double operator*(const Point& a) const{
        return x * a.x + y * a.y;
    }
    Point operator*(long double c) const {
        return {x * c, y * c};
    }
    bool operator<(const Point&a) {
        if (abs(x - a.x) < EPS) return y < a.y;
        return x < a.x;
    }
    bool operator==(const Point&a) {
        return (fabs(x - a.x) < EPS && fabs(y - a.y) < EPS);
    }
    Point rotate(double angle) { // rotate around origin (0, 0)
        // [ cos -sin ] [ x ]  =  [x*cos - y*sin]
        // [ sin  cos ] [ y ]     [x*sin + y*cos]
        double angleRad = angle * PI / 180;
        double a = x * cos(angleRad) - y * sin(angleRad);
        double b = x * sin(angleRad) + y * cos(angleRad);
        return {a, b};
    }
};

#define sq(x) ((x) * (x))

long double cross(const Point& A, const Point& B) {
    return A.x * B.y - A.y * B.x;
}

// cross(CA, CB) < 0: CA -> turns right -> CB
// cross > 0: left,    cross = 0: touch,     cross < 0: right
long double cross(const Point&A, const Point& B, const Point& C) {
    return cross(A - C, B - C);
}
long double abs(const Point& A) {
    return sqrt(sq(A.x) + sq(A.y));
}

// ----------------------- Segment ---------------------

// long long
// Check if point C lies on line segment [AB]
bool onSegment(Point a, Point b, Point c) {
    return cross(a, b, c) == 0
        && min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x)
        && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

// Returns true if segment [a, b] and [c, d] intersects
// End point also returns true
bool intersect(Point a, Point b, Point c, Point d) {
    if (onSegment(a, b, c) || onSegment(a, b, d) || onSegment(c, d, a) || onSegment(c, d, b)) {
        return true;
    }

    return cross(a, b, c) * cross(a, b, d) < 0 and
        cross(c, d, a) * cross(c, d, b) < 0;

    // use when cross * cross overflow 
    // long long p1 = (cross(a, b, c) < 0), p2 = (cross(a, b, d) < 0);
    // long long p3 = (cross(c, d, a) < 0), p4 = (cross(c, d, b) < 0);
    // return (p1 != p2 && p3 != p4);
}

// double
// A on [BC]
bool onSegment(Point A, Point B, Point C) {
    return fabs(cross(A, B, C)) < EPS && (A.x - B.x) * (A.x - C.x) < EPS && (A.y - B.y) * (A.y - C.y) < EPS;
}

// segment intersect
bool intersect(Point a, Point b, Point c, Point d) {
    if (onSegment(c, a, b) || onSegment(d, a, b) || onSegment(a, c, d) || onSegment(b, c, d)) {
        return true;
    }

    return cross(b, c, a) * cross(b, d, a) < -EPS and
        cross(d, a, c) * cross(d, b, c) < -EPS;
}

// ---------------------- Line --------------------------

// ax + by + c = 0
struct Line {
    long double a, b, c;
    Line(long double a, long double b, long double c): a(a), b(b), c(c){}
    Line(Point A, Point B) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = -(a * A.x + b * A.y);
    }
};

bool areParallel(Line l1, Line l2) {
    return fabs(l1.a * l2.b - l1.b * l2.a) < EPS;
}
bool areIntersect(Line l1, Line l2, Point& p) {
    if (areParallel(l1, l2)) return 0;
    long double dx = l1.b * l2.c - l2.b * l1.c;
    long double dy = l1.c * l2.a - l2.c * l1.a;
    long double d = l1.a * l2.b - l2.a * l1.b;
    p = {dx / d, dy / d};
    return 1;
}

Point circumcenter(Point A, Point B, Point C) {
    B = B - A;
    C = C - A;
    Line l1 = {B.x * 2, B.y * 2, -sq(B.x) - sq(B.y)};
    Line l2 = {C.x * 2, C.y * 2, -sq(C.x) - sq(C.y)};
    Point O;
    assert(areIntersect(l1, l2, O));
    O = O + A;
    return O;
}

// ---------------------- Angle --------------------------
// a^2 = b^2 + c^2 - 2bc*cos(A)
double angle(Point a, Point b, Point c) {
    double bc = dist(b, c);
    double ab = dist(a, b);
    double ac = dist(a, c);
    double val = ab * ab + ac * ac - bc * bc;
    val /= (2 * ab * ac);
    return acos(val) * 180 / PI; // in degrees
} 

// ---------------------- Polygon --------------------------

// *1.0 if use int
bool inPolygon(vector<Point>& p, Point q) {
    if (p.size() == 0) return 0;
    int n = p.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if (onSegment(q, p[i], p[j])) return 1; // on boundary
    }
    int c = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if ((p[i].y <= q.y && q.y < p[j].y || p[j].y <= q.y && q.y < p[i].y) && q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y)) c = !c;
    }
    return c; // 0/1: outside/inside
}

#define Det(a,b,c) ((double)(b.x-a.x)*(double)(c.y-a.y)-(double)(b.y-a.y)*(c.x-a.x))
bool inConvex(vector<Point>& l, Point p){
    int a = 1, b = l.size()-1, c;
    if (Det(l[0], l[a], l[b]) > EPS) swap(a,b);
    // Allow on edge --> if (Det... > 0 || Det ... < 0)
    if (Det(l[0], l[a], p) > -EPS || Det(l[0], l[b], p) < EPS) return false;
    while(abs(a-b) > 1) {
        c = (a+b)/2;
        if (Det(l[0], l[c], p) > EPS) b = c; else a = c;
    }
    // Alow on edge --> return Det... <= 0
    return Det(l[a], l[b], p) < -EPS;
}

// counter clockwise
double area2(Point a, Point b, Point c) { return cross(a, b) + cross(b, c) + cross(c, a); }

vector<Point> convexHull(vector<Point> pts) {
    int n = pts.size();
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<Point> up, dn;
    for (int i = 0; i < n; i++) {
        // Note: If need maximum points on convex hull, need to change >= 0 and <= 0 to > 0 and < 0.
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) > -EPS) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) < EPS) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
    if (pts.size() > n) pts = {dn[0], dn.back()}; // pts = dn if need maximum points
    return pts;
}