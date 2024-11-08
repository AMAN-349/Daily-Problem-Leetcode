/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    if(!nums.length) return init;
    for(var i=0;i<nums.length;i++)
    {
        init=fn(init,nums[i]);
    }
    return init;
};