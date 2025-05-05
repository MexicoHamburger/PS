#include <iostream>

#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    FAST
    int world[501][501] = {
        0,
    };
    int h, w, a;
    cin >> h >> w;
    for (int i = 1; i <= w; i++)
    {
        cin >> a;
        for (int j = 0; j <= a; j++)
        {
            world[i][j] = 1;
        }
    }
    int ans = 0;

    for (int j = h; j >= 0; j--)
    {
        int front = -1;
        for (int i = 1; i <= w; i++)
        {
            if (world[i][j] == 1)
            {
                if (front != -1)
                {
                    // front와 i 사이의 (front,i 미포함) 모든 값을 1로 돌림
                    for (int t = front + 1; t < i; t++)
                    {
                        world[t][j] = 1;
                        ans++;
                    }
                }
                front = i;
            }
        }
    }
    cout << ans << endl;
}