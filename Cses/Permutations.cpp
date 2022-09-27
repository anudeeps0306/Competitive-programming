#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n,sum=0;
    cin>>n;
    if(n==3 || n==2){
        cout<<"NO SOLUTION";
    }
    else if(n==4){
        cout<<2<<" "<<4<<" "<<1<<" "<<3;
    }
    else if(n==1){
        cout<<1;
    }
    else{
        if(n%2==0){
            int even=n;
            int odd=n-1;
            while(even>0){
                cout<<even<<" ";
                even-=2;
            }
            while(odd>0){
                cout<<odd<<" ";
                odd-=2;
            }

        }
        else{
            int even=n-1;
            int odd=n;
            while(even>0){
                cout<<even<<" ";
                even-=2;
            }
            while(odd>0){
                cout<<odd<<" ";
                odd-=2;
            }
        }
    }
    return 0;
}