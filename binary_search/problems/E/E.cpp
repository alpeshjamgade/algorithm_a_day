/**
 *    author:  Alpesh Jamgade
 *    created:  21.07.2021 21:26:17   
 *    solution: Just apply binary search (upper bound) on the numbers from 1 to INT_MAX 
 *              and check for each mid if the number of terms divisible by mid == N or not
 *    algorithm: Binary Search
 *    complexity: O(log(n))      
**/

#include <bits/stdc++.h>

#define ll long long
#define lcm(a, b) ((a * b) / __gcd(a, b))

using namespace std;

ll a, b, c, N;

ll count_terms(ll num)
{
    return ((num / a) + (num / b) + (num / c) - (num / lcm(a, b)) - (num / lcm(b, c)) - (num / lcm(c, a)) + (num / lcm(a, lcm(b, c))));
}

ll upper_bound(ll left, ll right)
{
    if (left < right)
    {
        ll mid = left + (right - left) / 2;
        ll terms = count_terms(mid);
        if (terms < N)
        {
            return upper_bound(mid + 1, right);
        }
        else
        {
            return upper_bound(left, mid);
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

    cin >> a >> b >> c >> N;
    cout << upper_bound(1, INT_MAX) << '\n';
    return 0;
}
