#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio;
    vector<int> v;
    int n;
    cin >> n;
    while(n--)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    cin >> n;
    while(n--)
    {
        int t;
        cin >> t;
        vector<int>::iterator it = lower_bound(v.begin(), v.end(), t);
        if(it == v.end())
        {
            cout << "X";
        }
        else
        {
            
            cout << *it;
        }
        cout << " ";

        it = upper_bound(v.begin(), v.end(), t);

        if(it == v.end())
        {
            cout << "X";
        }
        else
        {
            cout << *it;
        }
        cout << "\n";
    }
    
}

// int binary_search(int* data, int len, int find)
// {
//     int left = 0, mid, right = len - 1;
//     while(right - left > 1)
//     {
//         mid = (left + right) / 2;
//         if (find > data[mid])
//         {
//             left = mid;
//         }
//         else
//         {
//             right = mid;
//         }
//     }
//     return right;
// }
// // 1 4 5 7
// // 0 1 2 3
// int main()
// {
//     int data_len;
//     cin >> data_len;
//     int data[data_len];
//     for (int i = 0; i < data_len; i++)
//         cin >> data[i];

//     int query_len;
//     cin >> query_len;
//     int query[query_len];
//     for (int i = 0; i < query_len; i++)
//         cin >> query[i];

//     for (int i = 0; i < query_len; i++)
//     {

//     }
//         cout << binary_search(data, data_len, 10);
// }