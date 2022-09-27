#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        string s;
        cin>>s;
        char last=s[0];
        int sum=0,max=-1;
        for(auto it : s){
            if(it==last){
                sum++;
                max=max>sum?max:sum;
            }
            else{
                max=max>sum?max:sum;
                sum=1;
                last=it;
            }
        }
        cout<<max<<endl;
    
    return 0;
}
