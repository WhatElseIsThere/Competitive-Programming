tests = int(input())
for test in range(tests):
    x, y, n = map(int, input().split())
    ans = (n // x) * x + y
    if ans > n:
        ans -= x
    print(ans)
