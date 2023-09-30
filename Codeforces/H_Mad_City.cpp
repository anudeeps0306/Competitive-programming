#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

long maximizeAZ(string s){
     long  n = s.size();
    long  a=0,z=0;
    for(long  i=0; i<n; i++){
       if(s[i]=='A') a++;
        if(s[i]=='Z')
        z++;
    }
    long  z1=z;
    long  ans=0;
    z=z+1;
    
    for(long  i=0; i<n; i++){
            if(s[i]=='Z'){
                z--;
            }
            if(s[i]=='A'){
                ans+=z;
            }
    }
    long  ans1=0;
    z=z1;
    a=a+1;
    for(long  i=n-1; i>=0; i--){
            if(s[i]=='Z'){
                ans1+=a;;
            }
            if(s[i]=='A'){
                a--;
            }
    }
    return max(ans,ans1);
}

long  main() {
    string s;
    cin>>s;
   
    cout<<max(ans,ans1);


   
}
