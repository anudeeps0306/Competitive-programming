#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string s;
    cin>>s;
    int start=0,end=s.length()-1;
    for(int i=start;i<=end;i++){
        if(s[i]=='5'){
            start=i;
            break;
        }
        else{
            start=s.length()-1;
        }
    }
    for(int i=end;i>=start;i--){
        if(s[i]=='5'){
            end=i;
            break;
        }
        else{
            end=0;
        }
    }
    int count=0;
    // cout<<start<<" "<<end;
    if(start<=end && (end-start)==10){
        for(int i=start;i<=end;i++){
            count+=s[i]-'0';
        }
    }
    else{
        if(start<=end){
            int sum=0,answer=-1;
            for(int i=start;i<=end-11;i++){
                sum=0,answer=-1;
                for(int j=i;j<=10;j++){
                    sum+=s[j]-'0';
                }
                if(sum>answer){
                    answer=sum;
                }
            }
            cout<<answer;
        }
        else{
            count=-1;
        }
    }
    cout<<count;
	return 0;
}


