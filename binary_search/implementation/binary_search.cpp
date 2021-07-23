/**
 *    author:  Alpesh Jamgade
 *    created:  19.07.2021 21:35:16 
 *    run: g++ -std=c++17 -ulimit -Wall -Wno-unused-result -pthread -O2 binary_search.cpp -o binary_search && ./binary_search < sample1.in   
**/

#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> arr, int left, int right, int val)
{
    if (left < right)
    {
        int mid = left - (left - right) / 2;
        int middle_elem = arr[mid];
        if (middle_elem == val)
        {
            return mid;
        }
        else if (middle_elem < val)
        {
            return binary_search(arr, mid + 1, right, val);
        }
        else
        {
            return binary_search(arr, left, mid - 1, val);
        }
    }
    else
    {
        return left;
    }
}

int lower_bound(vector<int> arr, int left, int right, int val)
{
    if (left < right)
    {
        int mid = left - (left - right) / 2;
        int middle_elem = arr[mid];
        if (middle_elem >= val)
        {
            return lower_bound(arr, left, mid, val);
        }
        else
        {
            return lower_bound(arr, mid + 1, right, val);
        }
    }
    else
    {
        return right;
    }
}

int upper_bound(vector<int> arr, int left, int right, int val)
{
    if (left < right)
    {
        int mid = left - (left - right) / 2;
        int middle_elem = arr[mid];
        if (middle_elem <= val)
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

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    cout << binary_search(arr, 0, n - 1, m) << endl;

    return 0;
}
