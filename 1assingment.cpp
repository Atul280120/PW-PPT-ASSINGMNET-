Q1. Answer-
#include<bits/stdc++.h>
using namespace std;
#define ll long long 

void solve(vector<int>& arr, int t) {
    vector<int> indices;
    unordered_map<int, int> mp; 
    for (int i = 0; i < arr.size(); i++) {
        mp[arr[i]] = i; 
    }
    for (int i = 0; i < arr.size(); i++) {
    int complement = t - arr[i];
            if (mp.count(complement) && mp[complement] != i) {
                 cout<<i<<" "<<mp[complement];
                 break;
            }   
        
}
}


int main() {
    int n, t;
    cin >> n >> t;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    solve(arr, t);
    
    return 0;
}

Q2 - answer
#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int removeElement(vector<int>& nums, int val) {
     int  t=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[t]=nums[i];
                t++;
            }
        }
        
        return t;
    }


int main() {
    int n, t;
    cin >> n >> t;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    removeElement(arr, t);
    
    return 0;
}

Q3 - answer -
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int searchInsert(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 2;

    int insertIndex = searchInsert(nums, target);
    cout<<"Insert index: "<< insertIndex<<endl;

    return 0;
}

Q4 - Answer
#include<bits/stdc++.h>
using namespace std;
#define ll long long 

void plusOne(vector<int>& v) {
        int n = v.size();
        for(int i = n-1; i >= 0; i--){
            if(i == n-1)
                v[i]++;
            if(v[i] == 10){
                v[i] = 0;
                if(i != 0){
                    v[i-1]++;
                }
                else{
                    v.push_back(0);
                    v[i] = 1;
                }
            }
        }
       for(auto x:v){
        cout<<x<<endl;
       }
    }

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
       cin>>arr[i];
    }
    
    plusOne(arr);
    return 0;
}

Q5- answer
#include<bits/stdc++.h>
using namespace std;
#define ll long long 

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
               int p1=m-1,p2=n-1,i=m+n-1;
        while(p2>=0){
            if(p1>=0 && nums1[p1]>nums2[p2]){
                nums1[i--]=nums1[p1--];
        }
        else{
            nums1[i--]=nums2[p2--];
        }
    }
}

int main() {
    int n,m;
    cin >> n,m;
    vector<int> arr1(n),arr2(m);
    for (int i = 0; i < n; i++) {
       cin>>arr1[i];
    }
     for (int i = 0; i < n; i++) {
       cin>>arr2[i];
    }
  merge(arr1,n,arr2,m);
  for(auto x:arr1){
    cout<<x<<" ";
  }
  cout<<endl;
    return 0;
}

Q6:-
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
       cin >> arr[i];
    }
    vector<bool> freq(n, false);
    for(int i = 0; i < n; i++) {
        if(freq[arr[i]] == true) {
            cout << arr[i] << endl;
            break;
        }
        else {
            freq[arr[i]] = true;
        }
    }
    return 0;
}
Q7- answer
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
       cin >> arr[i];
    }
 
        int start=0, end=n-1,mid=0;
        while(mid<=end){
            if(arr[mid]!=0){
                swap(arr[start],arr[mid]);                  
                    start++;
            }
            mid++;
        }
    
    for(auto x:arr){
        cout<<x<<" ";
    }
    return 0;
}

Q8- answer

#include<bits/stdc++.h>


using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    vector<int> result(2, 0);
    unordered_set<int> seen;
    int n = nums.size();
    int sum = (n * (n + 1)) / 2;
    int duplicate = 0;

    for (int num : nums) {
        if (seen.count(num)) {
            duplicate = num;
        }
        sum -= num;
        seen.insert(num);
    }

    result[0] = duplicate;
    result[1] = duplicate + sum;

    return result;
}

int main() {
    vector<int> nums = {1, 2, 2, 4};
    vector<int> result = findErrorNums(nums);

    cout << result[0]<<" "<<result[1]  << endl;
   

    return 0;
}
