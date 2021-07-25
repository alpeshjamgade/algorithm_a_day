/**
 *    author:  Alpesh Jamgade
 *    created:  25.07.2021 23:45:13     
 *    
 *    solution : Considering the subarray's with only one element, the minimum sub-array sum achievable out of k sub-arrays formed, is max(arr.begin(), arr.end());
 *               Also, the maximum sub-array sum out of K sub-array is sum(arr.begin(), arr.end()) where k <= 1;
 *               
 *              So, now the solution is simple, we just need to apply binary search between these two extremas and check for each mid if there are less or equal to k;
 *              In this way by decreasing the total subarray's count (<=k) we can acheiven minimum possible maximum subarray sum
 *    
 *    algorithm : Binary Search 
 *    complexity : O(log(n)) [for binary search] * O(n) [for check() function] => O(n*log(n))
**/

#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n, k;

bool check(ll mid, vector<int> &arr)
{
    int subarray_count = 0;
    ll max_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            return false;
        max_sum += (ll)arr[i];

        if (max_sum > mid)
        {
            subarray_count++;
            max_sum = arr[i];
        }
    }
    subarray_count++;

    if (subarray_count <= k)
        return true;
    return false;
}

ll binary_search(ll left, ll right, vector<int>& arr, ll answer)
{
    if (left <= right)
    {
        ll mid = left - (left - right) / 2;
        if (check(mid, arr))
        {

            answer = mid;
            return binary_search(left, mid - 1, arr, answer);
        }
        else
        {
            return binary_search(mid + 1, right, arr, answer);
        }
    }
    else
    {
        return left;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll answer = 0;
    ll min = *max_element(arr.begin(), arr.end());
    ll max = accumulate(arr.begin(), arr.end(), (ll)0);
    cout << binary_search(min, max, arr, answer);
    return 0;
}