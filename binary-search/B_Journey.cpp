#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, a, b, c;
        cin >> n >> a >> b >> c;

        ll cycle_sum = a + b + c;                 
        ll full_cycles = n / cycle_sum;            
        ll total_walked = full_cycles * cycle_sum; 

        ll days = full_cycles * 3; 

      
        if (total_walked >= n)
        {
            cout << days << "\n";
            continue;
        }
        if (total_walked + a >= n)
        {
            cout << days + 1 << "\n";
            continue;
        }
        if (total_walked + a + b >= n)
        {
            cout << days + 2 << "\n";
            continue;
        }
        cout << days + 3 << "\n";
    }

    return 0;
}