#다섯개 입력받아서
#앞의 세 개 중 가장 싼 거 + 뒤의 두 개 중 가장 싼거 - 50 출력
price = [int(input()) for i in range(5)] 
print(min(price[:3]) + min(price[3:]) - 50)
