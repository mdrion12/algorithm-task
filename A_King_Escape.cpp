#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
int arr[1001][1001];
int vis[1001][1001];
int n;
int ax, ay, bx, by, cx, cy;
vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
bool valid(int i, int j)
{
    if (i <= n && i >= 1 && j >= 1 && j <= n && i != ax && j != ay && vis[i][j] == 0)
    {
        return true;
    }
    return false;
}
void dfs(int i, int j)
{
    for (auto it : dir)
    {
        int cx = it.first + i;
        int cy = it.second + j;
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
    cout.tie(NULL);

    cin >> n;

    cin >> ax >> ay >> bx >> by >> cx >> cy;

    int x = ax, y = ay;

    while (x >= 1 && y >= 1)
    {
        vis[x][y] = 1;
        x--;
        y--;
    }
    x = ax, y = ay;

    while (x >= 1 && y <= n)
    {
        vis[x][y] = 1;
        x--;
        y++;
    }
    x = ax, y = ay;

    while (x <= n && y >= 1)
    {
        vis[x][y] = 1;
        x++;
        y--;
    }
    x = ax, y = ay;

    while (x <= n && y <= n)
    {
        vis[x][y] = 1;
        x++;
        y++;
    }

    vis[bx][by] = 1;
    dfs(bx, by);
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << vis[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    if (vis[cx][cy] == 1)
    {
        yes
    }
    else
    {
        no
    }

    return 0;
}