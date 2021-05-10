n = int(input())
limit = 10000000
golomb = [0, 1, 2, 2]
for i in range(3, limit):
    golomb += [i] * golomb[i]
    if len(golomb) > limit: break
for i in range(limit):
    golomb[i + 1] += golomb[i]
    if golomb[i] < n <= golomb[i + 1]:
        print(i + 1)
        break