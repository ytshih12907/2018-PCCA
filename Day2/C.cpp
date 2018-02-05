#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    list<long> l;
    int n;
    cin >> n;

    while(n--)
    {
        string s;
        long a;
        cin >> s;

        if(s == "insert")
        {
            cin >> a;
            l.push_front(a);
        }
        else if(s == "delete")
        {
            cin >> a;
            for (list<long>::iterator it = l.begin(); it != l.end(); it++)
            {
                if(*it == a)
                {
                    l.erase(it);
                    break;
                }
            }
        }
        else if(s == "deleteFirst")
        {
            l.pop_front();
        }
        else if(s == "deleteLast")
        {
            l.pop_back();
        }
    }

    for (list<long>::iterator it = l.begin(); it != l.end(); it++)
    {
        if(it != l.begin())
        {
            cout << " ";
        }
        cout << *it;
    }
    cout << "\n";
}

/*
9
insert 5
insert 2
insert 3
insert 1
delete 4
insert 6
delete 5
deleteFirst
deleteLast
*/