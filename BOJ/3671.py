from itertools import permutations

MAX = 10000000

if __name__ == '__main__':
    is_prime = [True] * MAX
    is_prime[0] = is_prime[1] = False
    for i in range(2, MAX):
        if is_prime[i]:
            for j in range(i * 2, MAX, i):
                is_prime[j] = False

    c = int(input())
    for _ in range(c):
        papers = input()
        m = len(papers)
        S = set()
        for i in range(1, 1 << m):
            selected = []
            for j in range(m):
                if i & (1 << j):
                    selected.append(papers[j])
            for p in permutations(selected):
                cur = int(''.join(p))
                if is_prime[cur]:
                    S.add(cur)
        print(len(S))
