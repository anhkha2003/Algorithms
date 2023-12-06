// Linear Programming
// Solves a general linear maximization problem: 
// condition: Ax <= b, x >= 0
// maximize c^T * x
// A: (m, n) matrix, b: (m, 1) matrix, c: (n, 1), x: (n, 1)
// Returns -inf if no solution, inf if arbitrarily good solutions, or maximum value of c^T * x otherwise
// The input vector is set to an optimal x (or in the unbounded case, an arbitrary solution fulfilling the constraints).
// Usage:
// vvd A = {{1,-1}, {-1,1}, {-1,-2}};
// vd b = {1,1,-4}, c = {-1,-1}, x;
// T val = LPSolver(A, b, c).solve(x);
// Time: O(NM * \#pivots), where a pivot may be e.g. an edge relaxation. O(2^n) in the general case.

const double EPS = 1e-8;
const double INF = 1.0 / 0.0;

struct LPSolver {
    int m, n;
    vector<int> N, B;
    vector<vector<double>> D;

    LPSolver(const vector<vector<double>>& A, const vector<double>& b, const vector<double>& c) :
        m(b.size()), n(c.size()), N(n + 1), B(m), D(m + 2, vector<double>(n + 2)) {
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                D[i][j] = A[i][j];
            }
            B[i] = n+i;
            D[i][n] = -1;
            D[i][n + 1] = b[i];
        }

        for (int j = 0; j < n; ++j) {
            N[j] = j;
            D[m][j] = -c[j];
        }
        N[n] = -1; D[m + 1][n] = 1;
    }

    void pivot(int r, int s) {
        double inv = 1.0 / D[r][s];
        for (int i = 0; i < m + 2; ++i) {
            if (i != r) {
                for (int j = 0; j < n + 2; ++j) {
                    if (j != s) {
                        D[i][j] -= D[r][j] * D[i][s] * inv;
                    }
                }
                D[i][s] = -D[i][s] * inv;   
            }
        }

        for (int j = 0; j < n + 2; ++j) {
            if (j != s) D[r][j] *= inv;
        }

        D[r][s] = inv;
        swap(B[r], N[s]);
    }

    bool simplex(int phase) {
        int x = m + phase - 1;
        while(true) {
            int s = -1;
            for (int j = 0; j <= n; ++j) {
                if (N[j] != -phase && (s == -1 || D[x][j] < D[x][s])) s = j;
            }
            if (D[x][s] >= -EPS) return true;

            int r = -1;
            for (int i = 0; i < m; ++i) {
                if (D[i][s] > EPS) {
                    if (r == -1) {
                        r = i;
                        continue;
                    }

                    pair<double, double> pi(D[i][n + 1] / D[i][s], B[i]);
                    pair<double, double> pr(D[r][n + 1] / D[r][s], B[r]);
                    if (pi < pr) r = i;
                }
            }
            if (r == -1) return false;
            pivot(r, s);
        }
    }

    double solve(vector<double> &x) {
        int r = 0;
        for (int i = 1; i < m; ++i) {
            if (D[i][n + 1] < D[r][n + 1]) r = i;
        }

        if (D[r][n + 1] < -EPS) {
            pivot(r, n);
            if (!simplex(2) || D[m + 1][n + 1] < -EPS) return -INF;
            for (int i = 0; i < m; ++i) {
                if(B[i] == -1) {
                    pivot(i, find_if(N.begin(), N.end(), [&](int j){ return D[i][j] > EPS; }) - N.begin());
                }
            }
        }

        if (!simplex(1)) return INF;
        x.assign(n, 0);
        for (int i = 0; i < m; ++i) {
            if (B[i] < n) x[B[i]] = D[i][n + 1];
        }
        return D[m][n + 1];
    }
};