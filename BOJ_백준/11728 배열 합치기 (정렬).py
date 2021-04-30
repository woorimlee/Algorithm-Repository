import sys

N, M = sys.stdin.readline().split()

AandB = sys.stdin.read().split()

print(' '.join(sorted(AandB, key=int)))
