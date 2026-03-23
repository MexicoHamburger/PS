#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

/*
우선 A~Z까지 모든 알파벳이 다 나올 수 있다는 점을 염두.
그렇게 계산하면, A~Z까지 랜덤한 가중치를 부여해서 Brute Forcing하는 건 아예 말도안되는 똥소리라는 결론이 나옴

근데 어떤 생각을 해볼 수 있냐?
xxABC
BJADP

이 둘을 더하면? 뭐가 더 높겠음?
B랑 J에 높은 숫자 들어가는게 무조건 이득임

~~하면 ~~하는게 이득임 << 이 구조 나온 순간 걍 Greedy임 거의 90% 확률로 Greedy였음
즉, 접근 방법을 '각 알파벳별로 가능할만한 숫자를 미리 지정'해두고 계산하는 게 아니라
가중치가 높은 알파벳들한테 가장 높은 숫자를 부여하는 알고리즘을 짜면 됨
그리고 그 가중치는 젤 끝에 있는 놈한테 1, 그 다음 놈은 10, 그 다음 놈은 100.. 이렇게 주면서 진행하면 됨

*/
int main() {
	FAST
    int n;
    string st;
    vector<int> alphabet(26, 0);
    cin >> n;
    for (int i = 1; i <= n; i++)
	{
        cin >> st;
        
        int weight = 1;
        for (int j = st.length() - 1; j >= 0; j--) {
            alphabet[st[j] - 'A'] += weight;
            weight *= 10;
        }
    }
	/*
	AABP면, alphabet[15] = 1, alphabet[1] = 10, alphabet[0] = 100, alphabet[0] = 100 + 1000 이니,
	{1100, 10, 1, 0, 0, ...}로 정렬될 것.
	*/
    sort(alphabet.rbegin(), alphabet.rend());

    int result = 0;
    int num = 9;
	
	/*
	AABP면,
	idx 0부터 sort된 알파벳배열에 대해 9900 + 80 + 7 이라서 9987이 되는 것임.
	*/
    for (int i = 0; i < 10; i++)
	{
        if (alphabet[i] == 0) break;
        result += alphabet[i] * num;
        num--;
    }

    cout << result << "\n";

    return 0;
}