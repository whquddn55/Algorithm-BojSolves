from cmath import sin
from decimal import Decimal, getcontext

getcontext().prec = 50
pi = Decimal('3.141592653589793238462643383279502884197169399375105820974944')

a, b, c = input().split(' ')
a = Decimal(a)
b = Decimal(b)
c = Decimal(c)

def sin(x):
    x = x % Decimal(2 * pi)
    i, lasts, s, fact, num, sign = 1, 0, x, 1, x, 1
    while s != lasts:
        lasts = s
        i += 2
        fact *= i * (i-1)
        num *= x * x
        sign *= -1
        s += num / fact * sign
    return +s

def decide(mid: Decimal):
    return (a * mid + b * sin(mid).real) >= c

l = Decimal(0.0)
r = Decimal(200000.0)
mid = Decimal((l + r) / 2)
while r - l > Decimal(1e-30):
    mid = Decimal((l + r) / 2)
    if decide(mid):
        r = mid
    else:
        l = mid

print(round(mid, 6))

