#include <iostream>
#include <deque>
using namespace std;

int quick_pow(int a, int b)
{
    int ans = 0;
    while (b)
    {
        if (b & 1)
            ans += a % 100000;
        b >>= 1;
        a += a % 100000;
    }
    return ans % 100000;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int c;
    cin >> c;
    while(c--)
    {
        int a, b, n, m, mm = 1;
        cin >> a >> b >> n >> m;

        deque<int> v;
        v.push_back(a);
        v.push_back(b);

        for (int i = 2; i <= n; i++)
        {
            int t = v.front() + v.back();
            
            t %= 10000;
            // cout << t << "\n";
            v.push_back(t);
            v.pop_front();
        }

        for(int i = 0; i < m; i++)
        {
            mm *= 10;
        }
        cout << v.back() % mm << "\n";
    }
}