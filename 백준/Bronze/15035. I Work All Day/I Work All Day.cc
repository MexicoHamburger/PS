#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<int> v;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        int h;
        cin >> h;
        v.push_back(h);
    }
    int t;
    cin >> t;
    int minwaste = 10000;
    int minv = -1;
    for (auto height : v)
    {
        if (minwaste > (t%height))
        {
            minwaste = t % height;
            minv = height;
        }
    }
    cout << minv << endl;
    return 0;
}