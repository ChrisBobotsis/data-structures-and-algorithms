# Uses python3
import sys

def gcd_naive(a, b):
    current_gcd = 1
    for d in range(2, min(a, b) + 1):
        if a % d == 0 and b % d == 0:
            if d > current_gcd:
                current_gcd = d

    return current_gcd

def my_gcd(a, b):

    max_ = max(a,b)
    min_ = min(a,b)

    while (max_ % min_) != 0:
    
        tmp = max_

        max_ = min_

        min_ = tmp % min_

    return min_
    

if __name__ == "__main__":
    #input = sys.stdin.read()
    a, b = map(int, input().split())
    #print(gcd_naive(a, b))
    print(my_gcd(a, b))
