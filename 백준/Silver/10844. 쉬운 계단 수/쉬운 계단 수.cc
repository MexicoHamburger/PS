#include <iostream>
#include <vector>

#define MOD 1000000000
typedef long long ll;
using namespace std;

int main()
{
    int n;
    cin >> n;

    // dp[i][j] = 길이가 i고, 끝이 j인 계단수의 개수
    ll dp[101][10] = {
        0,
    };

    dp[1][0] = 0;
    for (int i = 1; i <= 9; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j + 1];
            }
            else if (j == 9)
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        ans += dp[n][i];
        ans = ans % MOD;
    }

    cout << ans << endl;
}