#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    long long int k, p, n = 11, zcy = 0, sum = 0;
    cin >> k >> p;

    while (1)
    {
        stringstream ss;
        ss << n;
        string s;
        ss >> s;
        

        if (s.size() % 2 == 0)
        {
            string t;
            for (long long int i = s.size() - 1; i >= 0; i--)
            {
                t += s[i];
            }
            if (s == t && s.size() % 2 == 0)
            {
                sum += n;
                // cout << n << "\n";
                if (++zcy == k)
                {
                    cout << sum % p;
                    return 0;
                }
            }
        }

        n++;
    }
}