#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> cows = { "Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue" };
vector<pair<string, string>> constraints;

bool isValid(vector<string> cows)
{
    for (const auto& constraint : constraints) {
        string cow1 = constraint.first;
        string cow2 = constraint.second;
        for (int i = 0; i < cows.size(); ++i) {
            const int plus1 = max(i - 1, 0);
            const int minus1 = min(i + 1, static_cast<int>(cows.size()) - 1);
            if (cows[i] == cow1) {
                if (cows[minus1] != cow2 && cows[plus1] != cow2) {
                    return false;
                }
            } else if (cows[i] == cow2) {
                if (cows[minus1] != cow1 && cows[plus1] != cow1) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("lineup.in");
    ofstream fout("lineup.out");

    fin >> n;

    for (int i = 0; i < n; ++i) {
        string cow1, cow2;
        string _1, _2, _3, _4;
        fin >> cow1 >> _1 >> _2 >> _3 >> _4 >> cow2;
        constraints.push_back({ cow1, cow2 });
    }

    sort(cows.begin(), cows.end());
    do {
        if (isValid(cows)) {
            for (const string& cow : cows) {
                fout << cow << "\n";
            }
            break;
        }
    } while (next_permutation(cows.begin(), cows.end()));

    return 0;
}