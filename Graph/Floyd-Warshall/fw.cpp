    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) dist[i][j] = INF;
        }
    }

    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        dist[u][v] = min((long long) c, dist[u][v]);
        dist[v][u] = min((long long) c, dist[v][u]);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }