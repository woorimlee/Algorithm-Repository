import sys
input = sys.stdin.readline

def lis(seq) :
	cache = [1] * len(seq)
	for i in range(1, len(seq)):
		for j in range(i):
			if seq[j] < seq[i]:
				cache[i] = max(cache[i],cache[j]+1)
	print(max(cache))
	
N = int(input())
seq = list(map(int,input().split()))
lis(seq)
