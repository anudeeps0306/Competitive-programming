#include<bits/stdc++.h>

using namespace std;
#define long long int


int main(){
    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin >> n >> k;

        if(n%2!=0){
            if(k%2==0){
                cout<<"NO"<<endl;
            }
            else{
                if(n%k==0){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
        }
        else{
            
        }
    }
}