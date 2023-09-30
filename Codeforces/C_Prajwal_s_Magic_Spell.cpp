#include <bits/stdc++.h>
using namespace std;


void solve(){
    string s;
    cin >> s;
    int ct=0;
    for(int i=0;i<s.length();i++){
       if(s[i] =='a')
       {
        break;
       }
       else {
        s[i]=s[i]-1;
        ct++;
        continue;
       }
    }
    cout << s << endl;
}
int main()
{
    solve();
    return 0;
}