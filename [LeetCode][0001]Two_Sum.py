"""
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
"""

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_dict = dict()
        nums_bidict = dict()
        it = 0
        nums_size = len(nums)
        while it < nums_size:
            nums_dict[it] = nums[it]
            nums_bidict[nums[it]] = it
            it += 1
        
        it = 0
        values = set(nums)
        while it < nums_size:
            ret = target - nums_dict[it]
            if ret in values and it != nums_bidict[ret]:
                return [it, nums_bidict[ret]]
            it += 1

