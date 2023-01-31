import numpy as np
from matplotlib import pyplot as plt 
from statistics import median

f = open("test.txt", "r")

lines = f.readline()
worker = list(i.split(" ")for i in lines.split(","))
worker.pop()
kmp = [int(i[0]) for i in worker]
bmh = [int(i[1]) for i in worker]

print("KMP median " + str(median(kmp)) + " average: " + str(sum(kmp)// len(kmp)))
print("BMH median " + str(median(bmh))+ " average: " + str(sum(bmh)// len(bmh)))

szin = "red"


n, bins, patches=plt.hist(kmp,bins=20, color=szin)
plt.xlabel("Microseconds")
plt.ylabel("Occurrences")
plt.title("Knuth-Morris-Pratt 1M Worst Case")
plt.show()

n, bins, patches=plt.hist(bmh,bins=20, color=szin)
plt.xlabel("Microseconds")
plt.ylabel("Occurrences")
plt.title("Boyer-Moore-Horspool 1M Worst Case")
plt.show()

