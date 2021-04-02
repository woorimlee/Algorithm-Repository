import sys

N = int(input())
file_list = sys.stdin.read().splitlines()
file_name_len = len(file_list[0])

def check_file_name(file_list, i):
    char = file_list[0][i]
    for j in range(1, N):
        if char is not file_list[j][i]:
            return False
    return True

res = ''
for i in range(file_name_len):
    if check_file_name(file_list, i):
        res += file_list[0][i]
    else:
        res += '?'
print(res)
