class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans = strs[0];
        for(int i=0;i<strs.size();i++){
            int a = strs[i].size();
            int j=0;
            while(j<a && j<ans.size()){
                if(ans[j] != strs[i][j]){
                    break;
                }
                j++;
            }
                ans = ans.substr(0, j);
                if (ans.empty()) 
                return ans;
            
        }
        return ans;
        

    }
};