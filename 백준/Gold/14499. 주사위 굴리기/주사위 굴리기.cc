#include <iostream>
using namespace std;

#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef pair<int, int> pii;

int n, m, x, y, k;
int dice[7] = {0,};

int board[21][21] = {0,};
int moves[1001] = {0,};

/*
아랫면, 앞면, 오른면, 뒷면, 왼면, 윗면이 있다.

1. 남쪽
오른면/왼면은 그대로
아랫면 -> 뒷면 -> 윗면 -> 앞면 -> 아랫면

2. 북쪽
오른면/왼면은 그대로
아랫면 -> 앞면 -> 윗면 -> 뒷면 -> 아랫면

3. 동쪽
앞면/뒷면은 그대로
아랫면 -> 왼면 -> 윗면 -> 오른면 -> 아랫면

4. 서쪽
앞면/뒷면은 그대로
아랫면 -> 오른면 -> 윗면 -> 왼면 -> 아랫면

*/
int main() {
    FAST
    cin >> n >> m >> x >> y >> k;

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1 ; i <= k ; i++) {
        cin >> moves[i];
    }

    pii diceLoc = {x+1,y+1};
    for (int i = 1 ; i <= k ; i++) {
        if (moves[i] == 1)
        { // 동
            if (diceLoc.second + 1 > m) {
                continue;
            }
            diceLoc.second += 1;
            
            int down = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[5];
            dice[5] = down;
        }
        else if (moves[i] == 2)
        { // 서
            if (diceLoc.second - 1 < 1) {
                continue;
            }
            diceLoc.second -= 1;

            int down = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[3];
            dice[3] = down;
        }
        else if (moves[i] == 3)
        { // 북
            if (diceLoc.first - 1 < 1) {
                continue;
            }
            diceLoc.first -= 1;

            int down = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[2];
            dice[2] = down;
        }
        else if (moves[i] == 4)
        { // 남
            if (diceLoc.first + 1 > n) {
                continue;
            }
            diceLoc.first += 1;

            int down = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[4];
            dice[4] = down;
        }

        if(board[diceLoc.first][diceLoc.second] == 0) {
            board[diceLoc.first][diceLoc.second] = dice[1];
        } else {
            dice[1] = board[diceLoc.first][diceLoc.second];
            board[diceLoc.first][diceLoc.second] = 0;
        }
        cout << dice[6] << endl;
    }
    return 0;
}