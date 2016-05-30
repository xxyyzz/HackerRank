def solve():
    for tc in xrange(int(raw_input())):
        n = int(raw_input())
        arr = map(int, raw_input().split())
        i, res = 0, 0
        for x in arr:
            if (x % 2) == 1:
                res = res ^ i
            i += 1
        print 'Second' if res == 0 else 'First'

solve()
