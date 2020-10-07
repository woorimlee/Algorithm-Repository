#대회 참가 학생수를 N에 입력받고, 크기 N의 리스트를 생성.
#입력받은 리스트를 정렬한 후,
#1등 2등을 출력하면서 같은 국가인지 확인한다.
#같은 국가라면 다른 국가 소속 학생 중 가장 점수 높은 사람의 위치를 찾고,
#같은 국가가 아니라면 3등을 바로 출력한다.

N = int(input())
a = [input().split() for i in range(N)] #리스트 컴프리헨션
a.sort(key = lambda x : -int(x[2])) #lambda 표현식
dong = 2
if(a[0][0] == a[1][0]) :
    while a[0][0] == a[dong][0] :
        dong += 1
for i in (0, 1, dong) :
    print(*a[i][:2]) #언패킹