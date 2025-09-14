#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    int freq[26] = {0};

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        q.push(ch);
        freq[ch - 'a']++;

        while (!q.empty()) {
            if (freq[q.front() - 'a'] > 1) {
                q.pop();
            } else {
                cout << q.front() << " ";
                break;
            }
        }
        if (q.empty()) {
            cout << -1 << " ";
        }
    }
    cout << endl;
}

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;

    cout << "First non-repeating characters at each step:\n";
    firstNonRepeating(str);

    return 0;
}
