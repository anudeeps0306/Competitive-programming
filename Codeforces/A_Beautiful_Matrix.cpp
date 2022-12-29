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

char get(int i) {
    return 'a' + i - 1;
}

const int INF = 1e9 + 5; 

int myans(int n){
    int pow =1;
    while(pow<=n){
        pow*=2;
    }
    return pow;
}
void solve(){
    int input,x,y;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>input;
            if(input==1){
                x=i;
                y=j;
                break;
            }
        }
    }
    cout<<abs(x-2)+abs(y-2)<<endl;
}

 
int32_t main(){
 
    fastIO;
    auto start = std::chrono::high_resolution_clock::now();
 
    // int t;
    // cin>>t;
    // while(t--)
    solve();
 
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // #ifndef ONLINE_JUDGE
    //     cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s"<< endl;
    // #endif
    return 0;
}
