/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const filtered=[];
    for(var i=0;i<arr.length;i++)
    {
        if(fn(arr[i],i))
        {
            filtered.push(arr[i]);
        }
    }
    return filtered;
};