from collections import Counter

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2): 
            return False
        
        # Count frequencies of characters in s1
        s1_counts = Counter(s1)
        # Count frequencies of characters in the first window of s2
        window_counts = Counter(s2[:len(s1)])
        
        # If the first window matches, we are done!
        if s1_counts == window_counts:
            return True
            
        # Slide the window across the rest of s2
        for r in range(len(s1), len(s2)):
            # Add the new character entering the window from the right
            next_char = s2[r]
            window_counts[next_char] += 1
            
            # Remove the old character leaving the window from the left
            left_char = s2[r - len(s1)]
            window_counts[left_char] -= 1
            
            # Clean up the dictionary to keep comparisons accurate
            if window_counts[left_char] == 0:
                del window_counts[left_char]
                
            # Check if the current window matches s1
            if s1_counts == window_counts:
                return True
                
        return False






        