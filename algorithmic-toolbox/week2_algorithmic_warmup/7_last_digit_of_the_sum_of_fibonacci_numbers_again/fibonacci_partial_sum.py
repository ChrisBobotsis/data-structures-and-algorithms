# Uses python3
import sys


def fibonacci_partial_sum_naive(from_, to):
    sum = 0

    current = 0
    next  = 1

    for i in range(to + 1):
        if i >= from_:
            sum += current

        current, next = next, current + next

    return sum % 10


def my_fibonacci_partial_sum(from_, to):
    # 4 -3 = 1
    delta = to - from_
    # 1
    remainder = delta % 60
    # 3
    start = to - remainder
    # f_2 = 1, f_1 = 1
    f_prev_1 = (my_calc_fib((start - 1)%60)) % 10
    f_prev_2 = (my_calc_fib((start - 2)%60)) % 10

    sum_ = 0

    for _ in range(remainder + 1):
        # 2
        f_i = (f_prev_1 + f_prev_2) % 10
        # 1
        f_prev_2 = f_prev_1
        # 2
        f_prev_1 = f_i

        sum_ += f_i
        sum_ %= 10

    return sum_




def my_calc_fib(n):

    if n == 0:
        return 0
    if n == 1:
        return 1

    # f_0 = 0
    prev_2 = 0
    # f_1 = 1
    prev_1 = 1

    result = 0

    for _ in range(n - 1):

        result = prev_1 + prev_2

        prev_2 = prev_1

        prev_1 = result

    return result


if __name__ == '__main__':
    # input = sys.stdin.read()
    from_, to = map(int, input().split())
    # print(fibonacci_partial_sum_naive(from_, to))
    print(my_fibonacci_partial_sum(from_, to))
    # print(my_calc_fib(from_))