#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
/*
벽을 세울 수 있는 경우의수는 최대 64*64*64 = 260,000
26만개의 경우의 수에 대해 세우고 흩기, 세우고 흩기 하면 됨됨 
*/

int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int area_origin[9][9] = {
    0,
};
int area_cpy[9][9] = {0,};

int maxArea = -1;

vector<pii> two_q;
vector<pii> zero_v;

void input(int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> area_origin[i][j];
            if (area_origin[i][j] == 2) {
                two_q.push_back(make_pair(i, j));
            } else if (area_origin[i][j] == 0) {
                zero_v.push_back(make_pair(i,j));
            }
        }
    }
}

void dfs(pii virus) {
    for (int i = 0 ; i < 4 ; i++)
    {
        int nx = virus.first + dx[i];
        int ny = virus.second + dy[i];

        if (nx >= 1 && ny >= 1 && nx <= n && ny <= m)
        {
            if (area_cpy[nx][ny] == 0) {
                area_cpy[nx][ny] = 2;
                dfs(make_pair(nx, ny));
            }
        }
    }
}

void make_wall_and_query(pii c1, pii c2, pii c3) {
    memcpy(area_cpy, area_origin, sizeof(area_origin));

    area_cpy[c1.first][c1.second] = 1;
    area_cpy[c2.first][c2.second] = 1;
    area_cpy[c3.first][c3.second] = 1;

    for (int i = 0 ; i < two_q.size() ; i++)
    {
        dfs(two_q[i]);
    }
}

void update_safe_area()
{
    int cnt = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            if (area_cpy[i][j] == 0) {
                cnt++;
            }
        }
    }
    maxArea = maxArea > cnt ? maxArea : cnt;
}

void search()
{
    for (int i = 0 ; i < zero_v.size() ; i++)
    {
        for (int j = i+1 ; j < zero_v.size() ; j++)
        {
            for (int k = j+1 ; k < zero_v.size() ; k++)
            {
                make_wall_and_query(zero_v[i], zero_v[j], zero_v[k]);
                update_safe_area();
            }
        }
    }
}

void answer()
{
    cout << maxArea << endl;
}

int main()
{
    cin >> n >> m;
    input(n, m);
    search();
    answer();
}