int  lengthOfLongestSubstring(string s) {
        map<int,int> v;
        int current=0,ans=0;
        int i=0;
        for(auto it : s){
            if(v[it-'a']!=0){
                ans=max(current,ans);
                current=0;
                v.clear();
                v[it-'a']++;
                current++;
            }
            else{
                v[it-'a']++;
                current++;
                ans=max(current,ans);
            }
            i++;
        }
        return ans;
}