import sys
input = sys.stdin.readline

digit_num = [
        "####.##.##.####", # 0
        "..#..#..#..#..#",
        "###..#####..###",
        "###..####..####",
        "#.##.####..#..#",
        "####..###..####",
        "####..####.####",
        "###..#..#..#..#",
        "####.#####.####",
        "####.####..####", # 9
        ]

def sign_to_digit_num(sign) :
    temp = []
    for i in range(N) : 
        temp.append("")
        for j in range(5) :
            temp[i] += sign[j][4 * i : 4 * i + 3]
    return list(reversed(temp)) # 1의 자리부터 계산하게 뒤집


N = int(input())
sign = [input().rsplit()[0] for _ in range(5)]
csign = sign_to_digit_num(sign)

# print(sign, csign)

ans, floor = 0, 1
for i in range(N) :
    pnum, pcnt = 0, 0
    for number in range(10) :
        flag = True
        for j in range(5 * 3) :
            if digit_num[number][j] == '.' and csign[i][j] == '#' :
                flag = False
        if flag :
            pcnt += 1
            pnum += number

    if pcnt != 0 :
        ans += pnum * floor / pcnt
    else :
        print(-1)
        exit
    floor *= 10

print(ans)
    
