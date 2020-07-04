N = int(input())
DNAs = input().split()
cnt = {}
min_cnt = {}
for DNA in DNAs:
	key = int(DNA[1:])	
	if key not in cnt:
		cnt[key] = 0
	if key not in min_cnt:
		min_cnt[key] = float('inf')	
	if DNA[0] == 's':
		cnt[key] += 1
	else:
		cnt[key] -= 1	
	min_cnt[key] = min(min_cnt[key], cnt[key])

cnt2 = {}
total_min = 0
for k in min_cnt:
	if cnt[k] == 0 and min_cnt[k] == 0:
		total_min += 1

ans_max = total_min
ans_idx = []

for i in range(N):
	key = int(DNAs[i][1:])
	if key not in cnt2:
		cnt2[key] = 0
	if cnt[key] != 0:
		pass
	elif DNAs[i][0] == 's':
		if min_cnt[key] == cnt2[key]: total_min -= 1
		cnt2[key] += 1
	else:
		cnt2[key] -= 1
		if min_cnt[key] == cnt2[key]: total_min += 1
	if total_min > ans_max:
		ans_max = total_min
		ans_idx = [(i + 1) % N]
	elif total_min == ans_max:
		ans_idx.append((i + 1) % N)

if ans_idx:
	print(min(ans_idx) + 1, ans_max)
else:
	print(1, 0)
