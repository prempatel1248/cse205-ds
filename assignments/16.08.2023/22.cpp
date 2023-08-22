class Solution {
public:
    string str_mul(int a, string s){
        string output="";
        while(a>0){
            output = output + s;
            a=a-1;
        }
        return output;
    }
    void parent(int i, int j, int k, int n, string str, vector<string>& ans){
        if(j==n){
            ans.push_back((str)+str_mul(j-k, ")"));
            return;
        }
        str = str + "(";
        j=j+1;
        parent(i+1, j, k, n, str, ans);
        str.erase(str.begin()+str.length()-1);
        j=j-1;
        if(j>k){
            str = str + ")";
            k=k+1;
            parent(i+1, j, k, n, str, ans);
            str.erase(str.begin()+str.length()-1);
            k=k-1;
        }
    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string> ans;
        parent(0, 0, 0, n, str, ans);
        return ans;
    }
};