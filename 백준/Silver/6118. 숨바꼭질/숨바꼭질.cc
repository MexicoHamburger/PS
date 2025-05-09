#include <iostream>
#include <vector>
#include <queue>

#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 1e9
using namespace std;
typedef pair<int,int> pii;

int n, m;
int main()
{
    FAST
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<int> dist(n+1, -1);

    int from, to;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }

    int maxval = -1;
    for (int i : dist) {
        maxval = max(maxval, i);
    }
    int cnt = 0;
    int maxidx = -1;
    for (int i = 1 ; i <= n ; i++)
    {
        if (maxval == dist[i]) {
            if (maxidx == -1) {
                maxidx = i;
            }
            cnt++;
        }
    }

    cout << maxidx << " " << maxval << " " << cnt << endl;

}