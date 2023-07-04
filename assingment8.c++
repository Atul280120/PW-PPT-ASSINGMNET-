// Q1

	int minimumDeleteSum(string s1, string s2) {
		int n=s1.size();
		int m=s2.size();
		int sum1=0,sum2=0;
		for(auto i:s1) sum1+=i;
		for(auto i:s2) sum2+=i;
		vector<vector<int>> dp(n+1,vector<int>(m+1,0));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(s1[i-1]==s2[j-1]) dp[i][j]=s1[i-1]+dp[i-1][j-1];
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}   
		}
		return (sum1+sum2)-2*dp[n][m];
	}


// Q2-
  bool f(int i, string &s,int br){
        if(i>=s.size()){
            return br==0;
        }

        if(br<0){
            return false;
        }

        bool take=false;
        // 3 options
        if(s[i]=='*'){
            take= take | f(i+1,s,br+1);  // add '(' 
            if(br) take = take | f(i+1,s,br-1);  // add ')' but cond there must be any opening bracket
            take = take | f(i+1,s,br);  // doing nothing
        }else{
            if(s[i]=='(') take = take | f(i+1,s,br+1);
            else take= take | f(i+1,s,br-1);
        }
        return take;
    }

    bool checkValidString(string s) {
        return f(0,s,0);
    }
//  q3-
int minDistance(string t1, string t2) {
     vector<vector<int>> dp(t1.size()+1,vector<int>(t2.size()+1));
        for(int i=0;i<t1.size()+1;i++){
            for(int j=0;j<t2.size()+1;j++){
                if(i==0 ){
                    dp[i][j]=j;
                }
                else if(j==0){
                    dp[i][j]=i;
                }
                else if(t1[i-1]==t2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                    
                }
                else{
                    dp[i][j]=1+min(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[t1.size()][t2.size()];
    }

//Q4-
string tree2str(TreeNode* node) {
        string res = "";

        if (node == nullptr) return res;

        res += to_string(node->val);

        if (node->left || node->right) {
            res += "(";
            res += tree2str(node->left);
            res += ")";
        }
        
        if (node->right) {
            res += "(";
            res += tree2str(node->right);
            res += ")";
        }

        return res;    
    }
// Q5-

int compress(vector<char>& chars) {
        int n=chars.size();
        int cnt=1;
        char temp=chars[0];
        int i=1,j=0;
        while(i<n){
            if(chars[i]==temp){
                cnt++;
            }
            else{
                chars[j++]=temp;
                if(cnt>1){
                    int start=j;
                    while(cnt){
                        chars[j++]=(cnt%10)+'0';
                        cnt/=10;
                    }
                    reverse(chars.begin()+start,chars.begin()+j);
                    cnt=1;
                }
                temp=chars[i];
            }
            i++;
        }
        chars[j++]=temp;
        if(cnt>1){
            int start=j;
            while(cnt){
                chars[j++]=(cnt%10)+'0';
                cnt/=10;
            }
            reverse(chars.begin()+start,chars.begin()+j);
            // cnt=1;
        }
        return j;
    }

// Q6-
  vector<int> findAnagrams(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        
        if(s.size() < p.size()) return {};
        
        vector<int> freq_p(26,0);
        vector<int> window(26,0);
        
        //first window
        for(int i=0;i<p_len;i++){
            freq_p[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        
        vector<int> ans;
        if(freq_p == window) ans.push_back(0);
        
        for(int i=p_len;i<s_len;i++){
            window[s[i-p_len] - 'a']--;
            window[s[i] - 'a']++;
            
            if(freq_p == window) ans.push_back(i-p_len+1);
        }
        return ans;
    }

// Q7
string decodeString(string s) {
    stack<string> chars;
    stack<int> nums;
    string res;
    int num = 0;
    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '[') {
            chars.push(res);
            nums.push(num);
            res = "";
            num = 0;
        } else if (c == ']') {
            string tmp = res;
            res = chars.top();
            chars.pop();
            for (int i = nums.top(); i > 0; i--) res += tmp;
            nums.pop();
        } else {
            res += c;
        }
    }
    return res;
}
// Q8-
bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length() || s.length() <= 1) {
            return false;
        }

        if (s == goal) {
            unordered_set<char> distinctChars(s.begin(), s.end());
            return distinctChars.size() < s.length();
        }

        vector<int> index;
        for (int i=0;i<s.length();i++) {
            if (s[i] != goal[i]) {
                index.push_back(i);
            }
        }

        if (index.size() != 2) {
            return false;
        }

        swap(s[index[0]], s[index[1]]);
        return;
