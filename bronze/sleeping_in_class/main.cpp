#include <bits/stdc++.h>
using namespace std;

int t;

vector<int> findFactors(int num)
{
    vector<int> factors;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            factors.push_back(i);
            if (i * i != num) {
                factors.push_back(num / i);
            }
        }
    }
    sort(factors.begin(), factors.end(), greater<int>());
    return factors;
}

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;

    int sq = sqrt(num);
    for (int i = 3; i <= sq; i += 2) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void solve(vector<int> arr)
{
    const int n = arr.size();

    // If all numbers are the same
    set<int> temp(arr.begin(), arr.end());
    if (temp.size() == 1 || n == 1) {
        cout << 0 << endl;
        return;
    }

    // If the sum if a prime number (meaning there is no way to divide equally)
    const int sum = accumulate(arr.begin(), arr.end(), 0);
    if (isPrime(sum)) {
        cout << n - 1 << endl;
        return;
    }

    int maxValue = *max_element(arr.begin(), arr.end());
    int ans = INT_MAX;
    for (const int& i : findFactors(sum)) {
        // `i` refers to the size of a single target number
        if (i < maxValue)
            break;

        int subSum = 0, steps = 0, prevIdx = 0;
        bool possible = true;
        for (int j = 0; j < n; j++) {
            subSum += arr[j];
            if (subSum == i) {
                subSum = 0;
                steps += j - prevIdx;
                prevIdx = j + 1;
            } else if (subSum > i) {
                possible = false;
                break;
            }
        }
        if (steps != 0 && possible)
            ans = min(ans, steps);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> num(n);
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        solve(num);
    }

    return 0;
}