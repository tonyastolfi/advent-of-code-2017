def repeat_sum(input):
    prev = input[-1]
    total = 0
    for ch in input:
        if ch == prev:
            total += int(ch)
        prev = ch
    return total


def halfway_sum(input):
    total = 0
    for n in xrange(len(input) / 2):
        if input[n] == input[n + len(input)/2]:
            total += int(input[n])*2
    return total


def examples():
    assert repeat_sum('1122') == 3
    assert repeat_sum('1111') == 4
    assert repeat_sum('1234') == 0
    assert repeat_sum('91212129') == 9


def examples2():
    assert halfway_sum('1212') == 6
    assert halfway_sum('1221') == 0
    assert halfway_sum('123425') == 4
    assert halfway_sum('123123') == 12
    assert halfway_sum('12131415') == 4
    

def solve():
    with open('input-1.txt', 'r') as f:
        input = f.read().strip()
    print repeat_sum(input)
    print halfway_sum(input)


if __name__ == '__main__':
    examples()
    examples2()
    solve()
