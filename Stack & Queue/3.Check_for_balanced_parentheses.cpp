

// Leetcode - 20 - Valid Parentheses
// TC - O(n)
// SC - O(n)


bool isValid(string s) {
        stack<int>st;

        for(int i=0; i<s.length(); i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }else{
                if(st.empty()) return false;
                char ch = st.top();
                st.pop();
                if(!((s[i]==')' && ch=='(') || (s[i]==']' && ch=='[') || (s[i]=='}' && ch=='{'))){
                    return false;
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }