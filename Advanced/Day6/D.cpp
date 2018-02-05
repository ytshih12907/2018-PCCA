#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int r;
    cin >> r;
    while (r--)
    {
        int n, p[1001], sum = 0;
        stringstream ss;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> p[i];

        sort(p, p + n);

        int i;
        for (i = n; i > 3; i -= 2)
        {
            int a = p[1] + p[0] + p[i - 1] + p[1],
                b = p[i - 1] + p[0] + p[i - 2] + p[0];

            if (a > b)
            {
                sum += b;
                ss << p[0] << " " << p[i - 2] << "\n"
                   << p[0] << "\n"
                   << p[0] << " " << p[i - 1] << "\n"
                   << p[0] << "\n";
            }
            else
            {
                sum += a;
                ss << p[0] << " " << p[1] << "\n"
                   << p[0] << "\n"
                   << p[i - 2] << " " << p[i - 1] << "\n"
                   << p[1] << "\n";
            }
        }

        if (i == 3)
        {
            sum += p[0] + p[1] + p[2];
            ss << p[0] << " " << p[1] << "\n"
               << p[0] << "\n"
               << p[0] << " " << p[2] << "\n";
        }
        else if (i == 2)
        {
            sum += p[1];
            ss << p[0] << " " << p[1] << "\n";
        }
        else if (i == 1)
        {
            sum += p[0];
            ss << p[0] << "\n";
        }

        cout << sum << "\n";

        cout << ss.str();
        if(r)
            cout << "\n";
    }
}