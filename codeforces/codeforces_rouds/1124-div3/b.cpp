#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<bool> printed(n + 1, false);
        stack<int> memory;

        for (int i = 0; i < n; ++i) {
            int document = i + 1;

            if (s[i] == '1') {
                memory.push(document);
            } else if (s[i] == '2') {
                if (!memory.empty()) {
                    printed[memory.top()] = true;
                    memory.pop();
                } else {
                    printed[document] = true;
                }
            } else { // s[i] == '3'
                printed[document] = true;
            }
        }

        vector<int> answer;

        for (int i = 1; i <= n; ++i) {
            if (!printed[i]) {
                answer.push_back(i);
            }
        }

        cout << answer.size() << '\n';

        for (int x : answer) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}
