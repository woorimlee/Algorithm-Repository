import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

# money : 투자 금액, compNum : 투자한 회사
# invest(money, compNum) : money만큼 compNum에 투자했을 때 얻을 수 있는 최대 이익을 return
def invest(money: int, comp_num: int) -> int :
    global invested, cache
    
    if comp_num > M : 
        return 0
    
    if cache[money][comp_num] != -1 : 
        return cache[money][comp_num]
        
    cache[money][comp_num] = 0
    best_case = 0
    for i in range(money + 1) : 
        profit = company[i][comp_num] + invest(money - i, comp_num + 1)
        if profit > cache[money][comp_num] : 
            cache[money][comp_num] = profit
            best_case = i
    
    invested[money][comp_num] = best_case
    return cache[money][comp_num]

def invest_record() : 
    total = N
    for i in range(1, M + 1) : 
        print(invested[total][i], end = ' ')
        total -= invested[total][i]
    print()

MAX_N = 300 + 1
MAX_M = 20 + 1
N, M = map(int, input().split())
company = [[0] * MAX_M for _ in range(MAX_N)] # 투자 액수와 회사 번호는 1부터 시작
invested = [[0] * MAX_M for _ in range(MAX_N)] # 투자 결과 출력용
cache = [[-1] * MAX_M for _ in range(MAX_N)]

for _ in range(N) : 
    money, *comp_profits = map(int, input().split())
    for i, profit in enumerate(comp_profits) : 
        company[money][i + 1] = profit

best_profit = invest(N, 1)
print(best_profit)
invest_record()
