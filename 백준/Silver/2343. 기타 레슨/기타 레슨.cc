#include <iostream>

#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int lectures[100001] = {
    0,
};

int n, m;
int maxval = -1;
int lecsum = 0;

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> lectures[i];
        lecsum += lectures[i];
        maxval = max(maxval, lectures[i]);
    }
}

int process()
{
    int high = lecsum;
    int low = maxval;
    /*
    이진탐색으로 블루레이의 최대 크기를 잡는다.
    최대크기만큼 assign을 했는데, 블루레이 개수가 m개보다 많다면, 너무 작게 잡은거니, 블루레이 최대 크기를 늘리고.
    최대크기만큼 assign을 했는데, 블루레이 개수가 m개보다 적다면, 너무 크게 잡은거니, 블루레이 최대 크기를 줄이고.
    최대크기만큼 assign을 했는데, 블루레이 개수가 m개가 딱 나온다면, 얘보다 더 작게 잡아서 답이 나올수도 있으니 일단 최대 크기를 줄여본다.
    */

    while (low <= high)
    {
        int sum = 0;
        int cnt = 0;
        int mid = (high + low) / 2;

        for (int i = 1; i <= n; i++)
        {
            sum += lectures[i];
            if (sum > mid)
            {
                sum = lectures[i];
                cnt++;
            }
        }

        if (sum > 0)
        {
            cnt++;
        }
        if (cnt > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
int main()
{
    FAST
    input();
    cout << process() << endl;
}