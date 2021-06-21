import sys
from bisect import bisect_left, bisect, bisect_right

input = sys.stdin.readline
N = int(input())
sg = input().split()
sg.sort()

M = int(input())
search_cards = input().split()
for sc in search_cards :
    # print(bisect_right(sg, sc) - bisect_left(sg, sc), end = ' ')
    print(bisect(sg, sc) - bisect_left(sg, sc), end = ' ')
