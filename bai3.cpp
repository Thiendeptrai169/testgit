#include <bits/stdc++.h>
using namespace std;
int long long a[10000001];
void checksnt()
{
    for (long long i = 0; i < pow(10,7); i++)
        a[i] = 1;
    a[0] = a[1] = 0;
    for (long long i = 2; i < sqrt(pow(10,7)); i++)
        for (long long j = i * i; j <= pow(10,7); j += i)
            a[j] = 0;
}
int main()
{
    checksnt();
    int t;
    cin >> t;
    while (t--)
    {
        long long l, r, a1, b;
        cin >> l >> r;
        if(r == 2 || r == 3)
            cout << "-1" << endl;
        else if (r % 2 == 0)
        {
            a1 = r / 2;
            b = r / 2;
            cout << a1 << " " << b << endl;
        }
        else if (l != r && r % 2 != 0)
        {
            a1 = (r - 1) / 2;
            b = (r - 1) / 2;
            cout << a1 << " " << b << endl;
        }
        else if (l == r && r % 2 != 0)
        {
            if (a[r] == 1)
                cout << "-1" << endl;
            else
            {
                for (long long i = 2; i < sqrt(r); i++)
                {
                    if (r % i == 0)
                        {
                            r /= i;
                            a1 = 1;
                            b = r - a1;
                            cout << a1 * i << " " << b * i << endl;
                            break;
                        }
                }
            }
        }
    }
}