#include <bits/stdc++.h>
using namespace std;

int n, totalTime;
int ans = INT_MAX;
pair<int, int> currentPos = { 1000, 1000 };
const unordered_map<char, pair<int, int>> directionUpdates = {
    { 'N', { 0, 1 } },
    { 'S', { 0, -1 } },
    { 'E', { 1, 0 } },
    { 'W', { -1, 0 } }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("mowing.in");
    fin >> n;

    vector<vector<int>> field(2001, vector<int>(2001, -1));
    for (int i = 0; i < n; i++) {
        char direction;
        int time;
        fin >> direction >> time;

        for (int j = 0; j < time; j++) {
            totalTime++;
            currentPos.first += directionUpdates.at(direction).first;
            currentPos.second += directionUpdates.at(direction).second;

            int& lv = field[currentPos.first][currentPos.second];
            if (lv != -1) {
                ans = min(ans, totalTime - lv);
            }
            lv = totalTime;
        }
    }

    if (ans == INT_MAX)
        ans = -1;

    ofstream fout("mowing.out");
    fout << ans << "\n";

    return 0;
}