n, k = map(int, input().split())
s = []
for i in range(n):
    s.append(input())

have = set(s)

ans = 0
for i in range(n):
    for j in range(i + 1, n):
        to_find = []
        for p in range(k):
            if s[i][p] == s[j][p]:
                to_find.append(s[i][p])
            else:
                val = ord('S') + ord('E') + ord('T') - ord(s[i][p]) - ord(s[j][p])
                to_find.append(chr(val))
        if ''.join(to_find) in have:
            ans += 1

print(ans // 3)
