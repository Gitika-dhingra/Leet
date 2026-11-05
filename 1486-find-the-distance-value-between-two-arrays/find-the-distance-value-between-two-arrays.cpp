class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        ranges::sort(arr2);
        arr2.push_back(INT_MAX);  // sentinel: some b is always >= a - d
        auto far = [&](int a) {  // the first b >= a - d is already past a + d
            return *ranges::lower_bound(arr2, a - d) > a + d;
        };
        return ranges::count_if(arr1, far);
    }
};