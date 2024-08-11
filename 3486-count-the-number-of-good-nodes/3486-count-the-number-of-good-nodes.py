class Solution:
    def countGoodNodes(self, edges: List[List[int]]) -> int:
        graph = defaultdict(list)
        for parent, child in edges:
            graph[parent].append(child)
            graph[child].append(parent)
        
        good_nodes = 0
        
        def dfs(node: int, parent: int) -> int:
            nonlocal good_nodes
            subtree_sizes = []
            
            for child in graph[node]:
                if child != parent:
                    subtree_size = dfs(child, node)
                    subtree_sizes.append(subtree_size)

            if len(set(subtree_sizes)) <= 1:
                good_nodes += 1

            return 1 + sum(subtree_sizes)
        
        dfs(0, -1)
        
        return good_nodes