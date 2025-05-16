#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 100000000
typedef pair<int,int> pii;

// {des, cost}
struct Compare {
    bool operator() (const pii& a, const pii& b) {
        return a.second > b.second;
    }
};

int main()
{
    FAST
    int n, m;
    cin >> n >> m;

    // {des, cost}
    vector<vector<pii>> graph(n+1);
    vector<int> vis(n+1, 0);
    vector<int> dist(n+1, INF);

    int src, des, val;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> src >> des >> val;
        graph[src].push_back({des, val});
    }

    int start, end;
    cin >> start >> end;

    priority_queue<pii, vector<pii>, Compare> pq;
    pq.push({start, 0});
    dist[start] = 0;

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

    cout << dist[end] << endl;
}