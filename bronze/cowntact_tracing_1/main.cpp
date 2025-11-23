#include <bits/stdc++.h>
using namespace std;

int n, t;
vector<int> results;
vector<tuple<int, int, int>> contacts;

unordered_set<int> validZeros;
int k_m = 250 + 1;
int k_M = 0;

bool simulate(vector<int> arr, int k)
{
    unordered_map<int, int> cowRecord;
    vector<int> lastContact(n, -1);
    vector<int> lastContactExceeded(n, -1);
    bool exceeded = false;

    for (int i = 0; i < t; ++i) {
        const auto& contact = contacts[i];
        const int& c1Idx = get<1>(contact) - 1;
        const int& c2Idx = get<2>(contact) - 1;
        int& c1 = arr[c1Idx];
        int& c2 = arr[c2Idx];

        cowRecord[c1Idx] += c1 == 1;
        cowRecord[c2Idx] += c2 == 1;

        if (c1 == 1 && c2 == 0) {
            lastContact[c2Idx] = c1Idx;
            if (cowRecord[c1Idx] > k) {
                lastContactExceeded[c2Idx] = c1Idx;
                continue;
            }
        } else if (c1 == 0 && c2 == 1) {
            lastContact[c1Idx] = c2Idx;
            if (cowRecord[c2Idx] > k) {
                lastContactExceeded[c1Idx] = c2Idx;
                continue;
            }
        }

        if (c1 == 1 && cowRecord[c1Idx] <= k)
            c2 = 1;
        else if (c2 == 1 && cowRecord[c2Idx] <= k)
            c1 = 1;
    }

    for (int i = 0; i < n; ++i) {
        if (lastContact[i] == -1 || lastContactExceeded[i] == -1)
            continue;
        if (lastContact[i] == lastContactExceeded[i]) {
            exceeded = true;
            break;
        }
    }

    if (arr == results) {
        k_m = min(k_m, k);
        k_M = exceeded ? max(k_M, k) : 250 + 1;
        return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("tracing.in");
    ofstream fout("tracing.out");

    string tempS;

    fin >> n >> t;
    fin >> tempS;

    for (const char& c : tempS)
        results.push_back(c - '0');

    for (int i = 0; i < t; ++i) {
        contacts.push_back(make_tuple(0, 0, 0));
        fin >> get<0>(contacts[i]) >> get<1>(contacts[i]) >> get<2>(contacts[i]);
    }

    // Sort the contacts based on time
    sort(contacts.begin(), contacts.end());

    // Handle edge cases (K_m = 0)
    long countOne = count(results.begin(), results.end(), 1);
    if (countOne == 1) {
        fout << 1 << " " << 0 << " " << 0;
        return 0;
    }

    // Iterate all possible values of k and search for patient-zeros
    for (int i = 0; i < n; ++i) {
        if (results[i] == 0)
            continue;

        vector<int> arr(n, 0);
        arr[i] = 1;
        for (int k = 0; k <= t; ++k) {
            if (simulate(arr, k)) {
                validZeros.insert(i);
            }
        }
    }

    fout << validZeros.size() << " " << k_m << " ";
    if (k_M == 250 + 1)
        fout << "Infinity";
    else
        fout << k_M;

    return 0;
}