dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

class Solution:
    def __init__(self, board, N, M):
        self.board = board
        self.N = N
        self.M = M
        self.visited = [[False] * self.M for _ in range(self.N)]

    def is_ok(self, x, y):
        return 0 <= x < self.M and 0 <= y < self.N and self.board[y][x] == '#' and not self.visited[y][x]

    def get_max(self):
        return max(self.first(x, y) for y in range(self.N) for x in range(self.M))

    def get_second_max(self):
        return max(self.second(x, y) for y in range(self.N) for x in range(self.M))

    def first(self, x, y):
        if self.board[y][x] != '#':
            return 0
        max_value = 0
        # set visited
        L = 0
        while all(self.is_ok(x + dx[i] * L, y + dy[i] * L) for i in range(4)):
            for i in range(4):
                self.visited[y + dy[i] * L][x + dx[i] * L] = True
            L += 1
            # get max value
            max_value = max(max_value, (L * 4 - 3) * self.get_second_max())
        # reset visited
        while L:
            L -= 1
            for i in range(4):
                self.visited[y + dy[i] * L][x + dx[i] * L] = False
        return max_value

    def second(self, x, y):
        if self.board[y][x] != '#':
            return 0
        L = 0
        while all(self.is_ok(x + dx[i] * L, y + dy[i] * L) for i in range(4)):
            L += 1
        return L * 4 - 3

def main():
    N, M = map(int, input().split())
    board = [input() for _ in range(N)]
    solution = Solution(board, N, M)
    answer = solution.get_max()
    print(answer)

if __name__ == '__main__':
    main()