n = int(input("Enter(end with q): "))
edges = []

while True:
    line = input().strip()
    if line == 'q':
        break
    u, v = map(int, line.split())
    edges.append((u, v))

p = [-1] * n

def find(x):
    if p[x] == -1:
        return x
    p[x] = find(p[x])
    return p[x]

def union(x, y):
    xr, yr = find(x), find(y)
    if xr != yr:
        p[yr] = xr

for u, v in edges:
    union(u-1, v-1)

res = sum(1 for i in range(n) if p[i] == -1) - 1
print(res)
