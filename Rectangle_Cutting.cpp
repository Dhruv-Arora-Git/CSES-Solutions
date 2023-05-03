/*
 ___
|   \  | |__    _,_           __     __
| /\ \ | '_ \  | __| | | | |  \ \   / /
| \/ / | | | | | |   | (_) |   \ \_/ /
|___/  |_| |_| |_|   \ ___ /    \___/
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL), cout.tie(NULL), ios_base::sync_with_stdio(false);
#define ll long long int
#define ld long double
#define mp make_pair
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << " = " << x << '\n'
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << '\n'

// ----------------------------------------------
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll Lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll fastPower(ll base, ll power)
{
    ll ans = 1;
    while (base > 0)
    {
        if ((power & 1) == 1)
            ans *= base;
        base = base * base;
        power = power >> 1;
    }
    return ans;
}
// ----------------------------------------------

const int mod = 1'000'000'007;
/*
int dhruv(int i, int j, vector<vector<int>> &dp) {
	if(i == 0 || j == 0 || i == j)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];
	
	int ans = 1e9;
	for(int k =  1; k < j; ++k) {
		ans = min(ans, 1 + dhruv(i, k, dp) + dhruv(i, j - k, dp));
	}

	for(int k = 1; k < i; ++k) {
		ans = min(ans, 1 + dhruv(k, j, dp) + dhruv(i - k, j, dp));
	}

	return dp[i][j] = ans;
}
*/

int main()
{
    fastio;

    int a,b;
    cin >> a >> b;

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));
    // vector<vector<int>> dp1(a + 1, vector<int>(b + 1, -1));
    dp[0][0] = 0;

    for (int i = 0; i <= a; ++i)
    {
    	for (int j = 0; j <= b; ++j)
    	{
    		if(i == 0 || j == 0 || i == j)
    			dp[i][j] = 0;
    		else {
	    		for (int k = 1; k < j; ++k)
	    		{
	    			dp[i][j] = min(dp[i][j], (1 + dp[i][k] + dp[i][j - k]));
	    		}

	    		for (int k = 1; k < i; ++k)
	    		{
	    			dp[i][j] = min(dp[i][j], (1 + dp[k][j] + dp[i - k][j]));
	    		}
    		}
    	}
    }
    cout << dp[a][b] << "\n";
    // cout << dhruv(a, b, dp1) << "\n";
    return 0;
}