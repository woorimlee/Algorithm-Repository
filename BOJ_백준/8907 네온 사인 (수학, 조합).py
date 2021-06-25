import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N = int(input())
    cnt_edge_colors = [0] * N
    
    for i in range(N - 1):
        for j, e_c in enumerate(map(int, input().split()), start = i + 1):
            if e_c == 1 : 
                cnt_edge_colors[i] += 1
                cnt_edge_colors[j] += 1
        
    nCm = N * (N - 1) * (N - 2) // (3 * 2 * 1)
    
    cnt_non_monocolors = 0
    for c_e_c in cnt_edge_colors : 
        cnt_non_monocolors += c_e_c * (N - 1 - c_e_c)
        
    print(nCm - (cnt_non_monocolors // 2))
