#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<int> ans(n + 1);

    vector<int> prefix(n);
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + (a[i - 1] == b[i - 1]);
    vector<int> postfix(n);
    for (int i = n - 2; i >= 0; i--)
        postfix[i] = postfix[i + 1] + (a[i + 1] == b[i + 1]);

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i - j < 0 || i + j >= n)
                break;
            if (a[i - j] == b[i + j])
                count++;
            if (j > 0 && (a[i + j] == b[i - j]))
                count++;
            ans[count + prefix[i - j] + postfix[i + j]]++;
        }
        count = 0;
        for (int j = 0; j < n; j++) {
            if (i - j < 0 || i + j + 1 >= n)
                break;
            if (a[i - j] == b[i + j + 1])
                count++;
            if (a[i + j + 1] == b[i - j])
                count++;
            ans[count + prefix[i - j] + postfix[i + j + 1]]++;
        }
    }

    for (int i = 0; i <= n; i++)
        cout << ans[i] << "\n";

    return 0;
}