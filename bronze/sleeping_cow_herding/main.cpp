#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ifstream fin("herding.in");
    ofstream fout("herding.out");

    vector<int> cows(3);
    fin >> cows[0] >> cows[1] >> cows[2];
    sort(cows.begin(), cows.end());

    if (cows[0] == cows[1] - 1 && cows[0] == cows[2] - 2 && cows[1] == cows[2] - 1) {
        // Already at the correct position
        fout << 0 << "\n"
             << 0 << "\n";
    } else if (cows[2] - cows[1] == 2 || cows[1] - cows[0] == 2) {
        // Two cows are 1 unit away from each other
        fout << 1 << "\n"
             << max(cows[2] - cows[1], cows[1] - cows[0]) - 1 << "\n";
    } else {
        // None of the above
        fout << 2 << "\n"
             << max(cows[2] - cows[1], cows[1] - cows[0]) - 1 << "\n";
    }

    return 0;
}