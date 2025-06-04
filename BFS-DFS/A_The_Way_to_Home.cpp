#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
string x;
int n, d;
int dp[101];
bool valid(int i)
{
    if (x[i] == '1' && i <= n)
    {
        return true;
    }
    return false;
}
int dfs(int x, string s)
{
    if (x == n)
    {
        return 0;
    }
    if (dp[x] != -1)
    {
        return dp[x];
    }
    int ans = 200;
    for (int i = 1; i <= d; i++)
    {
        if (valid(x + i))
        {
            // ans = min(ans, dfs(x + i, s) + 1);
            int val = dfs(x + i, s) + 1;
            ans = min(ans, val);
        }
    }
    return dp[x] = ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> d;
    string s;
    cin >> s;
    x = "@";
    x += s;
    memset(dp, -1, sizeof(dp));
    int val = dfs(1, x);
    if (val == 200)
    {
        cout << "-1" << "\n";
    }
    else
    {
        cout << val << "\n";
    }

    return 0;
}