import math
from typing import List

# 有公因數就輸出 -1
# 沒有公因數，去找到沒有公因數的那兩位，尤其是最短距離的那位，啊這要怎麼不用 on2 解
# 每一步都是要踢掉非共同因數


class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        best_step = 10**9

        for begin in range(0, n - 1):
            if math.gcd(*nums[begin:]) != 1:
                continue
            GCD = []
            # GCD = [math.gcd(Minus[i], Minus[i + 1]) for i in range(n - 1)]
            process_nums = list(nums)
            no_gcd_index = 0
            for i in range(begin, n - 1):
                GCD.append(math.gcd(process_nums[i], process_nums[i + 1]))
                if GCD[i - begin] == 1:
                    no_gcd_index = i + 1
                    break
                process_nums[i] = process_nums[i + 1] = GCD[i - begin]
            step = 0
            for i in range(1, no_gcd_index - begin):
                if math.gcd(nums[no_gcd_index], nums[no_gcd_index - i]) == 1:
                    break
                step += 1
            step = step + n - nums.count(1)
            if step < best_step:
                best_step = step

        if best_step == 10**9:
            return -1
        return best_step


if __name__ == "__main__":
    solution = Solution()
    # nums = [30, 6, 15, 10]
    # nums = [3, 4]
    # nums = [2, 6, 3, 4]
    # 2, 3, 5, 7, 11
    # nums = [6, 210, 14, 7]
    # 6, 6, 14, 7
    # 6, 2, 2, 7
    # 6, 2, 1, 1 => 警報，回頭算數量
    # 先回頭看原始的 ans, ans+1，計數 0
    # 一路找到 ans+1 沒有 gcd 的位置
    # 6, 2, 7
    # 1,5 15,7 2,1
    # nums = [30, 105, 385]
    # 15, 35
    #
    print(solution.minOperations(nums))
    # print(math.gcd(*nums))

# 最終答案不會小於 n，因為會需要每一項都去操作變為 1
