#include <bits/stdc++.h>
using namespace std;

int n, m, d, s;
unordered_set<int> badMilks;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("badmilk.in");
    fin >> n >> m >> d >> s;

    vector<tuple<int, int, int>> transcript(d);
    unordered_map<int, int> sicked;
    set<int> sicked_guests;

    for (int i = 0; i < d; i++) {
        int p, m, t;
        fin >> p >> m >> t;
        badMilks.insert(m);
        transcript[i] = make_tuple(p, m, t);
    }
    for (int i = 0; i < s; i++) {
        int p, t;
        fin >> p >> t;
        sicked[p] = t;
        sicked_guests.insert(p);
    }

    vector<int> validMilks;
    for (const int& milk : badMilks) {
        int temp = 0;
        set<int> valids;
        for (int i = 0; i < d; i++) {
            const auto& el = transcript[i];
            if (get<1>(el) != milk || get<2>(el) >= sicked[get<0>(el)])
                continue;
            valids.insert(get<0>(el));
            temp++;
        }
        if (valids == sicked_guests) {
            validMilks.push_back(milk);
        }
    }

    int ans = 0;
    for (const int& milk : validMilks) {
        unordered_set<int> distinct;
        for (int i = 0; i < d; i++) {
            const auto& el = transcript[i];
            if (get<1>(el) == milk)
                distinct.insert(get<0>(el));
        }
        ans = max<int>(ans, distinct.size());
    }

    ofstream fout("badmilk.out");
    fout << ans << "\n";

    return 0;
}
