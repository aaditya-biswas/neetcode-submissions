class Node:
    def __init__(self):
        self.ch : str | None = None
        self.char_map : dict[str , Node] = {}
        self.end : bool = False
    
    def addWord(self , word : str, ind : int ) -> None:
        if (ind == len(word)):
            self.end = True
            return 
        
        req : str = word[ind]
        
        # If it does not exist 
        if self.char_map.get(req) == None:
            self.char_map[req] = Node()
            self.char_map[req].ch = req

        self.char_map[req].addWord(word,ind + 1)
        return
    def search(self , word : str , ind : int) -> bool:
        if (ind == len(word)):
            return self.end
        
        req : str = word[ind]
        
        # If exists 
        if req == '.':
            for a in self.char_map.values():
                if (a.search(word,ind+1)):
                    return True
        elif self.char_map.get(req):
            return self.char_map.get(req).search(word,ind + 1)
    
        return False



class WordDictionary:

    def __init__(self):
        self.trie = Node() 

    def addWord(self, word: str) -> None:
        self.trie.addWord(word,0)
        return

    def search(self, word: str) -> bool:
        return self.trie.search(word,0)