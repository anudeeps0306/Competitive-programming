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



 
void solve(){
    int n,s;
    cin>>n>>s;

    int a[n],maxi=INT_MIN;

    map<int,int> m;

    for(int i=0;i<n;i++){
        cin>>a[i];
        maxi = max(maxi,a[i]);
        m[a[i]]++;
    }

    int sum=maxi*((maxi+1)/2),c=1;
    bool flag = true;
    while(flag && sum > 0){
        if(m[c] == 0){
            sum -= c;
        }
        if(sum == 0){
            break;
        }
        else{
            continue;
        }
        c++;
    }

    if(sum == 0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }




    cout<<endl;
}

 
int32_t main(){
 
    fastIO;
    auto start = std::chrono::high_resolution_clock::now();
 
    int t;
    cin>>t;
    while(t--) 
    solve();
 
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // #ifndef ONLINE_JUDGE
    //     cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s"<< endl;
    // #endif
    return 0;
}

