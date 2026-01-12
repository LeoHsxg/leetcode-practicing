import math


class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        cnt0 = s.count('0')
        cnt1 = s.count('1')
        pos0 = []
        total0 = [0] * n  # 預分配 n+1 個空間
        
        for i in range(0, n):
            if s[i] == '0':
                pos0.append(i)
                total0[i] = cnt0
            else:
                total0[i] = cnt0
        
        # case1: only '1'
        last0, ans = 0, 0
        has0 = False
        for i in range(0, n):
            if s[i] == '0':
                if not has0:
                    has0 = True
                    ans += (i * (i+1)) / 2
                else:
                    t = i - last0 - 1
                    ans += (t * (t + 1))/2
                last0 = i
        t = n - last0 - 1
        ans += (t * (t + 1))/2
                
        # for i in range(0, len(pos0)):
        #     t = pos0[i] - pos0[i-1] - 1
        #     ans += (t * (t + 1))/2
        # t = (n + 1) - pos0[len(pos0) - 1] - 1
        # ans += (t * (t + 1))/2
        
        # case2: with 0
        begin, end = 0, n
        t_cnt0, t_cnt1 = 0, 0
        if cnt0 == 0:
            ans = ans
        elif cnt0 == 1:
            
            
            
        for i in range(len(pos0)-2, -1, -1):
            
            
            
        return ans
                
            
            
        
        
                
            

if __name__ == "__main__":
    solution = Solution()
    str_ = "1110111"
    print(solution.numberOfSubstrings(str_))
    
# 拆分兩種情況，只有 1 的超合法情況，以及有 0 的情況
# 0 的話，則是以每一個 0 為單位，由後往前檢查 (因為 0 號位置可以塞 0，要由前往後也可以就是了)，
