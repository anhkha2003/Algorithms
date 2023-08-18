// use for functional graphs / successor graphs
// cycle detection

int tortoise_and_hare(int n) {
    // find a node in cycle
    int a = t[n];
    int b = t[t[n]];
    while (a != b) {
        a = t[a];
        b = t[t[b]];
    }

    // find the first node if walk from n
    a = n;
    while (a != b) {
        a = t[a];
        b = t[b];
    } 

    // find the length and nodes of the cycle
    vector<int> nodes;
    b = t[a];
    int len = 1;
    while (a != b) {
        nodes.push_back(b);
        b = t[b];
        len++;
    }
    nodes.push_back(b);

    return a;
}