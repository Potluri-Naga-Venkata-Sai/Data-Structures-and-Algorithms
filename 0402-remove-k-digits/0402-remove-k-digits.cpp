class Solution {
public:
    string removeKdigits(string num, int k) {
        // we have to use monotonic stack...
        string st = "";
        for(char c: num){
            while(!st.empty() && st.back() > c && k > 0){
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }
        while(k > 0){
            st.pop_back();
            k--;
        }
        int i = 0;
        while(i < st.size() && st[i] == '0'){
            i++;
        }
        st = st.substr(i);
        if(st.empty()){
            return "0";
        }
        return st;
    }
};