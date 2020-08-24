class node:
    def __init__(self):
        self.child = dict()

    def dfs(self, depth):
        for key in sorted(self.child.keys()):
            print("--" * depth + key)
            self.child[key].dfs(depth + 1)

if __name__ == "__main__":
    N = int(input())
    root = node()
    for _ in range(N):
        nodes = input().split()[1:]
        cur = root
        for node_i in nodes:
            if node_i in cur.child:
                cur = cur.child[node_i]
            else:
                cur.child[node_i] = node()
                cur = cur.child[node_i]
    root.dfs(0)