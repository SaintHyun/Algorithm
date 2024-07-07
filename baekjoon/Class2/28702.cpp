#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input[3];
    int i, numidx, num;
    for (i = 0; i < 3; i++)
    {
        cin >> input[i];
    }
    for (i = 0; i < 3; i++)
    {
        if (input[i][0] >= '0' && input[i][0] <= '9')
        {
            numidx = i;
            break;
        }
    }
    num = stoi(input[numidx]);
    num = num + (3 - numidx);
    if (num % 3 == 0)
    {
        if (num % 5 == 0)
            cout << "FizzBuzz\n";
        else
            cout << "Fizz\n";
    }
    else if (num % 5 == 0)
        cout << "Buzz\n";
    else
        cout << num << "\n";
}