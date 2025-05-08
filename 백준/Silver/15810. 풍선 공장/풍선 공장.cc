#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
/*
a, b, c면 답이 n일때 n/a + n/b + n/c = m이 성립하면 됨.
스탭이 1명일 때, 하나 부는데 1백만 걸리고 1백만개의 풍선을 요구받으면 정답은 최대 1천억이니까, long long까지 넘어간다.

*/
int n, m;
int main()
{
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0 ; i < n ; i++)
    {
        cin >> v[i];
    }

    ll low = 1;
    ll high = 1e12;
    ll ans = low;
    while (low <= high)
    {
        ll mid = (low + high)/2;
        ll sum = 0;
        for (auto i : v) {
            sum += mid / i;
        }
        if (sum >= m) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    cout << ans << endl;
}