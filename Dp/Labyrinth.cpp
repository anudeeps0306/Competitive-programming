#include <bits/stdc++.h>
using namespace std;



bool check(int i,int j,vector<vector<char>> &v){
    if(i>=0 && i<v.size() && j>=0 && j<v[0].size() && v[i][j]=='.'){
        return true;
    }
    if(i>=0 && i<v.size() && j>=0 && j<v[0].size() && v[i][j]=='B'){
        return true;
    }

    return false;

}



void dfsa(){

}


int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<char>> v(n,vector<char>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }

    queue<pair<int,int>> q;
    int start1,start2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='A'){
                start1=i;
                start2=j;
                q.push({i,j});
                break;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='B'){
                // cout<<i<<" "<<j<<endl;
                break;
            }
        }
    }
    vector<vector<int>> v1(n,vector<int>(m,0));

    map<pair<pair<int,int>,char>,pair<pair<int,int>,char>> m1;

    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
      
        v1[i][j]=1;
        q.pop();
        // cout<<start1<<" "<<start2<<endl;
        if(v[i][j]=='B'){
            // int index1=i,index2=j;
            // while(start1!=index1 && start2!=index2){
             
            //     index1=m1[{index1,index2}].first;
            //     index2=m1[{index1,index2}].second;
            // }
            
        }

        if(check(i+1,j,v) && !v1[i+1][j]){
            q.push({i+1,j});
            m1[{i+1,j}]={i,j,'D'};
        }
        if(check(i-1,j,v) && !v1[i-1][j]){
            q.push({i-1,j});
            m1[{i-1,j}]={i,j};
        }
        if(check(i,j+1,v) && !v1[i][j+1]){
            q.push({i,j+1});
            m1[{i,j+1}]={i,j};
        }
        if(check(i,j-1,v) && !v1[i][j-1]){
            q.push({i,j-1});
            m1[{i,j-1}]={i,j};
        }
        
    }

    for(auto it : m1){
        cout<<it.first.first<<" "<<it.first.second<<" "<<it.second.first<<" "<<it.second.second<<endl;
    }

    // for(auto it : v1){
    //     for(auto it1 : it){
    //         cout<<it1<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}