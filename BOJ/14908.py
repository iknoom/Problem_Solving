# i -> j:   t_i * S_i + (t_i + t_j) * S_j
# j -> i:   t_j * S_j + (t_i + t_j) * S_i
#           = t_i * S_i + t_i * S_j + t_j * S_j
#           = t_j * S_j + t_i * S_i + t_j * S_i
#           = t_i * S_j
#           = t_j * S_i

class node:
    def __init__(self, t, s, idx):
        self.t = t
        self.s = s
        self.idx = idx

    def __lt__(self, other):
        return self.t * other.s < other.t * self.s

if __name__ == '__main__':
    N = int(input())
    nodes = []
    for i in range(N):
        t_i, s_i = map(int, input().split())
        nodes.append(node(t_i, s_i, i + 1))
    print(*[node.idx for node in sorted(nodes)])