import sys
import re

# KMP 풀이, 시간 초과
"""
def get_partial_match(p: str) :
    pi = [0] * len(p)
    
    begin, matched = 1, 0
    while begin + matched < len(p) :
    	if p[begin + matched] == p[matched] :
    	    matched += 1
    	    pi[begin + matched - 1] = matched;
    	else :
    		if matched == 0 : 
    			begin += 1
    		else :
    			begin += matched - pi[matched - 1];
    			matched = pi[matched - 1];
    return pi;
    
def kmp_search(s: str, p: str) -> int : 
    pi = get_partial_match(p)
    ret = 0
    
    begin, matched = 0, 0
    while begin + matched < len(s) : 
        if matched < len(p) and s[begin + matched] == p[matched] : 
            matched += 1
            ret = max(ret, matched)
        elif matched :
            begin += matched - pi[matched - 1]
            matched = pi[matched - 1]
        else : 
            begin += 1
    
    return ret

s1 = list(sys.stdin.readline().rstrip())
s2 = list(sys.stdin.readline().rstrip())

if len(s1) < len(s2) : 
    s1, s2 = s2, s1

m = len(s2)

ans = 0
for _ in range(m) : 
    ans = max(ans, kmp_search(s1, s2))
    del s2[0]

print(ans)
"""

# dp 풀이
s1 = sys.stdin.readline().rstrip()
s2 = sys.stdin.readline().rstrip()

prev = [0] * (len(s2) + 1)
ans = 0

for i in range(len(s1)) : 
    cur = [0] * (len(s2) + 1)
    for j in range(len(s2)) :
        if s1[i] == s2[j] : 
            cur[j + 1] = prev[j] + 1
    ans = max(ans, max(cur))
    prev = cur[:]

print(ans)
