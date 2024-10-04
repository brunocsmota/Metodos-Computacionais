/******************************************************************************

                         Algoritmo de Dijkstra

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
};

void dijkstra(vector<vector<Edge>> graph, int start, vector<int>& dist) {
    int n = graph.size();
    dist.assign(n, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto&edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    // Matriz de adjacência representando o grafo
    vector<vector<Edge>> graph = {
        {{1, 32}, {1, 21}, {2, 29}},
        {},
        {{5, 60}},
        {{4, 34}, {5, 18}},
        {{5, 40}, {6, 51}, {7, 46}},
        {},
        {{7, 25}},
        {}
    };

    int start = 1;  // Nó de partida
    int end = 3;  // Nó de destino
    int n = graph.size();
    vector<int> dist(n);

    dijkstra(graph, start, dist);

    cout << "A menor distância de " << start << " para " << end << " é: " << dist[end] << endl;

    return 0;
}