import sys
input = sys.stdin.readline

n = int(input())
m = int(input())

friends = {}
for _ in range(m) :
    i, j = input().split()
    if i not in friends:
        friends[i] = []
    if j not in friends:
        friends[j] = []
    friends[i].append(j)
    friends[j].append(i)
    
#friends를 한 번 출력해서 어떻게 구성되어 있는지 확인해보세요
#print(friends) 

invitation = set()
for friend in friends['1'] :
    invitation.add(friend)
    for fof in friends[friend] :
        invitation.add(fof)

print(len(invitation)-1)
