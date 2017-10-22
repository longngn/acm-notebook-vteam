#include <set>
#include <iostream>

using namespace std;

int Dijkstra(int s, int t) {
    for(int i = 1; i <= n; i++) tr[i] = 0, d[i] = 0;
    set<pair<int, int> > h; h.insert(make_pair(0, s));
    tr[s] = -1; 
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