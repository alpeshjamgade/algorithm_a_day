#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first
#define se second
#define pi 3.1415926535
#define mod1 1000000007
#define mod2 1000000009
#define mp make_pair
#define no_of_digits(n) floor(log10(n)) + 1
#define lcm(a, b) (a/__gcd(a,b)*b)
#define sdebug(n) cout << "\n' n = " << n << " '\n";

using namespace std;

const int mxN = 7489;
int dp[mxN];
const vector<int> coins = {50, 25, 10, 5, 1};

// bottom-up
void calculate() {
  dp[0] = 1;
	for(int d = 0; d < (int)coins.size(); d++) {
        for(int amount = 1; amount <= mxN; amount++){
            if(amount >= coins[d])
                dp[amount]+=dp[amount-coins[d]];
        }
	}
}


// top-bottom
int kira(int d, int S) {
    if(S == 0) return 1; 
    if(S < 0) return 0; 
    if(d <=0 && S >= 1) return 0;
    return kira(d-1, S) + kira(d, S-coins[d-1]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(dp, 0, sizeof(0));
    calculate();
    int n;
    while(cin >> n) {
  	    cout << dp[n] << '\n';
        cout << kira(5, n) << '\n';
    }
    return 0;
}
