from collections import deque

d = deque()

#"Push Back"
d.append(1)                             #Deque: 1
d.append(2)                             #Deque: 1 2
d.append(3)                             #Deque: 1 2 3

#"Push Front"
d.appendleft(4)                         #Deque: 4 1 2 3
d.appendleft(5)                         #Deque: 5 4 1 2 3
d.appendleft(6)                         #Deque: 6 5 4 1 2 3

#"Pop Back"
x = d.pop()                             #Deque: 6 5 4 1 2
print("Popped", x, "from back")

#"Pop Front"
x = d.popleft()                         #Deque: 5 4 1 2
print("Popped", x, "from front")
