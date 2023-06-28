                            ALL ANSWER ARE ONLY FUNCTION INPUT IS GIVEN
Answer 1:-
vector<int> findCommonElements(const std::vector<int>& arr1, const std::vector<int>& arr2, const vector<int>& arr3) {
    int i = 0, j = 0, k = 0;
    vector<int> result;

    while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            result.push_back(arr1[i]);
            i++;
            j++;
            k++;
        } else if (arr1[i] < std::min(arr2[j], arr3[k])) {
            i++;
        } else if (arr2[j] < std::min(arr1[i], arr3[k])) {
            j++;
        } else if (arr3[k] < std::min(arr1[i], arr2[j])) {
            k++;
        }
    }

    return result;
}

Answer 2:
vector<std::vector<int>> findDistinctElements(const std::vector<int>& nums1, const std::vector<int>& nums2) {
  unordered_set<int> set1(nums1.begin(), nums1.end());
   unordered_set<int> set2(nums2.begin(), nums2.end());
    vector<int> result1, result2;

    for (int num : set1) {
        if (set2.find(num) == set2.end()) {
            result1.push_back(num);
        }
    }

    for (int num : set2) {
        if (set1.find(num) == set1.end()) {
            result2.push_back(num);
        }
    }

    return {result1, result2};
}

Answer 3-
vector<std::vector<int>> transposeMatrix(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();

   vector<std::vector<int>> result(columns, std::vector<int>(rows));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

Answer 4-
int arrayPairSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int maxSum = 0;
    
    for (int i = 0; i < nums.size(); i += 2) {
        maxSum += nums[i];
    }
    
    return maxSum;
}

Answer 5-
int arrangeCoins(int n) {
    int k = 0;
    long long sum = 0; 

    while (sum + k + 1 <= n) {
        k++;
        sum += k;
    }

    return k;
}

Answer 6-
vector<int> sortedSquares(std::vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);

    int left = 0;
    int right = n - 1;

    for (int i = n - 1; i >= 0; i--) {
        if (abs(nums[left]) >= abs(nums[right])) {
            result[i] = nums[left] * nums[left];
            left++;
        } else {
            result[i] = nums[right] * nums[right];
            right--;
        }
    }

    return result;
}

Answer 7-
int maxCount(int m, int n, const std::vector<std::vector<int>>& ops) {
    int minRow = m;
    int minCol = n;

    for (const std::vector<int>& op : ops) {
        minRow = std::min(minRow, op[0]);
        minCol = std::min(minCol, op[1]);
    }

    return minRow * minCol;
}

Answer 8-
vector<int> shuffleArray(const std::vector<int>& nums, int n) {
    vector<int> result(nums.size());

    for (int i = 0; i < n; i++) {
        result[i * 2] = nums[i];
        result[i * 2 + 1] = nums[i + n];
    }

    return result;
}
