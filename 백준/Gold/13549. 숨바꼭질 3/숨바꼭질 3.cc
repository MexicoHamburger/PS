#include <iostream>
#include <queue>
#include <vector>

#define INF 100000000
#define N 100000

using namespace std;
typedef pair<int,int> pii;


struct Compare {
    bool operator() (const pii& a, const pii& b) {
        return a.second > b.second;
    }
};

int main()
{
    // {des, cost}
    vector<vector<pii>> graph(N+2);
    vector<int> dist(N+2, INF);

    int start, end;
    cin >> start >> end;

    graph[0].push_back({1, 1});
    for (int i = 1 ; i <= N ; i++)
    {
        graph[i].push_back({i-1, 1});
        graph[i].push_back({i+1, 1});
        if (i*2 <= N) {
            graph[i].push_back({i*2, 0});
        }
    }

    // {des, cost}
    priority_queue<pii, vector<pii>, Compare> pq;
    pq.push({start, 0});
    dist[start] = 0;

    while(!pq.empty())
    {
        pii cur = pq.top(); pq.pop();
        int u = cur.first;
        int cost = cur.second;
        if (dist[u] < cost) {
            continue;
        }

        for (pii next : graph[u]) {
            int v = next.first;
            int w = next.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        }
    }

    cout << dist[end] << endl;
}