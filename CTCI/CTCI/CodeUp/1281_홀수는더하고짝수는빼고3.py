a, b = input().split()
st = ''
num_a = int(a)
num_b = int(b)

if num_a % 2 == 0 :
    answer = -num_a
    st += str(-num_a)
else :
    answer = num_a
    st += str(num_a)

if a == b :
    if int(a) % 2 == 0 :    
        print("-", a, "=-", a, sep='')
    else :
        print(a, "=+", a, sep='')
    exit()
    

while num_a != num_b :
    num_a += 1
    if(num_a %2 == 0) :
        st += '-' + str(num_a)
        answer -= num_a
    else :
        st += '+' + str(num_a)
        answer += num_a
        
st += '='
if (num_b - 1) % 2 == 0 :
    st += '+' + str(answer)
else :
    st += str(answer)
print(st)
