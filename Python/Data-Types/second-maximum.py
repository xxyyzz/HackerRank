n = input()
arr = map(int, raw_input().split())
s = list(set(arr))
s.sort()
print s[len(s)-2]
