import sys

# B, R 갯수를 셀 필요도없음
# 전체 다른 갯수 /2 + 1

input = sys.stdin.readline

N = input()
blog = input().rstrip()

cnt = 0
for i in range(0, len(blog) - 1) :
    if blog[i] != blog[i+1] :
        cnt += 1
cnt += 1
print(cnt // 2 + 1)
