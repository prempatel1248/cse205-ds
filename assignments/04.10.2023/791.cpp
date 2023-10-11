class Solution {
public:
    string customSortString(string order, string s) {
        string ch;
        for(int i=0; i<order.size(); i++){
            for(int j=0; j<s.size(); j++){
                if(order[i]==s[j]){
                    ch.push_back(s[j]);
                }
            }
        }
        string temp;
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<ch.size(); j++){
                if(s[i]==ch[j]){
                    break;
                }
                if(j==ch.size()-1){
                    temp.push_back(s[i]);
                }
            } 
        }
        for(int i=0; i<temp.size(); i++){
            ch.push_back(temp[i]);
        }
        return ch;
    }
};