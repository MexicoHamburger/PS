#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
typedef struct
{
    int leftBorder;
    int rightBorder;
    ll value;
} node;

node arr[2100000];
ll n, m, k;
int leafStart;

void buildTree()
{
    int idx = pow(2, leafStart);
    while (idx != 1)
    {
        // leafStart = 4라면, 4,5,6,7에 대해 둘씩 쪼개서 더하고 올리고 더하고 올리고 더하고 올리고.
        int from = idx;
        int until = idx * 2;
        // printf("idx : %d, from : %d, until : %d\n", idx, from, until);
        for (int i = from; i < until; i += 2)
        {
            // Lchild의 idx는 i, Rchild의 idx는 i+1. 이것도 보장되어있음.
            // Lchild, Rchild의 부모 idx는 무조건 i/2
            // 부모 만들땐 Lchild의 Lborder, Rchild의 Rborder 합쳐주면 됨
            arr[i / 2] = {arr[i].leftBorder, arr[i + 1].rightBorder, arr[i].value + arr[i + 1].value};
            // printf("arr[%d] = {%d, %d, %d}\n", i / 2, arr[i].leftBorder, arr[i + 1].rightBorder, arr[i].value + arr[i + 1].value);
        }
        idx /= 2;
    }
}

void change(int b, ll c)
{
    // 4번째 node에 1이 있는데, 걔를 8로 바꾼다 하면?
    // leafStart = 4고, (4+4-1) = arr[7]에 저장된 값을 8로 바꾸는 것이니,
    // 변량은 7이 됨.
    // 부모로 쭉 타고가면서 변량을 더해주면 된다.
    int idx = pow(2,leafStart) + b - 1;
    ll diff = c - arr[idx].value;
    //printf("\n changing %d to %d\n", arr[idx].value, c);
    while (idx)
    {
        //printf("idx : %d, value %d to %d\n", idx, arr[idx].value, arr[idx].value+diff);
        arr[idx].value += diff;
        idx /= 2;
    }
}

ll partialSum(int b, ll c, int idx)
{
    if (b == c)
    {
        int ans = pow(2,leafStart) + b - 1;
        return (arr[ans].value);
    }
    if (arr[idx].leftBorder > c || arr[idx].rightBorder < b)
    {
        return 0;
    }
    //printf("구간 [%d-%d], idx [%d], border_at_idx [%d-%d]\n", b, c, idx, arr[idx].leftBorder, arr[idx].rightBorder);
    // 전위순회하는 탑다운이 미친듯이 편하네
    // 전위순회는 노드, 좌, 우 순서
    if (b <= arr[idx].leftBorder && arr[idx].rightBorder <= c)
    {
        //printf("RETURN %d at 구간 [%d-%d], idx [%d], border_at_idx [%d-%d]\n", arr[idx].value, b, c, idx, arr[idx].leftBorder, arr[idx].rightBorder);
        return arr[idx].value;
    }
    if ((idx * 2) < pow(2, leafStart + 1))
    {
        ll leftRet = partialSum(b, c, idx * 2);
        ll rightRet = partialSum(b, c, idx * 2 + 1);
        return (leftRet + rightRet);
    }
    return 0;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    cin >> n >> m >> k;
    for (int i = 1; i < 30; i++)
    {
        if (n == 1)
        {
            break;
        }
        int lb = pow(2, i - 1);
        int rb = pow(2, i);
        if (lb < n && n <= rb)
        {
            leafStart = i;
            break;
        }
        // n = 3,4 -> leafStart = 2
        // n = 5,6,7,8 -> leafStart = 3
    }

    ll input;

    int fin;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &input);
        int leafIdx = pow(2, leafStart) + i;
        arr[leafIdx] = {i + 1, i + 1, input};
        // printf("arr[%d] = {%d, %d, %d}\n", leafIdx, i+1, i+1, input);
        fin = i + 1;
    }
    for (int i = fin + 1; i <= pow(2, leafStart); i++)
    {
        int idx = pow(2, leafStart) + i - 1;
        arr[idx] = {i, i, 0};
        // printf("arr[%d] = {%d, %d, %d}\n", idx, i, i, 0);
    }

    buildTree();

    // 얘네는 입력상 int임
    int a, b;
    ll c;
    for (int i = 1; i <= m + k; i++)
    {
        scanf("%d %d %lld", &a, &b, &c);
        if (a == 1)
        {
            change(b, c);
        }
        else if (a == 2)
        {
            printf("%lld\n", partialSum(b, c, 1));
        }
    }
    return 0;
}