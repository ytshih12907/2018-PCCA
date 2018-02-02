#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    while(1)
    {
        stringstream ss;

        string s;
        int n;

        cin >> s;
        ss << s;
        
        if(s[1] == 'x')
        {
            ss >> hex >> n;
            if (n < 0)
                return 0;
            cout << dec << n << endl;
        }
        else
        {
            ss >> dec >> n;
            if (n < 0)
                return 0;
            
            cout << "0x" << hex << uppercase << n << endl;
        }
    }
}