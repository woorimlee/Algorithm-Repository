time = input().split()
time[0] = int(time[0])
time[1] = int(time[1]) - 30
if (time[1]) < 0 :
    time[1] = 60 + (time[1])
    time[0] -= 1
    if time[0] < 0 :
        time[0] = 23
print(time[0], time[1])
