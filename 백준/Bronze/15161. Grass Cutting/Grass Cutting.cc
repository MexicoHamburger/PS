#include <iostream>

using namespace std;

int grass[11][11] = {
    0,
};

void init()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            grass[i][j] = 1;
        }
    }
}

void grow()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            grass[i][j] += 1;
        }
    }
}

void mow(int r1, int r2, int r3, int c1, int c2, int c3)
{
    for (int j = 1; j <= 10; j++)
    {
        grass[r1][j] = 1;
        grass[r2][j] = 1;
        grass[r3][j] = 1;
    }
    for (int i = 1; i <= 10; i++)
    {
        grass[i][c1] = 1;
        grass[i][c2] = 1;
        grass[i][c3] = 1;
    }
}

void print()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cout << grass[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    init();
    int k;
    cin >> k;

    int r1, r2, r3, c1, c2, c3;
    for (int i = 1; i <= k; i++)
    {
        cin >> r1 >> r2 >> r3 >> c1 >> c2 >> c3;
        grow();
        mow(r1, r2, r3, c1, c2, c3);
    }
    print();
    return 0;
}