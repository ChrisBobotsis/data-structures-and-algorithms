# Uses python3
import sys

def get_number_of_inversions(a, b, left, right):
    number_of_inversions = 0
    if right - left <= 1:
        return number_of_inversions
    ave = (left + right) // 2
    number_of_inversions += get_number_of_inversions(a, b, left, ave)
    number_of_inversions += get_number_of_inversions(a, b, ave, right)
    #write your code here
    D = []
    A = a[left:ave]
    B = a[ave:right]
    while len(B) > 0 and len(A) > 0:
        if B[0] < A[0]:
            #number_of_inversions += 1
            D.append(B[0])
            B.pop(0)
            number_of_inversions += len(A)
        else:
            D.append(A[0])
            A.pop(0)
    # Append the rest
    D += A + B
    a[left:right] = D
    return number_of_inversions

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    b = n * [0]
    print(get_number_of_inversions(a, b, 0, len(a)))
