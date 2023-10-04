#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        int a[9][9];
        for(int i=1;i<9;i++){
            for(int j=1;j<9;j++){
                a[i][j]=0;
            }
        }
        a[x][y]=1;
        if(x==1 && y==1){
            a[3][2]=2;
        }
        else if(x==8 && y==1){
            a[6][2]=2;
        }
        else if(x==1 && y==8){
            a[3][7]=2;
        }
        else if(x==8 && y==8){
            a[6][7]=2;
        }
        else if(x==1){
            a[3][y+1]=2;
            a[3][y-1]=2;
        }
        else if(x==8){
            a[6][y+1]=2;
            a[6][y-1]=2;
        }
        else if(y==1){
            a[x-1][3]=2;
            a[x+1][3]=2;
        }
        else if(y==8){
            a[x-1][6]=2;
            a[x+1][6]=2;
        }
        else{
            a[x-2][y+1]=2;
            a[x-2][y-1]=2;
            a[x+2][y+1]=2;
            a[x+2][y-1]=2;
        }
        for(int i=1;i<9;i++){
            for(int j=1;j<9;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    return 0;
}
