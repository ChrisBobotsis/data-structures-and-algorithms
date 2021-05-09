# Uses python3
import numpy as np

def evalt(a, b, op):

    if op == '+':
        return a + b
    elif op == '-':
        return a - b
    elif op == '*':
        return a * b
    else:
        assert False


def get_maximum_value(dataset):

    ops, integers = return_ops_and_integers(dataset)

    n = len(integers)

    m = np.zeros((n, n))
    M = np.zeros((n, n))

    for i in range(n):
        m[i, i] = integers[i]
        M[i, i] = integers[i]

    for s in range(1, n):
        for i in range(n - s):

            j = i + s
            m[i, j], M[i, j] = MinAndMax(i, j, m, M, ops)

    return int(M[0, n - 1])


def return_ops_and_integers(dataset):

    ops = []
    integers = []

    for i, data in enumerate(dataset):

        if i % 2 == 1:
            ops.append(data)
        else:
            integers.append(int(data))

    return (ops, integers)


def MinAndMax(i, j, m, M, ops):

    min_ = float("inf")
    max_ = -float("inf")
    
    for k in range(i, j):
        a = evalt(
            M[i, k],
            M[k + 1, j],
            ops[k],
        )

        b = evalt(
            M[i, k],
            m[k + 1, j],
            ops[k],
        )

        c = evalt(
            m[i, k],
            M[k + 1, j],
            ops[k],
        )

        d = evalt(
            m[i, k],
            m[k + 1, j],
            ops[k],
        )

        min_ = min(min_, a, b, c, d)
        max_ = max(max_, a, b, c, d)

    return (min_, max_)

if __name__ == "__main__":
    print(get_maximum_value(input()))
