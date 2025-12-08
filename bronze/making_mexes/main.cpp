#include <bits/stdc++.h>
using namespace std;

int binarySearch(const std::vector<int>& arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    unordered_map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums[i] = num;
        freq[num]++;
    }
    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());
    sortedNums.erase(unique(sortedNums.begin(), sortedNums.end()), sortedNums.end());

    for (int i = 0; i <= n; ++i) {
        int searchValue = i - 1;
        int idx = 0;
        while (searchValue >= 0) {
            idx = binarySearch(sortedNums, searchValue);
            if (idx >= 0)
                break;
            searchValue--;
        }
        cout << max(i - idx - 1, freq[i]) << endl;
    }

    return 0;
}