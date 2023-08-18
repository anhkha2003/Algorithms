#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2000005];
int h[2000005];

void dfs(int n, int par) {
	for (auto i: adj[n]) {
		if (i == par) continue;
		h[i] = h[n] + 1;
		dfs(i, n);
	}
}

int findEnd(int n, int root) {
	int x = root, maxVal = 0;
	for (int i = 1; i <= n; i++) {
		if (maxVal < h[i]) {
			x = i;
			maxVal = h[i];
		}
	}
	return x;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    dfs(1, 0);
    int x = findEnd(n);

    for (int i = 1; i <= n; i++) h[i] = 0;

    dfs(x, 0);
	int y = findEnd(n);
	int dist = h[y]; // x -> y

	cout << dist;
    
    return 0;
}