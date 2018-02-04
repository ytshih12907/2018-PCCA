#include <iostream>
#include <vector>
using namespace std;

inline long long int f(long long int x) { return x * 10 + 1; }
inline long long int g(long long int x) { return x * 2; }

vector<long long int> stk;
bool flag = false;

void dfs(long long int u, long long int v)
{
    stk.push_back(u);
    if (u == v)
    {
        cout << "YES"
             << "\n"
             << stk.size() << "\n";
        for (long long int i = 0; i < stk.size(); i++)
        {
            cout << stk[i] << " ";
        }
        flag = true;
    }
    else if (u < v)
    {
        dfs(f(u), v);
        dfs(g(u), v);
    }

    stk.pop_back();
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    long long int a, b;
    cin >> a >> b;
    dfs(a, b);
    if(!flag)
    {
        cout << "NO"
             << "\n";
    }
}