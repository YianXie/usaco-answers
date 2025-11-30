#include <bits/stdc++.h>
using namespace std;

int consecutive = 1;

void cntConsec(vector<int> vec)
{
    if (vec.size() <= 1) {
        return;
    } else if (vec[vec.size() - 1] > vec[vec.size() - 2]) {
        consecutive++;
        const vector<int> sub(vec.begin(), vec.end() - 1);
        cntConsec(sub);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("sleepy.in");
    ofstream fout("sleepy.out");

    int n;
    fin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        fin >> nums[i];
    }

    cntConsec(nums);

    fout << n - consecutive << "\n";
    return 0;
}