n = int(input())

for i in range(1,n+1):
    for j in range(n - i):
        print(' ', end="")
    for j in range(i):
        print('*', end="")
    print()


# n = int(input())
# for i in range(#내용):
#     for j in range(#내용):
#         # 내용
#     for j in range(#내용):
#         # 내용