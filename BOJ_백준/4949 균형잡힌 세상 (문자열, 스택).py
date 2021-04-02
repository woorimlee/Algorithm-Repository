import sys

# 입력방법 두 가지
# input = sys.stdin.read().splitlines
# for or while :
#   input = sys.stdin.readline().strip('\n')

def check_Blanced(sentence: str) -> bool:
    st = []
    for char in sentence:
        if char == '(' or char=='[':
            st.append(char)
        elif char == ')':
            if not st or st.pop() != '(':
                return False
        elif char == ']':
            if not st or st.pop() != '[':
                return False
    return not st

while True:
    strs = sys.stdin.readline().strip('\n')
    if strs == '.':
        break
    print('yes') if check_Blanced(strs) else print('no')
