from collections import Counter
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # Use the end of the string 
        l : int = 0
        r : int = 0
        mp_t : Counter[str]  = Counter(t)
        mp_s : Counter[str] = Counter()
        min_len : int = 1001 
        min_len_start : int = 0
        min_len_end : int = 0
        while r  < len(s):
            # Add it to the counter
            mp_s[s[r]] += 1

            # Check if we are able to shrink
            while mp_t <= mp_s:
                if min_len > (r - l + 1):
                    min_len_start = l
                    min_len_end = r 
                    min_len = r - l + 1
                mp_s[s[l]] -= 1
                l += 1

            r += 1
            # Shrink the window from the right
        if min_len == 1001: return ""
        return s[min_len_start : min_len_end + 1]