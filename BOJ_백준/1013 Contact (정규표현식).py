import sys
import re

pattern = r'\b(?:100+1+|01)+\b'

T = int(input())
for _ in range(T) : 
    signal = sys.stdin.readline().rstrip()
    
    if re.fullmatch(pattern, signal) :
        print('YES')
    else :
        print('NO')
