def perm(n, k):
    r = 1
    for i in range(n, n - k, -1):
        r *= i
    return r % 1000000

if __name__ == "__main__":
    n, k = map(int, input().split())
    print(perm(n, k))
