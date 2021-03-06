from sys import stdin
input = stdin.readline

def solution():
    n, k = map(int, input().split())
    s = list(input().rstrip())
    if n % k:
        print(-1)
        return
    all_count = [0] * 26
    for i in range(n):
        all_count[ord(s[i]) - 97] += 1

    if all(all_count[i] % k == 0 for i in range(26)):
        print(''.join(s))
        return

    # solution
    for i in reversed(range(n)):
        all_count[ord(s[i]) - 97] -= 1
        if s[i] == 'z': continue
        ret = 0
        for j in range(26):
            if all_count[j] % k:
                ret += k - (all_count[j] % k)
        # is possible
        if ret > (n - i):
            continue

        if (n - i) - ret >= k:
            all_count_dup = all_count[:]
            s[i] = chr(ord(s[i]) + 1)
            all_count_dup[ord(s[i]) - 97] += k - 1
            j = i
            for x in range(26):
                if not all_count_dup[x] % k:
                    continue
                rest = k - (all_count_dup[x] % k)
                while rest:
                    s[i + j] = chr(x + 97)
                    j += 1
                    rest -= 1
            print(''.join(s))
            return
        else:
            last = -1
            for j in range(ord(s[i]) - 97 + 1, 26):
                if all_count[j] % k:
                    last = j
                    break
            if last < 0:
                continue
            s[i] = chr(last + 97)
            all_count[last] += 1
            j = i
            for x in range(26):
                if not all_count[x] % k: continue
                rest = k - (all_count[x] % k)
                while rest:
                    j += 1
                    s[i + j] = chr(x + 97)
                    rest -= 1
            print(''.join(s))
            return

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()