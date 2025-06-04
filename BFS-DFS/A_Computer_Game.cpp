#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO\n";
#define yes cout << "YES\n";

int vis[3][101];
char arr[3][101];
int n;

bool valid(int x, int y)
{
    return (x >= 1 && x <= 2 && y >= 1 && y <= n && vis[x][y] == 0 && arr[x][y] == '0');
}

vector<pair<int, int>> dir = {{1, 1}, {-1, 1}, {0, 1}};

void dfs(int x, int y)
{
    for (auto it : dir)
    {
        int cx = x + it.first;
        int cy = y + it.second;
        if (valid(cx, cy))
        {
            vis[cx][cy] = 1;
            dfs(cx, cy);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;

        for (int i = 1; i <= 2; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> arr[i][j];
            }
        }
        memset(vis, 0, sizeof(vis));
        if (arr[1][1] == '0')
        {
            vis[1][1] = 1;
            dfs(1, 1);
        }

        if (vis[2][n] == 1)
        {
            yes
        }
        else
        {
            no
        }
    }

    return 0;
}
