class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        
        int x =0;
        int c = 0;
        for(int i=0;i<operations.size();i++){

            if(operations[i] == "--X") c = 1;
            else if(operations[i] == "X--") c=2;
            else if(operations[i] == "++X") c=3;
            else if(operations[i] == "X++") c=4;

            switch(c){

                case 1 : x = x-1;break;
                case 2 : x = x-1;break;
                case 3 : x = x+1;break;
                case 4 : x = x+1;break;


            }

            c=0;
        }

        return x;
    }
};