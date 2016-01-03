a = input()
one = set(int(elem) for elem in raw_input().split())
b = input()
two = set(int(elem) for elem in raw_input().split())
# INPUT DONE
s = set()
for x in one:
    s.add(x)
for x in two:
    if x in s:
        s.remove(x)
    else:
        s.add(x)
for elem in sorted(s):  print elem
