class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        S_1, S_2 = len(word1), len(word2)
        D = [[0 for _ in range(S_2 + 1)] for _ in range(S_1 + 1)]

        for i in range(S_2 + 1):
            D[0][i] = i
        for i in range(S_1 + 1):
            D[i][0] = i
        
        for i in range(1, S_1 + 1):
            for j in range(1, S_2 + 1):
                op_1 = D[i-1][j-1]
                if not word1[i - 1] == word2[j - 1]:
                    op_1 += 1
                op_2 = D[i-1][j] + 1
                op_3 = D[i][j - 1] + 1
                D[i][j] = min(op_1, op_2, op_3)
        
        return D[S_1][S_2]