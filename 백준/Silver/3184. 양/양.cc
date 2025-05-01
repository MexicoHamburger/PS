#include <iostream>
#include <queue>

using namespace std;
typedef pair<int,int> pii;

char m[251][251] = {
    0,
};
int vis[251][251] = {
    0,
};
int r, c;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int sheep = 0;
int wolf = 0;

bool isValid(int x, int y)
{
    return (x>0 && y>0 && x<=r && y<=c);
}
void process(int i, int j)
{
    queue<pii> q;
    q.push({i,j});
    vis[i][j] = 1;

    int sheepcount = 0;
    int wolfcount = 0;
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();

        if (m[cur.first][cur.second] == 'o') {
            sheepcount++;
        }
        else if (m[cur.first][cur.second] == 'v') {
            wolfcount++;
        }
        for (int d = 0 ; d < 4 ; d++)
        {
            int nx = cur.first+dx[d];
            int ny = cur.second+dy[d];

            if (isValid(nx,ny) && m[nx][ny] != '#' && vis[nx][ny] == 0) {
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
    if (sheepcount > wolfcount) {
        sheep += sheepcount;
    } else {
        wolf += wolfcount;
    }
}
int main()
{
    cin >> r >> c;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> m[i][j];
        }
    }

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (m[i][j] != '#' && vis[i][j] == 0)
            {
                process(i, j);
            }
        }
    }
    
    cout << sheep << " " << wolf << endl;
}