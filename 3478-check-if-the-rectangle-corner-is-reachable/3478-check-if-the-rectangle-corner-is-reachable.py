
class Solution:
    def canReachCorner(self, width: int, height: int, circles: List[List[int]]) -> bool:
        num_circles = len(circles)
        circle_info = [(circles[i][0], circles[i][1], circles[i][2]) for i in range(num_circles)]
        adjacency_list = [[] for _ in range(num_circles + 4)]
        
        for i in range(num_circles):
            x, y, radius = circle_info[i]

            if x - radius <= 0:
                adjacency_list[i].append(num_circles)
                adjacency_list[num_circles].append(i)
            if width - x <= radius:
                adjacency_list[i].append(num_circles + 2)
                adjacency_list[num_circles + 2].append(i)
            if y - radius <= 0:
                adjacency_list[i].append(num_circles + 1)
                adjacency_list[num_circles + 1].append(i)
            if height - y <= radius:
                adjacency_list[i].append(num_circles + 3)
                adjacency_list[num_circles + 3].append(i)

            for j in range(i + 1, num_circles):
                x2, y2, radius2 = circle_info[j]
                dx = x - x2
                dy = y - y2
                distance_squared = dx * dx + dy * dy
                radius_sum = radius + radius2

                if distance_squared <= radius_sum * radius_sum:
                    adjacency_list[i].append(j)
                    adjacency_list[j].append(i)
        
        def bfs(start_node, target_node1, target_node2):
            queue = deque([start_node])
            visited = [0] * (num_circles + 4)
            visited[start_node] = 1
            while queue:
                current_node = queue.popleft()
                for neighbor in adjacency_list[current_node]:
                    if not visited[neighbor]:
                        visited[neighbor] = 1
                        queue.append(neighbor)
            return visited[target_node1] or visited[target_node2]
        
        return not (bfs(num_circles, num_circles + 1, num_circles + 2) or bfs(num_circles + 3, num_circles + 2, num_circles + 1))
