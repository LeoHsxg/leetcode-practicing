import math


class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)

        PrefSum = [0] * (n + 1) # prefix sum of ones
        for i, ch in enumerate(s):
            PrefSum[i+1] = PrefSum[i] + (ch == '1')

        Pos0 = [i for i, ch in enumerate(s) if ch == '0']
        num0 = len(Pos0)

        ans = 0

        # case1: only '1'
        i = 0
        while i < n:
            if s[i] == '0':
                i += 1
                continue
            j = i
            while j < n and s[j] == '1':
                j += 1
            L = j - i
            ans += L * (L + 1) // 2
            i = j

        # square root n, bound
        B = math.isqrt(n) + 2

        def ones(l, r):
            return PrefSum[r+1] - PrefSum[l]

        # case2
        for a in range(num0):   # 遍歷每個 0 的位置
            Lmin = 0 if a == 0 else Pos0[a-1] + 1
            Lmax = Pos0[a]
            if Lmin > Lmax:
                continue

            for z in range(1, B + 1):
                b = a + z - 1
                if b >= num0:
                    break

                Rmin = Pos0[b]
                Rmax = Pos0[b + 1] - 1 if b + 1 < num0 else n - 1
                if Rmin > Rmax:
                    continue

                need = z * z
                r = Rmin

                for l in range(Lmin, Lmax + 1):
                    if PrefSum[Rmax + 1] - PrefSum[l] < need:
                        continue
                    while r <= Rmax and ones(l, r) < need:
                        r += 1
                    if r > Rmax:
                        break
                    ans += (Rmax - r + 1)

        return ans