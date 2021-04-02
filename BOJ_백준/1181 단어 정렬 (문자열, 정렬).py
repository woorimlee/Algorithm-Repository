import sys

N = input()
words = set(sys.stdin.read().splitlines())

words = sorted(list(words), key = lambda x : (len(x), x))
print('\n'.join(words))
