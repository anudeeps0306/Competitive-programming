#include <bits/stdc++.h>
using namespace std;
#define fastIO          {ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define mod             1000000007
#define PI              3.1415926535897932384626
#define endl            "\n"
#define YES             cout << "YES" << "\n"
#define NO              cout << "NO" << "\n"
#define ispowoftwo(n)   (!(n & (n-1)))
#define pb              push_back
#define ppb             pop_back
#define int              long long
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef vector<vi> vvi;
 
 
 
int lcm(int a, int b){
    return (a / __gcd(a, b)) * b;
}

bool clean(string s){
    bool flag = false;

    for(int i=0;i<s.length()-1;i++){
        if(s[i]=='A' && s[i+1]=='B'){
            flag=true;
        }
        else if(s[i]=='B' && s[i+1]=='B'){
            flag=true;
        }
    }
    return flag;
}


int check( int i , vector<int> ans){
    for(auto it : ans){
        if(it%i != 0){
            return -1;
        }
    }

    if(i==1) return 2;

    for(int j=2;j<i;j++){
        if(i%j != 0){
            return j;
        }
    }

    return i+1;
}

string v[200];

void solve(){
    int n,a=0,b=0,c=0,d=0;
    cin>>n;
    string s;
    cin>>s;

    int i=0;
    while(i<n){
        if(s[i]!='m' && s[i]!='M'){
            break;
        }
        i++;
        a++;
    }

    while(i<n){
        if(s[i]!='e'&& s[i]!='E'){
            break;
        }
        i++;
        b++;
    }

    while(i<n){
        if(s[i]!='o' && s[i]!='O'){
            break;
        }
        i++;
        c++;
    }

    while(i<n){
        if(s[i]!='w' && s[i]!='W'){
            break;
        }
        i++;
        d++;
    }

    // while(i<n){
    //     if(s[i]=='e' || s[i]=='E'){
    //         continue;
    //     }
    //     else{
    //         break;
    //     }
    //     i++;
    // }

    // while(i<n){
    //     if(s[i]=='o' || s[i]=='O'){
    //         continue;
    //     }
    //     else{
    //         break;
    //     }
    //     i++;
    // }

    // while(i<n){
    //     if(s[i]=='w' || s[i]=='W'){
    //         continue;
    //     }
    //     else{
    //         break;
    //     }
    //     i++;
    // }

    



    if(i==n && a>=1 && b>=1 && c>=1 && d>=1){
        YES;
    }
    else{
        NO;
    }

    
    
}

 
int32_t main(){
 
    fastIO;
    auto start = std::chrono::high_resolution_clock::now();
 
    int t;
    cin>>t;
    while(t--) solve();
 
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // #ifndef ONLINE_JUDGE
    //     cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s"<< endl;
    // #endif
    return 0;
}

