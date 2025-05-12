#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

long long dist2(pii a, pii b) {
    long long dx = a.first - b.first;
    long long dy = a.second - b.second;
    return dx * dx + dy * dy;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int z;
        cin >> z;
        vector<pii> animals(z);
        for (int i = 0; i < z; ++i) {
            cin >> animals[i].first >> animals[i].second;
        }

        long long min_dist = 1LL << 62;
        pair<pii, pii> best_pair;

        for (int i = 0; i < z; ++i) {
            for (int j = i + 1; j < z; ++j) {
                long long d = dist2(animals[i], animals[j]);

                pii a = animals[i], b = animals[j];
                if (a > b) swap(a, b);

                if (d < min_dist) {
                    min_dist = d;
                    best_pair = {a, b};
                } else if (d == min_dist) {
                    if (make_pair(a, b) < best_pair) {
                        best_pair = {a, b};
                    }
                }
            }
        }

        cout << best_pair.first.first << " " << best_pair.first.second << " ";
        cout << best_pair.second.first << " " << best_pair.second.second << "\n";
    }

    return 0;
}
