/**
 *    author:  Alpesh Jamgade
 *    created:  21.07.2021 21:23:54    
 *     
 *    solution : Here we need to return the position at which the given number H can be put in the given array(sorted),
 *               We can calculate this position using binary_search (modified to find upper bound) or just use STL function upper_bound();
 *               this can be easily answered by knowing how many numbers are there which are less than or equal to H.
 *
 *    algorithm : Binary Search
 *    complexity : O(log(n))
 **/

#include <bits/stdc++.h>

using namespace std;

int upper_bound(vector<int> arr, int left, int right, int val)
{
    if (left < right)
    {
        int mid = left - (left - right) / 2;
        int middle_elem = arr[mid];
        if (middle_elem >= val)
        {
            return upper_bound(arr, mid + 1, right, val);
        }
        else
        {
            return upper_bound(arr, left, mid, val);
        }
    }
    else
    {
        return left;
    }
}

int solve2(vector<int> heights, int H)
{
    int at = upper_bound(heights, 0, heights.size() - 1, H);
    return at + 1;
}

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
    cout << solve2(heights, H) << '\n';
    return 0;
}

