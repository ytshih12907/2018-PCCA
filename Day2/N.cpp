#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int n, c = 0;
    while(cin >> n)
    {
        if(n == 0)
            return 0;

        
        deque<int> d;

        for (int i = 1; i <= n; i++)
        {
            d.push_back(i);
        }
        if (c)
        {
            cout << "\n";
        }
        c++;
        cout << "Discarded cards:";
        int count = 0;
        while (d.size() > 1)
        {
            if(count)
            {
                cout << ", ";
            }
            else
            {
                cout << " ";
            }
            cout << d.front();
            d.pop_front();
            d.push_back(d.front());
            d.pop_front();
            count++;
        }
        cout << "\n"
             << "Remaining card: " << d.front();
    }
}