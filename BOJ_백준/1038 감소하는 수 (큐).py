N = int(input())
index = 9
q = [i for i in range(0, index + 1)] #0 ~ 9까지 리스트에 넣음
#que의 맨 앞에는 감소하는 수 중 가장 작은 값이 들어있음.
#그 수의 일의 자리 값을 기준으로 그것보다 작은 값을 0부터 순서대로 맨 뒤에 이어붙이고
#que에 넣어준다.
ans = [i for i in range(0, index + 1)]

while index <= N :
    if not q :
        break
    t_num = q.pop(0) #target_number
    t_last_num = t_num % 10 #일의 자리
    for j in range(0, t_last_num) :
        q.append(t_num * 10 + j)
        ans.append(t_num * 10 + j)
        index += 1
        
if len(ans) <= N :
    print(-1)
else :
    print(ans[N])