#include <iostream>

using namespace std;

int main()
{
    int t, a, b;
    cin >> t;
    for (int i = 1 ; i <= t ; i++)
    {
        cin >> a >> b;
        int result = 1;

        a %= 10;
        while (b > 0) {
            if (b%2 == 1) {
                result = (result*a) % 10;
            }
            a = (a*a) % 10;
            b /= 2;
        }
        
        if (result == 0) result = 10;
        cout << result << endl;
    }
}