#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

bool linear_search(vector<int> nums, int target) {
    for (int num : nums)
        if (num == target) return true;
    
    return false;
}

int main(void) {
    vector<int> nums = { 2, 3, 1, 5, 6, 7, 4, 8 };

    assert(linear_search(nums, 3) == true);
    assert(linear_search(nums, 10) == false);
    assert(linear_search(nums, 4) == true);

    return 0;
}