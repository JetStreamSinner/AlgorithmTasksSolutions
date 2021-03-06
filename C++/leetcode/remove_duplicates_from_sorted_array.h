#pragma once

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.
// The relative order of the elements should be kept the same.
// Since it is impossible to change the length of the array in some languages, you must instead have the result be placed
// in the first part of the array nums. More formally, if there are k elements after removing the duplicates,
// then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
// Return k after placing the final result in the first k slots of nums.
// Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

class Solution {
public:

    int customSolution(std::vector<int>& nums) {
        const auto end_iter = nums.end();
        const auto last_value = nums.back();
        auto forwarder = nums.begin();
        auto sorted = forwarder;

        while (*sorted != last_value) {
            forwarder = std::find_if(forwarder, end_iter, [&](auto value) {
                return value != *sorted;
            });
            sorted = std::next(sorted);
            *sorted = *forwarder;
        }

        const auto unique_range = std::distance(nums.begin(), sorted) + 1;
        return unique_range;
    }

    int stlWaySolution(std::vector<int>& nums) {
        auto duplicatesFrom = std::unique(nums.begin(), nums.end());
        const auto result = std::distance(nums.begin(), duplicatesFrom);
        return result;
    }

    int removeDuplicates(std::vector<int>& nums) {
        return customSolution(nums);
    }
};