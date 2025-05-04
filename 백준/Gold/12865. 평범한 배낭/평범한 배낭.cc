#include <iostream>
#include <vector>
using namespace std;

int n, k;
int main()
{
    cin >> n >> k;
    vector<int> W(n + 1), V(n + 1);
    vector<int> dp(k+1, 0);
    // dp[a] = 무게a까지 담았을 때의 최대 가치

    for (int i = 0; i < n; i++)
    {
        cin >> W[i] >> V[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = k; j >= W[i]; j--) {
            dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
        }
    }

    cout << dp[k] << "\n";
}