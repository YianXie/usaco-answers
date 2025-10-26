#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> flowers(n);
    for (int i = 0; i < n; i++) {
        cin >> flowers[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = accumulate(flowers.begin() + i, flowers.begin() + j + 1, 0);
            if (sum % (j - i + 1) != 0) continue;

            int average = sum / (j - i + 1);
            int it = count(flowers.begin() + i, flowers.begin() + j + 1, average);
            if (it > 0) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
