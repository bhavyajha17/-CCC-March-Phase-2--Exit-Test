def kSub(k, nums):
    count = 0
    prefix_sum = [0] * (len(nums) + 1)
    frequency = [0] * k
    frequency[0] = 1
    for i in range(1, len(prefix_sum)):
        prefix_sum[i] = prefix_sum[i-1] + nums[i-1]
        remainder = prefix_sum[i] % k
        count += frequency[remainder]
        frequency[remainder] += 1
    return count
