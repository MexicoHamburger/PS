#include <iostream>
using namespace std;
int N, M, K;
bool trash[102][102] = { false, };
bool visited[102][102] = { false, };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int maxsize = 0;
int s = 0;

void DFS(int x, int y) {
    visited[x][y] = true;
    s++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || ny < 1 || nx > N || ny > M)
            continue;
        if (visited[nx][ny] == false && trash[nx][ny] == true) {
            DFS(nx, ny);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    int r, c;
    for (int i = 0; i < K; i++) {
        cin >> r >> c;
        trash[r][c] = true;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (trash[i][j] == true && visited[i][j] == false) {
                s = 0;
                DFS(i, j);
                if (maxsize < s) {
                    maxsize = s;
                }
            }
        }
    }
    cout << maxsize << "\n";

    return 0;
}