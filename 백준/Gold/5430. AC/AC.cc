#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++)
    {
        string cmd;
        int n;

        cin >> cmd;
        cin >> n;
        deque<int> dq;
        string arr_input;
        cin >> arr_input;

        string num;
        for (char ch : arr_input) {
            if (isdigit(ch)) {
                num += ch;
            } else if (!num.empty()) {
                dq.push_back(stoi(num));
                num.clear();
            }
        }

        bool isReversed = false;
        bool hasError = false;
        for (int i = 0; i < cmd.size(); i++)
        {
            char curCmd = cmd[i];
            if (cmd[i] == 'R')
            {
                isReversed = !isReversed;
            }
            if (cmd[i] == 'D')
            {
                if (dq.empty())
                {
                    cout << "error" << endl;
                    hasError = true;
                    break;
                }
                else
                {
                    if (isReversed) {
                        dq.pop_back();
                    } else {
                        dq.pop_front();
                    }
                }
            }
        }
        if (hasError) {
            continue;
        }
        if (dq.size() == 0) {
            cout << "[]" << endl;
            continue;
        }
        cout << "[";
        if (!isReversed) {
            for (int i = 0 ; i < dq.size() ; i++) {
                if (i == dq.size()-1) {
                    cout << dq[i];
                    break;
                }
                cout << dq[i] << ",";
            }
        }
        else {
            for (int i = dq.size()-1 ; i >= 0 ; i--) {
                if (i == 0) {
                    cout << dq[i];
                    break;
                }
                cout << dq[i] << ",";
            }
        }
        cout << "]" << endl;
    }
}
