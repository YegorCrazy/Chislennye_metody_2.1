import matplotlib.pyplot as plt

file_x = open("xoutput", "r")
x = [float(line) for line in file_x]

file_y1 = open("y1output", "r")
y1 = [float(line) for line in file_y1]

file_y2 = open("y2output", "r")
y2 = [float(line) for line in file_y2]

plt.scatter(x, y1, label='2 accuracy', color='b')
plt.scatter(x, y2, label='4 accuracy', color='g')
plt.xlabel('x')
plt.ylabel('y')
plt.show()

##for i in x:
##    print(i)

file_x.close()
