#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;

bool binary_search(vector<int> nums, int target) {
    int left_index, mid_index = 0;
    int right_index = nums.size() - 1;

    while (left_index <= right_index) {
        mid_index = floor((left_index + right_index) / 2);
        
        if (nums[mid_index] < target) left_index = mid_index + 1;
        else if (nums[mid_index] > target) right_index = mid_index - 1;
        else return true;
    }
    
    return false;
}

int main(void) {
    vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    assert(binary_search(nums, 2) == true);
    assert(binary_search(nums, 10) == false);
    assert(binary_search(nums, 9) == true);

    return 0;
}
