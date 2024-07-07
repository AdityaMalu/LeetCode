class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.cost = float('inf')
        
class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word: str, cost: int):
        node = self.root
        for char in word:
            node = node.children[char]
        node.cost = min(node.cost, cost)
        
    def search(self, target: str, start: int):
        node = self.root
        positions = []
        for i in range(start, len(target)):
            if target[i] not in node.children:
                break
            node = node.children[target[i]]
            if node.cost != float('inf'):
                positions.append((i + 1, node.cost))
        return positions

class Solution:
    def minimumCost(self, target: str, words: List[str], costs: List[int]) -> int:
        n = len(target)
        
        trie = Trie()
        for word, cost in zip(words, costs):
            trie.insert(word, cost)
      
        dp = [float('inf')] * (n + 1)
        dp[0] = 0

        for i in range(n):
            if dp[i] == float('inf'):
                continue
            for end, cost in trie.search(target, i):
                dp[end] = min(dp[end], dp[i] + cost)
        
        return dp[n] if dp[n] != float('inf') else -1