#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    while (q--)
    {
        int x;
        cin >> x;

        cout << distance(lower_bound(arr.begin(), arr.end(), x), upper_bound(arr.begin(), arr.end(), x)) << '\n';
    }
    return 0;
}
