class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        std::sort(envelopes.begin(), envelopes.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        std::vector<int> heights;
        for(const auto& envelope : envelopes) {
            heights.push_back(envelope[1]);
        }

        return findLIS(heights);
    }

    int findLIS(const std::vector<int>& heights ){
        int n = heights.size();
        std::vector<int> dp(n,1);
        int maxLength = 1;

        for(int i = 1; i<n; ++i){
            for(int j = 0; j < i; ++j){
                if(heights[i] > heights[j]){
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            maxLength = std::max(maxLength, dp[i]);
        }
        return maxLength;
    }
};
