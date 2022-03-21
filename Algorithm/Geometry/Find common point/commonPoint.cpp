const long double EPS = 1e-8;
const double INF = -1e9;

struct Line {
    double a, b, c;
};

pair<double, double> commonPoint(Line &p, Line &q) {
    // a1 * b2 - a2 * b1
    double deter = p.a * q.b - p.b * q.a;

    if (abs(deter) < EPS) return {INF, INF};

    double x = (q.b * p.c - p.b * q.c) / deter; // b2 * c1 - b1 * c2
    double y = (p.a * q.c - q.a * p.c) / deter; // a1 * c2 - a2 * c1
    return {x, y};
}