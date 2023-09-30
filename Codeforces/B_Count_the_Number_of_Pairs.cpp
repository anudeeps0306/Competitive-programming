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
// #define int              long long
 
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
    int n,k;
    cin>>n>>k;

    map<char,int> m;

    string s;
    cin>>s;

    for(int i=0;i<n;i++){
        m[s[i]]++;
    }

    int ans=0;


    for(auto it : m){
        if(isupper(it.first)){
            if(m[char(int(it.first)+32)]>0){
                int a1 =min(it.second,m[char(int(it.first)+32)]);
                ans+= a1;
                m[it.first]-=a1;
                m[char(int(it.first)+32)]-=a1;
            }
        }
        // cout<<ans<<" "<<it.first<<endl;
    }

    

    

   for(auto it : m){
        if(islower(it.first)){
            int a1 = it.second/2;
            if(a1<=k){
                ans+=a1;
                k-=a1;
            }
            else{
                ans+=k;
                k=0;
            }
        }
   }

   //same logic for upper
   for(auto it : m){
        if(isupper(it.first)){
            int a1 = it.second/2;
            if(a1<=k){
                ans+=a1;
                k-=a1;
            }
            else{
                ans+=k;
                k=0;
            }
        }
   }


   cout<<ans<<endl;

    
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

