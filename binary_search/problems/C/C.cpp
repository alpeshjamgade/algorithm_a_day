#include <bits/stdc++.h>

using namespace std;

int upper_bound(vector<int> arr, int left, int right, int value)
{
    if (left < right)
    {
        int mid = left - (left - right) / 2;
        int middle_elem = arr[mid];

        if (middle_elem <= value)
        {
            return upper_bound(arr, mid + 1, right, value);
        }
        else
        {
            return upper_bound(arr, left, mid, value);
        }
    }
    else
    {
        return left;
    }
}

int lower_bound(vector<int> arr, int left, int right, int value)
{
    if (left < right)
    {
        int mid = left - (left - right) / 2;
        int middle_elem = arr[mid];

        if (middle_elem >= value)
        {
            return lower_bound(arr, left, mid, value);
        }
        else
        {
            return lower_bound(arr, mid + 1, right, value);
        }
    }
    else
    {
        return right;
    }
}

int solve(vector<int> arr, int value)
{
    int count = abs(lower_bound(arr, 0, arr.size() - 1, value) - upper_bound(arr, 0, arr.size() - 1, value));
    return count;
}

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
        cout << solve(arr, x) << '\n';
    }
    return 0;
}
