import sys

input = sys.stdin.readline

change = {'0' : '1', '1' : '0'}

def run(copy) :
    cnt = 0
    for i in range(1, N) :
        if copy[i - 1] != target[i - 1] :
            cnt += 1
            for j in range(i - 1, i + 2) :
                if j < N :
                    copy[j] = change[copy[j]]

    if copy == target :
        return cnt
    else :
        return 1234567890

N = int(input())
original = list(input().strip())
target = list(input().strip())
c_original = original[:]
c_original[0] = change[original[0]]
c_original[1] = change[original[1]]

ans = min(run(original), run(c_original) + 1)
if ans == 1234567890 :
    print(-1)
else :
    print(ans)
