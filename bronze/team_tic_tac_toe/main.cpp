#include <bits/stdc++.h>
using namespace std;

const int n = 3;
int ans;
vector<vector<char>> board(n, vector<char>(n));
vector<char> letters;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("tttt.in");
    for (int i = 0; i < n; i++) {
        string row;
        fin >> row;
        for (int j = 0; j < n; j++) {
            board[i][j] = row.at(j);
            letters.push_back(row.at(j));
        }
    }

    // Remove duplicate letters
    sort(letters.begin(), letters.end());
    auto last = unique(letters.begin(), letters.end());
    letters.erase(last, letters.end());

    // Check for single-team
    // Check for horizontal/vertical
    for (const char& c : letters) {
        int temp = 0;
        for (int k = 0; k < n; k++) {
            unordered_set<char> horSet;
            unordered_set<char> verSet;
            for (int m = 0; m < n; m++) {
                horSet.insert(board[k][m]);
                verSet.insert(board[m][k]);
            }
            temp += horSet.size() == 1 && horSet.count(c);
            temp += verSet.size() == 1 && verSet.count(c);
        }

        // Check for diagonals
        unordered_set<char> diagSet1;
        unordered_set<char> diagSet2;
        for (int k = 0; k < n; k++) {
            diagSet1.insert(board[k][k]);
            diagSet2.insert(board[k][n - k - 1]);
        }
        temp += diagSet1.size() == 1 && diagSet1.count(c);
        temp += diagSet2.size() == 1 && diagSet2.count(c);
        ans += !!temp;
    }

    ofstream fout("tttt.out");
    fout << ans << "\n";

    // Reset the answer counter
    ans = 0;

    // Check for double-team
    for (int i = 0; i < letters.size(); i++) {
        for (int j = i + 1; j < letters.size(); j++) {
            const char c1 = letters[i];
            const char c2 = letters[j];
            int temp = 0;
            for (int k = 0; k < n; k++) {
                unordered_set<char> horSet;
                unordered_set<char> verSet;
                for (int m = 0; m < n; m++) {
                    horSet.insert(board[k][m]);
                    verSet.insert(board[m][k]);
                }
                temp += horSet.size() == 2 && horSet.count(c1) && horSet.count(c2);
                temp += verSet.size() == 2 && verSet.count(c1) && verSet.count(c2);
            }

            // Check for diagonals
            unordered_set<char> diagSet1;
            unordered_set<char> diagSet2;
            for (int k = 0; k < n; k++) {
                diagSet1.insert(board[k][k]);
                diagSet2.insert(board[k][n - k - 1]);
            }
            temp += diagSet1.size() == 2 && diagSet1.count(c1) && diagSet1.count(c2);
            temp += diagSet2.size() == 2 && diagSet2.count(c1) && diagSet2.count(c2);
            ans += !!temp;
        }
    }

    fout << ans << "\n";

    return 0;
}