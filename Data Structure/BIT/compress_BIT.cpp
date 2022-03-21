// nén BIT
// xử lí với số lớn (vd như l[i] <= 1e9)
// biết trc sẽ update vị trí nào để add vào BIT trc
// thay vì update và get với vị l[i], mình tìm xử lí vs số thứ tự đc nén trong numbers

struct BIT {
    vector<int> numbers;
    vector<int> fen;   

    void add(int x) {
        numbers.push_back(x);
    }

    void setup() {
        fen.resize(numbers.size() + 1);
        sort(numbers.begin(), numbers.end());
    }

    int find(int x) {
        return upper_bound(numbers.begin(), numbers.end(), x) - numbers.begin();  
    }

    void update(int u, int v) {
        u = find(u);
        for (int i = u; i <= numbers.size(); i += i & -i) {
            fen[i] += v;
            fen[i] %= MOD;
        }
    }

    long long getSum(int u) {
        u = find(u);
        long long res = 0;
        for (int i = u; i; i -= i & -i) {
            res += fen[i];
            res %= MOD;
        }
        return res;
    }
};

vector<Edge> edges;
int l[500005];
long long d[500005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    vector<BIT> bit(n + 1);

    for (auto e: edges) {
        l[id] = e.milk;
        bit[e.v].numbers.push_back(l[id] + 1);
        id++;
    }

    for (int i = 1; i <= n; i++) {
        bit[i].setup();
    }

    for (int i = 0; i < m; i++) {
        d[i] += bit[edges[i].u].getSum(l[i]) + 1;
        bit[edges[i].v].update(l[i] + 1, d[i]);
    }

    return 0;
}