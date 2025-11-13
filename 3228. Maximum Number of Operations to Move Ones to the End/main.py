import math


class Solution:
    def maxOperations(self, s: str) -> int:
        cnt_one = 0
        ans = 0
        has_zero = False
        
        for char in s:  # 直接迭代字串，不需要索引
            if char == "1":
                if has_zero:
                    has_zero = False
                    ans += cnt_one
                cnt_one += 1
            elif char == "0":  # 使用 elif 而非兩個 if
                has_zero = True
        
        if has_zero:
            ans += cnt_one
        return ans


if __name__ == "__main__":
    solution = Solution()
    str_ = "110"
    print(solution.maxOperations(str_))
    
# 今日知識：Python 沒有「宣告」的概念，但必須初始化
