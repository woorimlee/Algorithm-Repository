import sys
import re

pattern = r'\b(?:100+1+|01)+\b'
signal = sys.stdin.readline().rstrip()

if re.fullmatch(pattern, signal) :
    print('SUBMARINE')
else :
    print('NOISE')
