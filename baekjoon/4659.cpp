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

    string password;
    string vowel = "aeiou";
    while (1)
    {
        int i, len, flag1_cnt = 0;
        bool flag2 = false, flag3 = false;
        cin >> password;
        if(password == "end") return 0;
        len = password.length();
        for (i = 0; i < len; i++)
        {
            if (vowel.find(password[i]) != string::npos)
            {
                flag1_cnt++;
            }
            if (i >= 2 && vowel.find(password[i]) != string::npos && vowel.find(password[i - 1]) != string::npos && vowel.find(password[i - 2]) != string::npos)
            {
                flag2 = true;
            }
            if (i >= 2 && vowel.find(password[i]) == string::npos && vowel.find(password[i - 1]) == string::npos && vowel.find(password[i - 2]) == string::npos)
            {
                flag2 = true;
            }
            if (i >= 1 && password[i] == password[i - 1] && password[i] != 'e' && password[i] != 'o')
            {
                flag3 = true;
            }
        }
        if (flag1_cnt == 0 || flag2 || flag3)
        {
            cout << "<" << password << "> is not acceptable.\n";
        }
        else
        {
            cout << "<" << password << "> is acceptable.\n";
        }
        
        return 0;
    }
}