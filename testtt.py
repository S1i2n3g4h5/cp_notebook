n, q = map(int, input().split())
sequence = list(map(int, input().split()))
queries = []
for _ in range(q):
    l, r = map(int, input().split())
    queries.append((l, r))


results = []
for l,r in queries:
    s = set()
    for i in range(l-1,r):
        s.add(sequence[i])  
        
    
    x=0
    while x in s:
        x+=1
    results.append(x)


for result in results:
    print(result)
