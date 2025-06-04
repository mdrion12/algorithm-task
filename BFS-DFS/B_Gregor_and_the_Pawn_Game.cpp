#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int t, n;
string enemy, gregor;
vector<bool> visited;

bool cal(int i, string &enemy, string &gregor)
{
    if (i < 0 || i >= n || gregor[i] == '0' || visited[i])
        return false;

    visited[i] = true;

    if (enemy[i] == '0')
        return true;

    if (i > 0 && enemy[i - 1] == '1')
    {
        enemy[i - 1] = '0';
        return true;
    }

    if (i + 1 < n && enemy[i + 1] == '1')
    {
        enemy[i + 1] = '0';
        return true;
    }

    return false;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> enemy >> gregor;

        visited.assign(n, false);

        int ans = 0;

        for (int i = 0; i < n; ++i)
        {
            if (gregor[i] == '1')
            {
                if (cal(i, enemy, gregor))
                {
                    ans++;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
