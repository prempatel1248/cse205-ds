class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1 = "";
        string str2 = "";
        for(int i=0; i<=(word1.size()-1); i++){
            str1 = str1 + word1[i];
        }
        for(int i=0; i<=(word2.size()-1); i++){
            str2 = str2 + word2[i];
        }
        if(str1==str2){
            return true;
        }
        else{
            return false;
        }

    }
};