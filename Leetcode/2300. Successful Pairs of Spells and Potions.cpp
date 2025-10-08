class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        sort(potions.begin(),potions.end());
        vector<int>pairs;
        int m = potions.size();
        int count  = m;

        for(int i : spells){
        long long need = (success + i - 1) /i;
        
        int s = 0;
        int e = m-1;
        int mid = s + (e-s)/2;

        while(s<=e){
            if(potions[mid]>=need){
                count = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        pairs.push_back(m-count);
        count = m;

        }
        return pairs;   
    }
};