/**
 *    author:  Alpesh Jamgade
 *    created:  21.07.2021 21:24:31       
**/

#include <bits/stdc++.h>
#define lcm(a, b) ((a * b) / __gcd(a, b))

using namespace std;
ofstream fout("out");

int N, a, b;

int count_terms(int value)
{
    return value / a + value / b - value / lcm(a, b);
}

int upper_bound(int left, int right)
{
    if (left < right)
    {
        int mid = left - ((left - right) / 2);
        int terms = count_terms(mid);

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

    cin >> a >> b >> N;
    cout << upper_bound(1, 1000000000) << '\n';
    return 0;
}
