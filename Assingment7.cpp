Q1-
   bool isIsomorphic(string s, string t) 
    {
         unordered_map<char, char> mp, mp2;
        for (int i=0; i<s.length(); ++i) 
        {
            if (mp[s[i]] && mp[s[i]]!=t[i]) return false;
            if (mp2[t[i]] && mp2[t[i]]!=s[i]) return false;
            mp[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        return true;
    }

Q2-
bool isStrobogrammatic(string num) {
        unordered_map<char, char> lut{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        for (int l = 0, r = num.size() - 1; l <= r; l++, r--) {
            if (lut.find(num[l]) == lut.end() || lut[num[l]] != num[r]) {
                return false;
            }
        }
        return true;
    }
 Q3- 
string addstring(string& s1,string& s2,int i,int j,int& c,string& ans){
        if(c==0&&i<0&&j<0){
            reverse(ans.begin(),ans.end());
            return ans;
        }
        if(i>=0){
            c+=s1[i]-'0';
            i--;
        }
        if(j>=0){
            c+=s2[j]-'0';
            j--;
        }
        ans+=char(c%10+'0');
        c=c/10;
        return addstring(s1,s2,i,j,c,ans);
    }
   string addStrings(string num1, string num2) {
        int c=0,i=num1.length()-1,j=num2.length()-1;
        string ans="";
       return addstring(num1,num2,i,j,c,ans);
       
    }
Q4-
string reverseWords(string s) {
      stringstream ss(s);
        string temp,ans;
        while(ss>>temp){
            reverse(temp.begin(),temp.end());
            ans+= (temp+" ");
        }
        
        return ans.substr(0,ans.size()-1);
    }
Q5-
  string reverseStr(string s, int k) {
        
        int l=0;
        int r = min(k,(int)s.length());
        while( l < s.length() ){
            
            reverse(s.begin()+l,s.begin()+r);
            l+=2*k;
            r=min(k+l,(int)s.size());
        }
        return s;
    }
Q6-
  bool solve(string s,string goal){
  if (s.size() != goal.size())
      return false;

    for (int i = 0; i < s.size(); ++i)
    {
      if (s == goal)
        return true;
      s = s.substr(1) + s[0];
    }

    return false;
  }
Q7-
  bool backspaceCompare(string s, string t) {
        stack <char> s1;
        stack <char> s2;

        for(int i = 0; i < s.size(); i++){
            s1.push(s[i]);
            if(s1.top() == '#'){
                s1.pop();
                if(!s1.empty())
                    s1.pop();
            }
        }
        for(int i = 0; i < t.size(); i++){
            s2.push(t[i]);
            if(s2.top() == '#'){
                s2.pop();
                if(!s2.empty())
                    s2.pop();
            }
        }

        if(s1.size() != s2.size())
            return false;

        while(!s1.empty() && !s2.empty()){
            if(s1.top() != s2.top())
                return false;
            s1.pop();
            s2.pop();
        }
        return true;
    }
Q8- Answer
bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()<=1)return 1;
        int x = coordinates[1][0]-coordinates[0][0];
        int y = coordinates[1][1]-coordinates[0][1];
        auto good = [&](vector<int>&v)->bool{
            return x*(v[1]-coordinates[1][1]) == y*(v[0]-coordinates[1][0]);
        };
        int n = coordinates.size();
        for(int i = 1;i<n;i++){
            if(!good(coordinates[i]))return false;
        }
        return true;
    }
