class Solution {
public:
    bool isValid(string s) {
        char arr[10000];
        int k = 0;
     for(int i=0;s[i] != '\0';i++){
        char ch = s[i];
        if(ch == '(' || ch== '{' || ch == '[')
            arr[k++] = ch;
        else{
            if(k==0)
            return false;
            
            char a = arr[--k];

            if(( ch == ')' && a != '(') || (ch == ']' && a != '[') || (ch == '}' && a != '{'))
            return false;
        }
     }
        return k==0;

    }
        

       
};