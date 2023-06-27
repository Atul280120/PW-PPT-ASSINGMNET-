assingment 3
answer 1

int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    int closestSum = INT_MAX; 
    int minDiff = INT_MAX; 

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            int diff = abs(sum - target);

          
            if (diff < minDiff) {
                closestSum = sum;
                minDiff = diff;
            }

            
            if (sum < target)
                left++;
            else if (sum > target)
                right--;
            else
                return target; 
        }
    }

    return closestSum;
}
  
answer 2;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> result;
    
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        
        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            
            int left = j + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                
                if (sum < target)
                    left++;
                else if (sum > target)
                    right--;
                else {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    
                    left++;
                    right--;
                }
            }
        }
    }
    
    return result;
}


answer 3:-
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        int j = n - 1;

        while (j > i && nums[j] <= nums[i]) {
            j--;
        }

        swap(nums[i], nums[j]);
    }

    reverse(nums.begin() + i + 1, nums.end());
}

answer 4:-
int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return left;
}

answer  5:-
vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    
    for (int i = n - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        }
        
        digits[i] = 0;
    }
    
    digits.insert(digits.begin(), 1);
    
    return digits;
}
answer 6:
int singleNumber(vector<int>& nums) {
    int result = 0;
    
    for (int num : nums) {
        result ^= num;
    }
    
    return result;
}
answer 7:-

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> ranges;
    
    auto addRange = [&](long long start, long long end) {
        if (start > end) return;
        
        if (start == end) {
            ranges.push_back(to_string(start));
        } else {
            ranges.push_back(to_string(start) + "->" + to_string(end));
        }
    };
    
    addRange(static_cast<long long>(lower), static_cast<long long>(nums[0]) - 1);
    
    for (int i = 1; i < nums.size(); i++) {
        addRange(static_cast<long long>(nums[i - 1]) + 1, static_cast<long long>(nums[i]) - 1);
    }
    
    addRange(static_cast<long long>(nums.back()) + 1, static_cast<long long>(upper));
    
    return ranges;
}

answer 8:-
bool canAttendMeetings(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
    
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < intervals[i - 1][1]) {
            return false;
        }
    }
    
    return true;
}



