#include<vector>
#include<iostream>
using namespace std;

int solve(string s1, string s2, int n1, int n2, int i, int j, int used, vector<vector<vector<int>>> &dp){
    
    if(i >= n1 || j >= n2)
    return 0;

    if(dp[i][j][used] != -1)
    return dp[i][j][used];
    
    if(s1[i] == s2[j]){
    dp[i][j][used] = 1 + solve(s1,s2,n1,n2,i+1,j+1,used,dp);
    return dp[i][j][used];
    }

    int ans1 = solve(s1,s2,n1,n2,i+1,j,used,dp);
    int ans2 = solve(s1,s2,n1,n2,i,j+1,used,dp);
    
    dp[i][j][used] = max(ans1,ans2);

    if(used == 0){
        int ans3 = 1 + solve(s1,s2,n1,n2,i+1,j+1,1,dp);
        dp[i][j][used] = max(dp[i][j][used],ans3);
    }
    return dp[i][j][used];
}

int solve2(string s1, string s2, int n1, int n2){

    vector<vector<int>> curr(n2+1,vector<int>(2,0));
    vector<vector<int>> next(n2+1,vector<int>(2,0));

    for(int i = n1-1; i>= 0; i--){
        for(int j = n2-1; j>= 0; j--){
            for(int used = 0; used <=1; used++){
                if(s1[i] == s2[j]){
                    curr[j][used] = 1 + next[j+1][used];
                }
                else{

                    int ans1 = next[j][used];
                    int ans2 = curr[j+1][used];
                    
                    curr[j][used] = max(ans1,ans2);

                    if(used == 0){
                        int ans3 = 1 + next[j+1][1];
                        curr[j][used] = max(curr[j][used],ans3);
                    }
                }
            }
        }
        next = curr;
    }

    return next[0][0];
}


int IncreaseLCSBy1(int N1, string S1, int N2, string S2) {
    
    vector<vector<vector<int>>> dp(N1+1,vector<vector<int>>(N2+1,vector<int>(2,-1)));
    return solve2(S1,S2,N1,N2);

}

int main(){

    string s1;
    cout << "Enter string 1 :";
    cin >> s1;
    string s2;
    cout << "Enter string 2 :";
    cin >> s2;
    int n1 = s1.size();
    int n2 = s2.size();

    cout << IncreaseLCSBy1(n1,s1,n2,s2) << endl;
}


