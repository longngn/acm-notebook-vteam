#include <set>
#include <iostream>

using namespace std;

int DijkstraHeap(int s, int t) {
    for(int i = 1; i <= n; i++) tr[i] = 0, d[i] = oo;
    set<pair<int, int> > h; h.insert(make_pair(0, s));
    tr[s] = -1, d[s] = 0; 
    while (!h.empty()) {
        int u = h.begin() -> second; h.erase(h.begin());
        for(auto _v: adj[u]) {
            int v = _v.first, w = _v.second;
            if (tr[v] == 0) {
                tr[v] = u;
                d[v] = d[u] + w;
                h.insert(make_pair(d[v], v));
            } else if (d[u] + w < d[v]) {
                h.erase(make_pair(d[v], v));
                d[v] = d[u] + w;
                h.insert(make_pair(d[v], v));
            }
        }
    }
    return d[t];
}

int Floyd() {
    for(int u = 1; u <= n; u++) 
        for(int v = 1; v <= n; v++) 
            c[u][v] = u == v ? 0 : oo, tr[u][v] = v;
    readGraph();
    for(int k = 1; k <= n; k++)
        for(int u = 1; u <= n; u++)
            for(int v = 1; v <= n; v++)
                if (c[u][k] + c[k][v] < c[u][v]) {
                    c[u][v] = c[u][k] + c[k][v];
                    tr[u][v] = tr[u][k];
                }
    // Trace from s to t:
    if (c[s][t] == oo) cout << "No path";
    else {
        while (s != t) {
            cout << s << ' ';
            s = tr[s][t];
        }
        cout << t;
    }
}