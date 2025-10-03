#include<bits/stdc++.h>
using namespace std;  

string str; 
int cnt[26];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> str; 
    
    for(char a : str)
        cnt[a - 'a']++;
	
    for (int i : cnt)
        cout << i << " ";
	 
    return 0; 
}