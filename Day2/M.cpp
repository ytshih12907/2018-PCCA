#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    string a;
    getline(cin, a);
    while(n--)
    {
        vector<char> v;
        string s;
        getline(cin, s);
        bool flag = true;

        for (int i = 0; i < s.size(); i++)
        {
            char c = s.at(i);
            if(c == '[' || c == '(')
            {
                v.push_back(c);
            }
            else if(c == ']')
            {
                if(v.size() > 0 && v.back() == '[')
                {
                    v.pop_back();
                }
                else
                {
                    cout << "No"<< "\n";
                    flag = false;
                    break;
                }
            }
            else if(c == ')')
            {
                if (v.size() > 0 && v.back() == '(')
                {
                    v.pop_back();
                }
                else
                {
                    cout << "No" << "\n";
                    flag = false;
                    break;
                }
            }
            else
            {
                cout << "No" << "\n";
                flag = false;
                break;
            }
        }

        if(flag)
        {
            if(v.size() == 0)
            {
                cout << "Yes"
                     << "\n";
            }
            else
            {
                cout << "No"
                     << "\n";
            }
        }
    }
}