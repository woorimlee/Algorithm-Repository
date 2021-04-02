S = str(input())

suffixs = []
for _ in S :
    suffixs.append(S)
    S = S[1:]

suffixs.sort()
for suffix in suffixs :
    print(suffix)
