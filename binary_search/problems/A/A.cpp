#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> heights, int H)
{
    int at = distance(heights.begin(), upper_bound(heights.begin(), heights.end(), H, greater<int>()));
    return at + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, H;
    cin >> n;
    vector<int> heights(n);

    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    cin >> H;
    // sort(heights.begin(), heights.end());
    cout << solve(heights, H) << '\n';
    return 0;
}
