#include <iostream>
#include <cstring>
#include <queue>
#define INF 100000000
using namespace std;

typedef pair<int,int> pii;
/*
특정 위치 a를 이동하는 최소시간은,
min(a-1, a+1, a/2) + 1임.
풀어보자.
*/

int visit[100001];
int main()
{
    memset(visit, -1, sizeof(visit));
    int n, k;
    cin >> n >> k;

    queue<pii> q;
    q.push({n,0});
    // you can access to n at time 0.
    visit[n] = 0;
    int curKtime = INF;
    int cnt = 0;

    while(!q.empty())
    {
        int curPos = q.front().first;
        int curTime = q.front().second;
        visit[curPos] = 0;

        q.pop();
        if (curTime > curKtime) continue;

        if (curPos == k) {
            if (curTime < curKtime) {
                curKtime = curTime;
                cnt = 1;
            }
            else if (curTime == curKtime) {
                cnt++;
            }
        }
        else {
            for (int next : {curPos - 1, curPos + 1, curPos * 2}) {
                if (next < 0 || next > 100000) continue;
                if (visit[next] == -1 || visit[next] >= curTime + 1) {
                    visit[next] = curTime + 1;
                    q.push({next, curTime + 1});
                }
            }
        }
    }
    cout << curKtime << endl;
    cout << cnt << endl;
}