class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        reverse_string(s,i);
    }
    void reverse_string(vector<char>& s, int i){
        if(i>=(s.size()/2)){
            return;
        }
        swap(s[i],s[s.size()-i-1]);
        reverse_string(s, i+1);
    }
};