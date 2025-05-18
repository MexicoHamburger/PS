#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> a;
    priority_queue<int> b;

    for (int i = 1; i <= n; i++)
    {
        int aval;
        cin >> aval;
        a.push(aval);
    }
    for (int i = 1; i <= n; i++)
    {
        int bval;
        cin >> bval;
        b.push(bval);
    }

    long long int ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        int aval = a.top(); a.pop();
        int bval = b.top(); b.pop();

        ans += aval * bval;
    }

    cout << ans << endl;
}