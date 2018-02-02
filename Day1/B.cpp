#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    
    string input, s;
    
    while(getline(cin, input))
    {
        int count = 0;
        stringstream ss;
        ss << input; //s5s
        while (ss >> s)
        {
            // s += " ";  //ss
            int n = 0;
            for (int i = 0; i < s.size(); i++)
            {
                char c = s[i];
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                {
                    n++;
                    // n = 1;
                }
                else 
                {
                    if (n)
                    {
                        count++;
                    }
                    n = 0;
                }
                // else if(n){
                //     count++;
                //     n = 0;
                // }
            }
            if (n)
            {
                count++;
            }
        }

        cout << count << endl;
    }
}