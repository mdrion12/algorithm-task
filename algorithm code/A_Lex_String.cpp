#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, k;
        cin >> a >> b >> k;
        string s1, s2;
        cin >> s1 >> s2;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int i = 0, j = 0;
        int x = 0, y = 0;
        string c = "";
        while (i < s1.size() && j < s2.size())
        {
            if ((s1[i] < s2[j] && x < k) || y == k)
            {
                c += s1[i];
                i++;
                x++;
                y = 0;
            }
            else
            {
                c += s2[j];
                j++;
                y++;
                x = 0;
            }
        }
        cout << c << "\n";
    }
    return 0;
}
