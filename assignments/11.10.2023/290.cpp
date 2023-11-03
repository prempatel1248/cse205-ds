class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string>mp;
        string str = "";
        int j=0;
        for(int i=0; i<s.size();i++){
            if(s[i]==' ' || i==s.size()-1){
                if(i==s.size()-1){
                    str = str+s[i];
                }
                for(int i=0; i<str.size(); i++){
                    cout<<str[i];
                }
                cout<<endl;
                if(mp[pattern[j]]==str || mp[pattern[j]]==""){
                    if(mp[pattern[j]]==""){
                        mp[pattern[j]]=str;
                    }
                    str.clear();
                }
                else{
                    return false;
                }
                j++;
            }
            else{
                str = str+s[i];
            }
        }
        for(auto x:mp){
            for(auto y:mp){
                if(x.second==y.second && x.first!=y.first){
                    return false;
                }
            }
        }
        if(j != pattern.size()){
            return false;
        }
        return true;
    }
};