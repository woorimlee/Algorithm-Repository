n = int(input())
a = list(map(int, input().split()))
b = []

for i in range(0, n):
	foo = list(map(int, input().split()))
	b.append(foo)

dap = int(1e9)
dlist = []

for i in range(0, 1 << n):
	tmp = [0, 0, 0, 0]
	S = []
	cost = 0
	for j in range(0, n):
		if ((i >> j) & 1) == 1:
			S.append(j + 1)
			for k in range(0, 4):
				tmp[k] += b[j][k]
			cost += b[j][4]
	
	good = True

	for j in range(0, 4):
		if tmp[j] < a[j]:
			good = False
	
	if good:
		if dap > cost:
			dap = cost
			dlist = S
		if dap == cost and (dlist > S):
			dlist = S

if dap > int(1e8):
	print(-1)
else:
	print(dap)
	print(" ".join(map(str, dlist)))
