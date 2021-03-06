/**
 *    author:  Alpesh Jamgade
 *    created:  21.07.2021 21:24:17    
 *  
 *    solution: [Trivial] Simply check if the element is present in the array or not;
 * 
 *    algorithm: Binary Search
 * 
 *    complexity: O(log(n))
 *    
**/

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

        cout << (binary_search(arr.begin(), arr.end(), x) ? "YES" : "NO") << '\n';
    }
    return 0;
}
