#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");

    int n;
    fin >> n;

    vector<int> time(1000);
    vector<pair<int, int>> coords(n);
    for (int i = 0; i < n; ++i) {
        int start, end;
        fin >> start >> end;
        coords[i] = { start, end };
        for (int j = start; j < end; ++j) {
            ++time[j];
        }
    }

    int ans = 0;
    for (auto pair : coords) {
        int start = pair.first;
        int end = pair.second;
        vector<int> temp = time;
        for (int j = start; j < end; ++j) {
            --temp[j];
        }

        int zeros = count(temp.begin(), temp.end(), 0);
        ans = max(1000 - zeros, ans);
    }

    fout << ans << endl;

    return 0;
}