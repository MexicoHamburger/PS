#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, k;
    cin >> t;
    for (int testcase = 1; testcase <= t; testcase++)
    {
        cin >> k;
        vector<int> v(k);
        for (int i = 0; i < k; i++)
        {
            cin >> v[i];
        }
        vector<vector<int>> dp(k, vector<int>(k, 0));
        vector<vector<int>> sum(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++)
        {
            sum[i][i] = v[i];
            for (int j = i + 1; j < k; j++)
            {
                sum[i][j] = sum[i][j - 1] + v[j];
            }
        }

        for (int len = 2; len <= k; len++)
        {
            for (int i = 0; i + len - 1 < k; i++)
            {
                int j = i + len - 1;
                dp[i][j] = 2147483647;
                for (int mid = i; mid < j; mid++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + sum[i][j]);
                }
            }
        }

        cout << dp[0][k - 1] << endl;
    }
}