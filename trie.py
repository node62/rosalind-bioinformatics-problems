import pyperclip

def f(u):
    with open(u) as f:
        d = f.read().splitlines()
    t = {}
    p = 1
    r = []
    for s in d:
        n = 1
        for c in s:
            if n not in t:
                t[n] = {}
            if c not in t[n]:
                p += 1
                t[n][c] = p
                r.append(f"{n} {p} {c}")
            n = t[n][c]
    print("\n".join(r))
    pyperclip.copy("\n".join(r))

f(input("Input file: ").strip('"'))