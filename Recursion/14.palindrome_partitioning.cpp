// Leetcode - 131. Palindrome Partitioning

// Time complexity: O((2^n) *k*(n/2))
// Space complexity: O(k*x)   k: avg len of palindrome list, x palindrome lists
// Stack space: O(n)

vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(0, path, s, ans);

        return ans;
    }

    void solve(int idx, vector<string>& path, string& s, vector<vector<string>>& ans){
        if(idx == s.length()){
            ans.push_back(path);
            return;
        }

        for(int i=idx; i<s.length(); i++){
            if(isPalindrome(s, idx, i)){
                path.push_back(s.substr(idx, i-idx+1));
                solve(i+1, path, s, ans);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int start, int end){
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }