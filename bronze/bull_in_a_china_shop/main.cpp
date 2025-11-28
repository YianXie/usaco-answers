#include <bits/stdc++.h>
using namespace std;

int n, k;
int hashCount;
vector<vector<char>> original;
vector<vector<vector<char>>> pieces;
pair<int, int> ans;

pair<int, int> getLeftCanMove(vector<vector<char>> vec)
{
    int xDiff = n;
    int yDiff = n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (vec[i][j] == '#') {
                xDiff = min(xDiff, j);
                yDiff = min(yDiff, i);
            }
        }
    }
    return { xDiff, yDiff };
}

pair<int, int> getRightCanMove(vector<vector<char>> vec)
{
    int xIdx = 0;
    int yIdx = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (vec[i][j] == '#') {
                xIdx = max(xIdx, j);
                yIdx = max(yIdx, i);
            }
        }
    }
    return { n - xIdx - 1, n - yIdx - 1 };
}

vector<vector<char>> move(vector<vector<char>> vec, int x, int y)
{
    vector<vector<char>> copy(n, vector<char>(n, '.'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (vec[i][j] == '#') {
                copy[i + y][j + x] = '#';
            }
        }
    }
    return copy;
}

bool check(vector<vector<char>> a, vector<vector<char>> b)
{
    vector<vector<char>> merged(n, vector<char>(n, '.'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == '#' && b[i][j] == '#')
                return false;
            if (a[i][j] == '#' || b[i][j] == '#')
                merged[i][j] = '#';
        }
    }
    return merged == original;
}

bool solve(vector<vector<char>> a, vector<vector<char>> b)
{
    auto preparedA = a;
    auto preparedB = b;

    auto diff1 = getLeftCanMove(a);
    auto diff2 = getLeftCanMove(b);

    // Move both shapes to the top-left corner
    preparedA = move(preparedA, -diff1.first, -diff1.second);
    preparedB = move(preparedB, -diff2.first, -diff2.second);

    diff1 = getRightCanMove(preparedA);
    diff2 = getRightCanMove(preparedB);

    // Simulate every possible way of combining
    for (int x1 = 0; x1 <= diff1.first; ++x1) {
        for (int y1 = 0; y1 <= diff1.second; ++y1) {
            auto movedA = move(preparedA, x1, y1);
            for (int l = 0; l <= diff2.first; ++l) {
                for (int m = 0; m <= diff2.second; ++m) {
                    auto movedB = move(preparedB, l, m);
                    if (check(movedA, movedB)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int countHashes(vector<vector<char>> vec)
{
    int count = 0;
    for (const auto& v : vec) {
        for (const char& c : v) {
            count += c == '#';
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("bcs.in");
    ofstream fout("bcs.out");

    fin >> n >> k;
    original.resize(n);
    pieces.resize(k);

    for (int i = 0; i < n; ++i) {
        string temp;
        fin >> temp;
        for (const char& c : temp) {
            hashCount += c == '#';
            original[i].push_back(c);
        }
    }
    for (int i = 0; i < n * k; ++i) {
        string temp;
        fin >> temp;
        pieces[i / n].push_back({});
        for (const char& c : temp)
            pieces[i / n][i % n].push_back(c);
    }

    for (int i = 0; i < k; ++i) {
        const int count1 = countHashes(pieces[i]);
        for (int j = i + 1; j < k; ++j) {
            // Skip if the sum of the hastags does not match the original
            if (count1 + countHashes(pieces[j]) != hashCount)
                continue;
            if (solve(pieces[i], pieces[j])) {
                fout << i + 1 << " " << j + 1;
                return 0;
            }
        }
    }

    return 0;
}