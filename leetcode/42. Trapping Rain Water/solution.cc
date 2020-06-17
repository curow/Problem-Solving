class Solution {
public:
    int trap(vector<int>& height) {
        int n = size(height);
        int total = 0;
        for (int i = 0; i + 1 < n; ++i) {
            if (height[i] == 0) continue;
            int rain = 0;
            int high_right = 0, high_right_index = i + 1, high_right_rain = 0;
            bool found_higher = false;
            for (int j = i + 1; j < n; ++j) {
                if (height[j] >= height[i]) {
                    found_higher = true;
                    rain += (j - i - 1) * height[i];
                    total += rain;
                    i = j - 1;
                    break;
                } else {
                    if (height[j] > high_right) {
                        high_right = height[j];
                        high_right_index = j;
                        high_right_rain = rain;
                    }
                    rain -= height[j];
                }
            }
            if (!found_higher) {
                total += high_right_rain + (high_right_index - i - 1) * high_right;
                i = high_right_index - 1;
            }
        }
        return total;
    }
};
