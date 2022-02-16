S = list(input())
if 'A' in S:
    for i in range(len(S)):
        if S[i] in 'BCDF':
            S[i] = 'A'
elif 'B' in S:
    for i in range(len(S)):
        if S[i] in 'CDF':
            S[i] = 'B'
elif 'C' in S:
    for i in range(len(S)):
        if S[i] in 'DF':
            S[i] = 'C'
else:
    for i in range(len(S)):
        S[i] = 'A'
print(''.join(S))