# Uses python3
import sys


def lcm_naive(a, b):
    for l in range(1, a*b + 1):
        if l % a == 0 and l % b == 0:
            return l

    return a*b


def my_lcm(a, b):

    max_ = max(a,b)
    min_ = min(a,b)

    # Check if b is multiple of a
    if (max_ % min_) == 0:
        return max_

    result = int(a*b/my_gcd(a,b))

    return result


def my_gcd(a, b):

    max_ = max(a, b)
    min_ = min(a, b)

    while (max_ % min_) != 0:

        tmp = max_

        max_ = min_

        min_ = tmp % min_

    return min_


if __name__ == '__main__':
    # input = sys.stdin.read()
    a, b = map(int, input().split())
    # print(lcm_naive(a, b))
    print(my_lcm(a, b))
