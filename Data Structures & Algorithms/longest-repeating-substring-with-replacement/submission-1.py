class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        charSet : dict[str , int] = {}
        
        for a in s:
            charSet[a] = 1
        # Now slide the pointers for each distinct character
        # Max_length
        max_len : int  = 1
        for ch in charSet.keys():
            l : int = 0
            r : int = 0
            count : int  = 0
            for  i in range(len(s)):
                if s[i] != ch:
                    count += 1
                while count > k:
                    if s[l] != ch:
                        count -= 1
                    l += 1
                max_len = max(max_len , r - l + 1)
                r += 1
        return max_len