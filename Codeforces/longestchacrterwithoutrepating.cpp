#include<bits/stdc++.h>

using namespace std;

int  lengthOfLongestSubstring(string s) {
    // int left =0,right=0,longest=0;
    // map<char,int> m;
    // while(right<s.size()){
    //     if(m[s[right]] == 0){
    //         m[s[right]]++;
    //         longest = max(longest,right-left+1);
    //         right++;
    //     }
    //     else{
    //         m[s[left]]--;
    //         left++;
    //     }
    // }
    // return longest;
    return 0;
}

int findComplement(int num) {
        int ans=1;
        while(ans < num){
            ans <<= 1;
            ans += 1;
        }
        ans = ans-num;
    return ans;
}


int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    // cout<<lengthOfLongestSubstring(s);
    cout<<findComplement(n);
    return 0;
}