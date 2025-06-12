#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, k;
        cin >> a >> k;
        ll l = 1, r = INT_MAX;
        ll mid, ans = 0;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            ll x = mid - mid / a;
            if (x < k)
            {
                l = mid + 1;
            }
            else if (x > k)
            {
                r = mid - 1;
            }
            else
            {
                ans = mid;
                r = mid - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}