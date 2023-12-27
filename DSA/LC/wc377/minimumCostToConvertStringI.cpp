#include<bits/stdc++.h>
using namespace std;

#define INF 1000000000

vector<int> dijkstra(vector<pair<int, int>> adj[], int src, int V) {
    priority_queue< pair<int, int>, vector <pair<int, int>> , greater<> > pq;
    vector<int> dist(V, INF);
    pq.emplace(0, src);
    dist[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto &x : adj[u]) {
            int v = x.first, weight = x.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

long long minimumCost(string &source, string &target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    int V = 26;
    vector<pair<int, int>> adj[V];
    for (int i = 0; i < original.size(); ++i) {
        adj[original[i] - 'a'].emplace_back(changed[i] - 'a', cost[i]);
    }
    vector<int> min_distances[V];
    for (int i = 0; i < V; ++i) {
        min_distances[i] = dijkstra(adj, i, V);
    }
    long long minimum_cost = 0;
    for (int i = 0; i < source.size(); ++i) {
        if (min_distances[source[i] - 'a'][target[i] - 'a'] == INF) {
            return -1;
        }
        minimum_cost += min_distances[source[i] - 'a'][target[i] - 'a'];
    }
    return minimum_cost;
}

int main() {
    string source = "abcd", target = "acbe";
    vector<char> original = {'a', 'b', 'c', 'c', 'e', 'd'}, changed = {'b', 'c', 'b', 'e', 'b', 'e'};
    vector<int> cost = {2, 5, 5, 1, 2, 20};
    cout << "The minimum cost is: " << minimumCost(source, target, original, changed, cost) << endl;
    return 0;
}
