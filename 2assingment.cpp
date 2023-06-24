Q1- Answer
   int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
             sum+=nums[i];
            }
        }
        return sum;
    }
Q2- Answer
 int distributeCandies(vector<int>& c) {
        set<int> s;
        for(int i=0;i<c.size();i++){
            s.insert(c[i]);
        }
        if(c.size()/2<s.size()){
            return c.size()/2;
        }
        return s.size();
    }
Q3- Answer
   int findLHS(vector<int>& nums) {
		unordered_map<int, int> tmp;
		int maxSub = 0;
		for (auto num: nums)
		{
			++tmp[num];
		}
		
		for (auto & [ num, value ]: tmp)
		{
			if ( tmp.end() != tmp.find(num - 1) )
				if( maxSub < tmp[num - 1] + value )
					maxSub = tmp[num - 1] + value;
		}
		return maxSub;
	}

Q4-answer

bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
    int count = 0;
    int size = flowerbed.size();
    int i = 0;

    while (i < size) {
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) &&
            (i == size - 1 || flowerbed[i + 1] == 0)) {
            flowerbed[i] = 1;
            count++;
            i += 2;  // Skip the next position since we cannot plant adjacent flowers
        } else {
            i++;
        }

        if (count >= n) {
            return true;
        }
    }

    return false;
}

Q5- Answer

int maximumProduct(std::vector<int>& nums) {
  sort(nums.begin(), nums.end());

    int n = nums.size();
    int product1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
    int product2 = nums[0] * nums[1] * nums[n - 1];

    return max(product1, product2);
}


Q6- Answer
int search(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;  
}

Q7- Answer
bool isMonotonic(std::vector<int>& nums) {
    bool increasing = true;
    bool decreasing = true;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i - 1]) {
            increasing = false;
        }
        if (nums[i] > nums[i - 1]) {
            decreasing = false;
        }
    }

    return increasing || decreasing;
}

Q8-Answer
int minimumScore(std::vector<int>& nums, int k) {
    int minNum = nums[0];
    int maxNum = nums[0];


    for (int i = 1; i < nums.size(); i++) {
        minNum = std::min(minNum, nums[i]);
        maxNum = std::max(maxNum, nums[i]);
    }

    int initialScore = maxNum - minNum;
    int minScore = initialScore;

potential candidate for modification
    for (int i = 0; i < nums.size(); i++) {
       after modifying nums[i]
        int newMinNum = std::min(minNum, nums[i] + k);
        int newMaxNum = std::max(maxNum, nums[i] - k);
maximum values result in a smaller score
        minScore = std::min(minScore, newMaxNum - newMinNum);
    }

    return minScore;
}


