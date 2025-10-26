#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");

    int k, n;
    fin >> k >> n;

    vector<vector<int>> rankings(k);

    for (int i = 0; i < k; i++) {
        rankings[i] = {};
        for (int j = 0; j < n; j++) {
            int rank;
            fin >> rank;
            rankings[i].push_back(rank);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        vector<int> contains;
        int temp = 0;
        int amount = 0;
        for (int j = 0; j < k; j++) {
            int idx = distance(rankings[j].begin(), find(rankings[j].begin(), rankings[j].end(), i));
            for (int m = idx + 1; m < n; m++) {
                contains.push_back(rankings[j][m]);
                amount++;
            }
        }
        for (int j = 1; j <= n; j++) {
            int occurrence = count(contains.begin(), contains.end(), j);
            if (occurrence == k) {
                temp++;
            }
        }
        ans += temp;
    }

    fout << ans << endl;

    fin.close();
    fout.close();

    return 0;
}