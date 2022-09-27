int bagOfTokensScore(vector<int> &tokens,int power){
    sort(tokens.begin(),tokens.end());
    int start=0,end=tokens.size()-1,ans=0,score=0;
    while(start<=end){
        while(start<=end && tokens[start] <= power){
            score++;
            power -= tokens[start];
            start++;
        }
        if(start>=end) break;
        score-=1;
        power += tokens[end];
        end--;
    }
    return score;
}