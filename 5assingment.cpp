Assingment 4
 Answer 1-
vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans(m,vector<int> (n));
int k=0;
if( m * n != original.size()){
return {};
}
else{
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
ans[i][j]=original[k];
k++;
}
}
return ans;
    }
    }

Answer 2-

  int arrangeCoins(int n) {
       long long i=0;
      long long j=n;
      
        while(i<=j)
        {
            long long m=(i+j)/2;
            if((m*(m+1))/2 >n)
            j=m-1;
            else
            {
                i=m+1;
              
            }
        }
        return (int)i-1;
    }

Answer 3-

 vector<int> sortedSquares(vector<int>& nums) {
       int left=0, right=nums.size()-1;
        vector<int> res(nums.size(),0);
        int i=res.size()-1;
        while(left<=right)
        {
            int leftp=pow(nums[left],2), rightp=pow(nums[right],2);
            if(leftp>=rightp) 
            {
                res[i]=leftp;
                left++;
                i--;
            }
            else
            {
                res[i]=rightp;
                right--;
                i--;
            }
        }
        return res;
    
    }

Answer 4-

   vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int ,int > mp1,mp2;
        vector<vector<int>> v(2);
        for(int i=0;i<nums1.size();i++){
            mp1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            mp2[nums2[i]]++;
        }
        for(auto x:mp1){
            if(!mp2[x.first]){
                v[0].push_back(x.first);
            }
        }
        for(auto x:mp2){
            if(!mp1[x.first]){
                v[1].push_back(x.first);
            }
        }
        return v;
    }

Answer 5

 int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
     sort(arr2.begin(),arr2.end());
         int result = 0;
         for(int i = 0; i<arr1.size(); i++)
        {
          int low = 0;
          int high = arr2.size()-1;
          while(low <= high)
          {
             int mid=low +(high-low)/2;
             if(abs(arr1[i]-arr2[mid]) <= d)
             {
                 break;
             }if(arr2[mid] < arr1[i]){
                 low = mid +1;
             }else{
                 high = mid-1;
             }
          }
          if(low > high){
              result++;
          }
        }
     return result;
    }
 
Answer 6-
vector<int> findDuplicates(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while(i < n) {
            int correct = i+1;
            if(nums[i] == correct) {
                i++;
            } else {
                int position = nums[i] - 1;
                if(nums[i] == nums[position]) {
                    //repeating hai ye
                    i++;
                } else {
                    swap(nums[i], nums[position]);
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(nums[i] != i+1) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
Answer 7-
int findMin(vector<int>& nums) {
            if(nums.size()==1)
            return nums[0];
        
        int left=0, right = nums.size()-1;
        
        if(nums[right]>nums[0])
            return nums[0];
        
        while(right>=left)
        {
            int mid = left + (right-left)/2;
            
            if(nums[mid]>nums[mid+1])
                return nums[mid+1];
            
            if(nums[mid-1]>nums[mid])
                return nums[mid];
            
            if(nums[mid]>nums[0])
                left = mid+1;
            
            else{
                right=mid-1;
            }
        }
        return -1;
        
    }

Answer 8-
vector<int> findOriginalArray(vector<int>& changed) {
        int n= changed.size();
        if (n&1)return {};
        vector<int> ans;
        map<int,int> mp;
        sort(changed.begin(),changed.end(),greater<int>());
        for (int i=0; i<n; i++){
            if (mp.find(changed[i]*2)!=mp.end()){
                if (mp[changed[i]*2]>0){mp[changed[i]*2]--;}
                ans.push_back(changed[i]);
                if (mp[changed[i]*2]==0) {mp.erase(changed[i]*2);}
                }
            else {mp[changed[i]]++;}
        }
        for (auto val: mp){
            if (val.second!=0)return {}; 
        }
        return ans;
    }


