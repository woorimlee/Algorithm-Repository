import sys
from collections import deque
import re

T = int(sys.stdin.readline())

def ac_func() : 
    acs = sys.stdin.readline().rstrip()
    arr_len = sys.stdin.readline().rstrip()
    arr = re.findall(r'\b\d+\b', sys.stdin.readline().rstrip())
    arr = deque(arr)
    R_flag = False
    
    for ac in acs : 
        if ac == 'R' :
            R_flag = False if R_flag else True
        else : 
            if len(arr) : 
                if R_flag : 
                    arr.pop()
                else : 
                    arr.popleft()
            else : 
                print("error")
                return
    
    arr = list(arr)
    if not R_flag : 
        print('[' + ','.join(arr) + ']')
    else : 
        print('[' + ','.join(arr[::-1]) + ']')
    
    
for _ in range(T) :
    ac_func()
