#include <iostream>
#include <vector>
#include <queue>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1001
#define INF 1e9
using namespace std;
typedef pair<int,int> pii;

vector<pii> graph[MAX];
int dist[MAX];
int parent[MAX];
int n, m, a, b, c;

void input()
{
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
}

void dijkstra(int start){
    fill(dist, dist + MAX, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq; 

    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty())
    {
        int distance = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur] < distance) continue;
        for(int i = 0 ; i < graph[cur].size() ; i++)
        {
            int next = graph[cur][i].first;
            int newDistance = graph[cur][i].second;

            if(distance + newDistance < dist[next])
            {
                parent[next] = cur;
                dist[next] = distance + newDistance;
                pq.push({dist[next], next});
            }
        }
    }
}

void output()
{
    cout << n - 1 << endl;
    for(int i = 2 ; i <= n ; i++) 
    {
        cout << parent[i] << " " << i << endl;
    }

}

int main(){
    input();
    dijkstra(1);
    output();
    return 0;
}