#include <iostream>
#define MAX_LEN 1000
#define MAX_CUT 50
using namespace std;

int cost[MAX_LEN][MAX_LEN], cut[MAX_CUT];

int dp(int s, int t)
{
    for (int i = s; i <= t; i++)
    {
        
    }
}

int main()
{
    int len;
    while (cin >> len)
    {
        if (!len)
            return 0;

        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> cut[i];
        }

        cout << "The minimum cutting is " << dp(0, len) << "." << endl;
    }
}