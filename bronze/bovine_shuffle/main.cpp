#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("shuffle.in");
    fin >> n;

    vector<int> pos(n);
    vector<int> id(n);

    for (int i = 0; i < n; i++)
        fin >> pos[i];
    for (int i = 0; i < n; i++)
        fin >> id[i];

    for (int i = 0; i < 3; i++) {
        vector<int> temp = id;
        for (int j = 0; j < n; j++) {
            id[j] = temp[pos[j] - 1];
        }
    }

    ofstream fout("shuffle.out");
    for (const int& i : id) {
        fout << i << "\n";
    }

    return 0;
}