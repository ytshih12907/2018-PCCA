#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    priority_queue<int> pq;
    string s;
    while(cin >> s)
    {
        if(s == "end")
            return 0;
        
        if(s == "insert")
        {
            int n;
            cin >> n;
            pq.push(n);
        }
        else
        {
            cout << pq.top() << "\n";
            pq.pop();
        }
    }
}