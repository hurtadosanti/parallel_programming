size = 19
split = 8
partitions = int(size / split) + (0 if size % split == 0 else 1)
print('Partitions', partitions)
counter = 0
for i in range(split):
    print(p, i,counter)
    print(i+p*split)
    counter+=1
print('Partition---',p)
