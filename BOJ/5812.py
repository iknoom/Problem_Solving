import sys
input = sys.stdin.readline

L = int(input())

Letter = []
table = []
command = []
idx = []

for _ in range(L):
    a, b = input().split()
    if a == 'T':
        Letter.append(b)
        next_table = [len(Letter) - 1]
        if command:
            next_table.append(command[-1])
            while True:
                t = len(next_table) - 1
                before = next_table[-1]
                if t < len(table[before]):
                    next_table.append(table[before][t])
                else:
                    break
        table.append(next_table)
        command.append(len(Letter) - 1)
        if not idx: idx.append(0)
        else: idx.append(idx[-1] + 1)

    if a == 'U':
        command.append(command[-int(b) - 1])
        idx.append(idx[-int(b) - 1])

    if a == 'P':
        diff = idx[-1] - int(b)
        cur = command[-1]
        while diff:
            for i in range(len(table[cur]) - 1, -1, -1):
                if diff >= (1 << (i - 1)):
                    cur = table[cur][i]
                    diff -= (1 << (i - 1))
                    break
        print(Letter[cur])