import re

for tc in xrange(int(raw_input())):
    line = str(raw_input())
    pattern = re.compile(r'(?<= )&&(?= )')
    res = re.sub(pattern, "and", line)
    pattern = re.compile(r'(?<= )\|\|(?= )')
    res = re.sub(pattern, "or", res)
    print res
