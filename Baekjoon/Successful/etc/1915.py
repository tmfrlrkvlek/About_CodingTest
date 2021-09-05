# 1915

n, m = map(int, input().split(' '))
table = [list(map(int,input())) for _ in range(n)]          # 0110 --> [0, 1, 1, 0] 변환
ans = 0

for i in range(n):
    for j in range(m):
        if i > 0 and j > 0 and table[i][j] == 1:
            table[i][j] += min(table[i - 1][j], table[i][j - 1], table[i - 1][j - 1])
        ans = max(ans, table[i][j])
print(ans ** 2)