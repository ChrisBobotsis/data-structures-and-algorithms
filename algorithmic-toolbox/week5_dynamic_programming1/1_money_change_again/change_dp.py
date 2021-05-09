# Uses python3
import sys

COINS = [1, 3, 4]

def get_change(money):
    #write your code here
    mnc = [0] + [float("inf")]*(money)
    for m in range(1, money + 1):
        # mnc[m] = float("inf")
        for c in COINS:
            if m >= c:
                nc = mnc[m - c] + 1
            if nc < mnc[m]:
                mnc[m] = nc

    return mnc[money]

if __name__ == '__main__':
    m = int(sys.stdin.read())
    print(get_change(m))
