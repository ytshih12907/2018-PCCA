#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    int n;
    cin >> n;
    while(n--)
    {
        cin >> s;
        vector<char> v;
        for (int i = 0; i < s.size(); i++)
        {
            v.push_back(s.at(i));
        }

        sort(v.begin(), v.end());
        do
        {
            for (int i = 0; i < v.size(); i++)
            {
                cout << v.at(i);
            }
            cout << "\n";
        } while (next_permutation(v.begin(), v.end()));

        cout << "\n";
    }
}