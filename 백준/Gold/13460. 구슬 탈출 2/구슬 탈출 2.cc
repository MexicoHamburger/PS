#include <iostream>
using namespace std;

typedef pair<int, int> pii;

int n, m;
char board[11][11]= { 0,};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
// 순서대로 우, 하, 좌, 상

int moveLevel = 10000;

void input(pii* goal, pii* red, pii* blue) {
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'B') {
                *blue = make_pair(i,j);
            } else if (board[i][j] == 'R') {
                *red = make_pair(i,j);
            } else if (board[i][j] == 'O') {
                *goal = make_pair(i,j);
            }
        }
    }
}

void move(pii goal, pii red, pii blue, int level)
{
    if (level > 10) {
        return;
    }
    for (int i = 0 ; i < 4 ; i++)
    {
        bool didRedMakeIt = false;
        bool didBlueMakeIt = false;
        bool isRedFirst = true;
        if (i == 0 && red.second > blue.second) isRedFirst = true; // 오른쪽
        else if (i == 1 && red.first > blue.first) isRedFirst = true; // 아래
        else if (i == 2 && red.second < blue.second) isRedFirst = true; // 왼쪽
        else if (i == 3 && red.first < blue.first) isRedFirst = true; // 위
        else isRedFirst = false;
        
        pii redPos = red;
        pii bluePos = blue;

        if (isRedFirst) {
            while(1) {
                // since red is first, don't need to consider blue position
                int nx = redPos.first + dx[i];
                int ny = redPos.second + dy[i];
                if (board[nx][ny] == '#') {
                    break;
                }
                redPos.first += dx[i];
                redPos.second += dy[i];
                if (redPos == goal) {
                    didRedMakeIt = true;
                    break;
                }
            }
            while(1) {
                // blue need to consider red position, but also the case when red already made it.
                int nx = bluePos.first + dx[i];
                int ny = bluePos.second + dy[i];
                if (board[nx][ny] == '#') {
                    break;
                }
                bluePos.first += dx[i];
                bluePos.second += dy[i];
                if (bluePos == goal) {
                    didBlueMakeIt = true;
                    break;
                }
                if (bluePos == redPos) {
                    bluePos.first -= dx[i];
                    bluePos.second -= dy[i];
                    break;
                }
            }
        } else {
            while(1) {
                // since blue is first, don't need to consider red position
                int nx = bluePos.first + dx[i];
                int ny = bluePos.second + dy[i];
                if (board[nx][ny] == '#') {
                    break;
                }
                bluePos.first += dx[i];
                bluePos.second += dy[i];
                if (bluePos == goal) {
                    didBlueMakeIt = true;
                    break;
                }
            }
            while(1) {
                // red need to consider blue position, but not the case when blue already made it. (cause it'd be already returned)
                int nx = redPos.first + dx[i];
                int ny = redPos.second + dy[i];
                if (board[nx][ny] == '#') {
                    break;
                }
                redPos.first += dx[i];
                redPos.second += dy[i];
                if (redPos == goal) {
                    didRedMakeIt = true;
                    break;
                }
                if (redPos == bluePos) {
                    redPos.first -= dx[i];
                    redPos.second -= dy[i];
                    break;
                }
            }
        }
        if (didBlueMakeIt) {
            continue;
        }
        if (didRedMakeIt) {
            moveLevel = min(level, moveLevel);
            return;
        } else {
            move(goal, redPos, bluePos, level+1);
        }
    }
}
int main() {
    pii goal, red, blue;
    input(&goal, &red, &blue);
    move(goal, red, blue, 1);
    if (moveLevel == 10000) {
        cout << -1 << endl;
    } else {
        cout << moveLevel << endl;
    }
    return 0;
}