#include <iostream>
#include <vector>
using namespace std;

long long merge(int *a, int n)
{
    long long count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                count++;
            }
        }
    }
    return count;
}

long long merge_sort(int *a, int n)
{
    int m = n / 2;
    long long count = 0;
    if (n == 1)
        return 0;

    count += merge_sort(a, m);
    count += merge_sort(a + m, n - m);

    count += merge(a, n);

    return count;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    while (cin >> n)
    {
        if (!n)
            return 0;

        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout << merge_sort(a, n) << "\n";
        // for (int i = 0; i < n; i++)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << "\n";
    }
}