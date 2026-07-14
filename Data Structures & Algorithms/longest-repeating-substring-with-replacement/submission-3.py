class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        charSet : dict[str , int] = {}
        max_len : int  = 1
        l : int  =  0
        max_val : int = 0
        max_char : str | None = None
        for i in range(len(s)):
            # Assume the window ends at i 
            
            # Get the count of most frequent character upto this point 
            if (charSet.get(s[i]) == None ):
                charSet[s[i]] = 0
            
            charSet[s[i]] += 1 
            
            # Get the maximum character
            if (max_val  < charSet[s[i]]):
                max_char = s[i]
                max_val = charSet[s[i]]

            # Check the condition window size – count of the most frequent character ≤ k

            # While condition not satisfied keep shrinking from the left
            while (l <= i and (i - l + 1) - max_val > k):
                charSet[s[l]] -= 1
                l += 1
            max_len = max(max_len, i - l + 1)

        return max_len