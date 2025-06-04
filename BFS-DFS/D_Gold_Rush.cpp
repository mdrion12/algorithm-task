#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";

int n, m;
bool f;
unordered_map<int, int> dp;

int dfs(int x)
{
    if (x == m)
    {
        f = true;
        return 0;
    }
    if (x < m)
    {
        return 0;
    }
    if (dp.count(x))
    {
        return dp[x];
    }
    if (x % 3 == 0)
    {
        int op1 = dfs((x / 3) * 2);
        int op2 = dfs(x / 3);
        return dp[x] = max(op1, op2);
    }
    return dp[x] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        f = false;
        dp.clear();
        dfs(n);
        if (f)
            yes else no
    }

    return 0;
}
