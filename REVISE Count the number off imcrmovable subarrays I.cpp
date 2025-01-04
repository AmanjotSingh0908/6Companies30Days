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
