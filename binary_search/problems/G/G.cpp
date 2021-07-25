/**
 *    author:  Alpesh Jamgade
 *    created:  26.07.2021 00:08:19  
 *    solution: for each of the element x in the middle array 
 *              check the number of elements less than x in first array and number of elements greater than x in third array
 *    algorithm: Binary Search
 *    complexity: O(n)*O(log(n)) = O(n*log(n))       
**/

#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll solve(vector<int> a[3], int n) {
    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        ll cnt1 = abs(distance(a[0].begin(), lower_bound(a[0].begin(), a[0].end(), a[1][i])));
        ll cnt2 = abs(distance(a[2].end(), upper_bound(a[2].begin(), a[2].end(), a[1][i])));
        cnt += cnt1*cnt2;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a[3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0, x; j < n; j++) {
            cin >> x;
            a[i].push_back(x);
        }
        sort(a[i].begin(), a[i].end());
    }

    cout << solve(a, n);
    return 0;
}

