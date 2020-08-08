tests = int(input())
for test in range(tests):
    n = int(input())
    k2, k3 = 0, 0
    while n % 2 == 0:
        k2 += 1
        n //= 2
    while n % 3 == 0:
        k3 += 1
        n //= 3
    if n != 1 or k2 > k3:
        print(-1)
    else:
        print(2 * k3 - k2)
