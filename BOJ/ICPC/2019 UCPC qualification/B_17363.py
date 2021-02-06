aya = {
        '.': '.',
        'O': 'O',
        '-': '|',
        '|': '-',
        '/': '\\',
        '\\': '/',
        '^': '<',
        '<': 'v',
        'v': '>',
        '>': '^'
    }
func = lambda s: aya[s]

if __name__ == "__main__":
    N, M = map(int, input().split())
    milk = [list(map(func, input())) for _ in range(N)]
    for i in range(M):
        for j in range(N):
            print(milk[j][-i - 1], end='')
        print()