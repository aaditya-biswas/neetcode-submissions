class Node:
    def __init__(self):
        # We don't strictly need to store self.char because the key in the parent's
        # char_map already represents the character, but we can keep it clean.
        self.char_map: dict[str, Node] = {}
        self.end = False

    def insert_word(self, word: str, ind: int) -> None:
        # Base case: we've reached the end of the word string
        if ind == len(word):
            self.end = True
            return

        req = word[ind]
        # If the character path doesn't exist, create it
        if req not in self.char_map:
            self.char_map[req] = Node()
        
        # Move down to the next node recursively
        self.char_map[req].insert_word(word, ind + 1)

    def search_word(self, word: str, ind: int) -> bool:
        if ind == len(word):
            return self.end  # Must be the exact end of a stored word

        req = word[ind]
        if req in self.char_map:
            return self.char_map[req].search_word(word, ind + 1)
        return False

    def starts_with_prefix(self, prefix: str, ind: int) -> bool:
        if ind == len(prefix):
            return True  # We matched every character in the prefix successfully

        req = prefix[ind]
        if req in self.char_map:
            return self.char_map[req].starts_with_prefix(prefix, ind + 1)
        return False


class PrefixTree:
    def __init__(self):
        self.root = Node()

    def insert(self, word: str) -> None:
        self.root.insert_word(word, 0)

    def search(self, word: str) -> bool:
        return self.root.search_word(word, 0)

    def startsWith(self, prefix: str) -> bool:
        return self.root.starts_with_prefix(prefix, 0)