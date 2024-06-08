class Solution:
    def findWinningPlayer(self, skills: List[int], k: int) -> int:
        
        players = [(skill, idx) for idx, skill in enumerate(skills)]
        
        current_winner = players[0]
        consecutive_wins = 0
        
        for i in range(1, len(players)):
            if current_winner[0] > players[i][0]:
                consecutive_wins += 1
                players.append(players[i])
            else:
                consecutive_wins = 1
                players.append(current_winner)
                current_winner = players[i]
            
            if consecutive_wins == k:
                return current_winner[1]
        
        return max(players)[1]
