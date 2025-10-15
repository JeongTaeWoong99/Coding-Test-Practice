#include <bits/stdc++.h>
using namespace std;

int         temp;
vector<int> v;

int main()
{
    for (int i = 0; i < 4; i++)
    {
        cin >> temp;
        v.emplace_back(temp);
    }

    sort(v.begin(),v.end());

    cout << v[0] * v[2];

    return 0;
}