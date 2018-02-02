#include <iostream>
#include <deque>
#include <utility>
using namespace std;

int main()
{
    deque<pair<string, int> > d;
    pair<string, int> p;
    int n, q, time = 0;
    cin >> n >> q;
    while(n--)
    {
        string s;
        int t;
        cin >> s >> t;
        d.push_back(make_pair(s, t));
    }

    while(d.size() > 0)
    {
        p = d.front();
        d.pop_front();
        if(p.second > q)
        {
            p.second -= q;
            d.push_back(p);
            time += q;
        }
        else if(p.second == q)
        {
            time += q;
            cout << p.first << " " << time << "\n";
        }
        else
        {
            time += p.second;
            cout << p.first << " " << time << "\n";
        }
    }
}