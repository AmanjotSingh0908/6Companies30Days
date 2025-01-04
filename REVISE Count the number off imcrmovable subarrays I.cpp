class Solution {
public:
    
    int incremovableSubarrayCount(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        int count = 0;
        int length = 1;

        for(int i = 1; i < n; i++){
            if(arr[i] > arr[i - 1]){
                ++length;
            } else {
                count += length * (length + 1) / 2;
                length = 1; //reset
            }
        }
        count += length * (length + 1) / 2;
        return count;
    }
};

//Passes all test cases
class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                bool flag = true;
                int last = -1;

                for (int k = 0; k < i; k++) {
                    if (last >= nums[k]) {
                        flag = false;
                        break;
                    }
                    last = nums[k];
                }

                for (int k = j + 1; k < n; k++) {
                    if (last >= nums[k]) {
                        flag = false;
                        break;
                    }
                    last = nums[k];
                }

                if (flag) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
