#include <bits/stdc++.h>
using namespace std;
#define fastIO          {ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define int             long long
#define mod             1000000007
#define PI              3.1415926535897932384626
#define endl            "\n"
#define YES             cout << "YES" << "\n"
#define NO              cout << "NO" << "\n"
#define ispowoftwo(n)   (!(n & (n-1)))
#define pb              push_back
#define ppb             pop_back
 
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
    string a,s;
    bool flag = true,f2 = false;
    int i;
    vector<int> b;
    b.clear();
    cin>>a>>s;
    int j=s.length()-1,num;
    for( i=a.length()-1;i>=0 && j>=0;i--){
        if(a.at(i)>s.at(j)){
            if(j==0 || (int)(s.at(j-1)-'0') == 0){
                flag = false;
                break;
            }
            num = (int)(s.at(j-1)-'0')*10 + (int)(s.at(j)-'0');
            j=j-2;
        }else{
            num = (int)(s.at(j)-'0');
            j--;
        }
        // cout<<num<<" ";
        if(num>18){
            flag = false;
            break;
        }
        b.push_back(num-(int)(a.at(i)-'0'));
        // cout<<b.back();
    }
    // cout<<i<<"  "<<j<<endl;
    if(i!=-1 && j==-1){
        flag = false;
    }
    while(i==-1 && j>=0){
        b.push_back((int)(s.at(j)-'0'));
        j--;
    }
    if(flag){
        for(int i=b.size()-1;i>=0;i--){
            if(b[i]==0){
                if(f2 == false){
                    continue;
                }else{
                    cout<<b[i];
                }
            }else{
                cout<<b[i];
                f2 = true;
            }
        }
    }else{
        cout<<"-1";
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