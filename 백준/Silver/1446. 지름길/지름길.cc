#include <iostream>
#include <vector>
#include <queue>

#define INF 2147483647
using namespace std;
typedef pair<int,int> pii;

struct Compare {
    bool operator()(const pii& a, const pii& b) {
        return a.second > b.second;
    }
};

int main()
{
    int n, d;
    vector<int> dist(10002, INF);
    vector<int> vis(10002, 0);
    cin >> n >> d;

    // {dest, cost}
    vector<vector<pii>> graph(10002);
    for (int i = 0 ; i < 10000 ; i++) {
        graph[i].push_back({i+1, 1});
    }

    int src, des, len;
    for (int i = 1 ; i <= n ; i++) {
        cin >> src >> des >> len;
        graph[src].push_back({des, len});
    }

    dist[0] = 0;
    priority_queue<pii, vector<pii>, Compare> pq;
    
    pq.push({0, 0});
    while (!pq.empty())
    {
        pii cur = pq.top(); pq.pop();
        int u = cur.first;
        int cost = cur.second;

        if (vis[u]) {
            continue;
        }
        vis[u] = 1;

        for (int i = 0 ; i < graph[u].size() ; i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        }
    }

    cout << dist[d] << endl;
}