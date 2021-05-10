s = input()
se = [[] for _ in range(26)]
for i in range(len(s)):
    se[ord(s[i]) - ord('A')].append(i)
answer = 0
for i in range(25):
    for j in range(i + 1, 26):
        s1, e1 = se[i]
        s2, e2 = se[j]
        if e1 < s2 or e2 < s1:
            continue
        if s1 < e2 < e1 and s1 < s2 < e1:
            continue
        if s2 < e1 < e2 and s2 < s1 < e2:
            continue
        answer += 1
print(answer)