#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    int tree[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> tree[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "node " << i << ": key = " << tree[i] << ", ";
        int t = i / 2;
        if(t > 0)
        {
            cout << "parent key = " << tree[t] << ", ";
        }

        t = i * 2;
        if(t <= n)
        {
            cout << "left key = " << tree[t] << ", ";
        }

        t++;
        if(t <= n)
        {
            cout << "right key = " << tree[t] << ", ";
        }

        cout << "\n";
    }
}