#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pii;
#define INF 2147483647

// pq에 {cost, dest} 순서로 넣자
struct Compare {
    bool operator()(const pii& a, const pii& b) {
        return a.first > b.first;
    }
};

int main()
{
    int n, m, k, start;
    cin >> n >> m >> k >> start;

    vector<vector<int>> graph(n+1);

    int src, des;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> src >> des;
        graph[src].push_back(des);
    }

    vector<int> dist(n+1, INF);
    vector<int> vis(n+1, 0);
    priority_queue<pii, vector<pii>, Compare> pq;
    dist[start] = 0;

    pq.push({0, start});
    while (!pq.empty())
    {
        pii cur = pq.top(); pq.pop();
        int cost = cur.first;
        int u = cur.second;

        if (vis[u]) {
            continue;
        }
        vis[u] = 1;

        for (auto v : graph[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                pq.push({dist[v], v});
            }
        }
    }
    bool flag = false;
    for (int i = 1 ; i <= n ; i++) {
        if (dist[i] == k) {
            cout << i << endl;
            flag = true;
        }
    }
    if (!flag) {
        cout << "-1" << endl;
    }
}