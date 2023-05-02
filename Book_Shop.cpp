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
int dp[1002][100002];
int dhruv(int n, int money, int price[], int pages[])
{
    if (n == 0)
        return 0ll;

    if (dp[n - 1][money] != -1)
        return dp[n - 1][money];

    if (price[n - 1] <= money)
        return dp[n - 1][money] = max(
                   pages[n - 1] + dhruv(n - 1, money - price[n - 1], price, pages),
                   dhruv(n - 1, money, price, pages));

    return dp[n - 1][money] = dhruv(n - 1, money, price, pages);
}
*/
int main()
{
    fastio;

    int n, money;

    cin >> n >> money;
    int dp[n + 1][money + 1];

    int price[n] = {4, 8, 5, 3}, pages[n] = {5, 12, 8, 1};

    for (int i = 0; i < n; ++i)
        cin >> price[i];
    for (int i = 0; i < n; ++i)
        cin >> pages[i];

    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= money; ++j)
        {
            if (price[i - 1] <= j)
            {
                dp[i][j] = max(
                    pages[i - 1] + dp[i - 1][j - price[i - 1]],
                    dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][money] << "\n";

    return 0;
}