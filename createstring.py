import sys
import random


results = sys.argv
possibilities = ["A", "C", "G", "U"]
stringToUse = ""

for i in range(0, int(results[1])):
    stringToUse += random.choice(possibilities)#"U"

f = open("tryme.txt", "w")
f.write(stringToUse)
f.close()
