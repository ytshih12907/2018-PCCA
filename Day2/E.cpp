#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    vector<int> v;
    int n;
    cin >> n;
    while(n--)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    make_heap(v.begin(), v.end());

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << " " << *it;
    }
    cout << "\n";
}