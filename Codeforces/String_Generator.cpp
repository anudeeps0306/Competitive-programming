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

bool isequal(vector<int> a1,vector<int> a2){
        for(int i=0;i<a1.size();i++){
            if(a1[i]!=a2[i]){
                return false;
            }

        }
        return true;
}

bool found(string s1,string s2,int start,int end,int start1,int end1){
    string s = s1.substr(start1,end1-start1+1);

    if(s==s1){
        return true;
    }

    if(end1 == s1.size()){
        return false;
    }

    
    vector<int> v(26,0);

    for(auto it : s){
        v[it-'a']++;
    }

    vector<int> a(26,0);
    int l=0,r=0;
    while(r<s2.size()){
        a[s2[r]-'a']++;
        if(r-l+1 == s.size() && isequal(v,a)){
            if(found(s1,s2,l,r-l+1,start1,end1+1)){
                return true;
            }
        }
        if(r-l+1 < s.size()){
            r++;
        }
        else{
            a[s2[l]-'a']--;
            l++;
            r++;
        }
    }


    return false;
}

void solve(int k){
    int n;
    cin>>n;

    string s1,s2;

    cin>>s1>>s2;

    if(found(s1,s2,0,n-1,0,0)){
        cout<<"Case "<<k<<": YES"<<endl;
    }
    else{
        cout<<"Case "<<k<<": NO"<<endl;
    }
}       

 
int32_t main(){
 
    fastIO;
    auto start = std::chrono::high_resolution_clock::now();
    int k=1;
    int t;
    cin>>t;
    while(t--){
        solve(k);
        k++;
    }
 
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // #ifndef ONLINE_JUDGE
    //     cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s"<< endl;
    // #endif
    return 0;
}

