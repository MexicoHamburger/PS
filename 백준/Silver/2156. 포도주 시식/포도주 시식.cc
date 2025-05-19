#include <iostream>
#include <vector>
#include <algorithm>

#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

/*
dp[k][0] = k번째 원소까지의 최댓값. 이때, k번째 원소는 미포함
dp[k][1] = k번째 원소까지의 최댓값. 이때, k번째 원소는 '연속체'의 1번째 원소
dp[k][2] = k번째 원소까지의 최댓값. 이때, k번째 원소는 '연속체'의 2번째 원소

dp[1][0] = 0                    dp[1][1] = 6                        dp[1][2] = 0
dp[2][0] = 6 (max(dp[1]))       dp[2][1] = dp[1][0]+v[2] = 10       dp[2][2] = dp[1][1] + v[2] = 16
dp[3][0] = 16 (max(dp[2]))      dp[3][1] = dp[2][0]+v[3] = 19       dp[3][2] = dp[2][1] + v[3] = 23
*/
int main()
{
    FAST
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(3));

    dp[1][0] = 0;
    dp[1][1] = v[1];
    dp[1][2] = 0;

    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        dp[i][1] = dp[i - 1][0] + v[i];
        dp[i][2] = dp[i - 1][1] + v[i];
    }
    int ans = max({dp[n][0], dp[n][1], dp[n][2]});
    cout << ans << endl;
}