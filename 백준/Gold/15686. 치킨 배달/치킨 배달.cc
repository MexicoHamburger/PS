#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n, m;

typedef pair<int, int> pii;
int city[51][51] = {
    0,
};

vector<pii> chicken;
vector<pii> home;
vector<int> numvec;
vector<int> combvec;

struct Compare {
    bool operator()(const pair<pii, int>& a, const pair<pii, int>& b)
    {
        return a.second > b.second;
    }
};

void input(int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> city[i][j];
            if (city[i][j] == 1)
            {
                home.push_back(make_pair(i, j));
            }
            else if (city[i][j] == 2)
            {
                chicken.push_back(make_pair(i, j));
            }
        }
    }
}

void init()
{
    for (int i = 0 ; i < m ; i++) {
        numvec.push_back(i);
    }

    for (int i = 0 ; i < chicken.size() - m ; i++) {
        combvec.push_back(0);
    }
    for (int i = 0 ; i < m ; i++) {
        combvec.push_back(1);
    }
}

void calc()
{
    int minChickenScore = 2147483647;
    do {
        vector<pii> famous_chickens;
        int chickenScoreSum = 0;
        for (int i = 0 ; i < combvec.size() ; i++) {
            if (combvec[i]) {
                famous_chickens.push_back(chicken[i]);
            }
        }
        
        for (int i = 0 ; i < home.size() ; i++) {
            int currentHomeMinScore = 2147483647;
            pii currentHome = home[i];
            for (int j = 0 ; j < famous_chickens.size(); j ++) {
                int chickenScore = abs(currentHome.first - famous_chickens[j].first) + abs(currentHome.second - famous_chickens[j].second);
                currentHomeMinScore = currentHomeMinScore < chickenScore ? currentHomeMinScore : chickenScore;
            }
            chickenScoreSum += currentHomeMinScore;
        }
        minChickenScore = minChickenScore < chickenScoreSum ? minChickenScore : chickenScoreSum;
    } while (next_permutation(combvec.begin(), combvec.end()));

    cout << minChickenScore << endl;
}
int main()
{
    cin >> n >> m;
    input(n, m);
    init();
    calc();
}