class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        # Given a string s consisting o 
        string_len = len(s)
        char_map: dict[str, list[int]] = {}

        for i, char in enumerate(s):
            if char in char_map:
                char_map[char][1] = i
            else:
                char_map[char] = [i, i]
        # Now for each number we need to 
        ind = 0;
        res : list[int] = []
        while ind < string_len:
            end = char_map[s[ind]][1]
            cur_len = 0
            while (ind < string_len and ind <= end):
                cur_len += 1
                end = max(end,char_map[s[ind]][1])
                ind += 1
            res.append(cur_len)
        return res