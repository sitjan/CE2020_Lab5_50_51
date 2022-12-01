f= open("random3.csv")
csv =[]
for i in f:
    csv.append(i)
csv = csv[3:]
newCsv=[]
for i in range(1,len(csv),2):
    newCsv.append(csv[i])
quickCsv =[]
for i in range(0,len(newCsv),2):
    quickCsv.append(newCsv[i])
print(quickCsv)
insertCsv=[]
for i in range(1,len(newCsv),2):
    insertCsv.append(newCsv[i])
for i in insertCsv:
    print(i)
quick=open("randomInsert.csv","w")
for i in insertCsv:
    quick.write(i)
