class Solution {
public:
    string removeStars(string s) {
        stack<char> s1;
        string sv;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='*'){
                s1.pop();
            }
            else{
                s1.push(s[i]);
            }
        }
        while(!s1.empty()){
            sv.push_back(s1.top());
            s1.pop();
        }
        for(int i=0; i<(sv.size()/2); i++){
            swap(sv[i], sv[sv.size()-1-i]);
        }
        return sv;
    }
};