#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    vector<int> v;
    string input, s;
    getline(cin, input);
    stringstream ss(input);

    while(ss >> s)
    {
        stringstream conv(s);
        if(s[0] >= '0' && s[0] <= '9')
        {
            int n;
            conv >> n;
            v.push_back(n);
        }
        else
        {
            char c;
            conv >> c;
            int a = v.back();
            v.pop_back();
            int b = v.back();
            v.pop_back();
            switch(c)
            {
                case '+':
                    v.push_back(a + b);
                    break;
                case '-':
                    v.push_back(b - a);
                    break;
                case '*':
                    v.push_back(a * b);
                    break;
                case '/':
                    v.push_back(b / a);
                    break;
            }
        }
    }
    cout << v.back() << "\n";
}