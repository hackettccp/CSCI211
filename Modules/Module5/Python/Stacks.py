from queue import LifoQueue

s = LifoQueue()

#"Push"
s.put(1)                                #Stack: 1
s.put(2)                                #Stack: 1 2
s.put(3)                                #Stack: 1 2 3
s.put(4)                                #Stack: 1 2 3 4
s.put(5)                                #Stack: 1 2 3 4 5
s.put(6)                                #Stack: 1 2 3 4 5 6

#"Pop"
x = s.get()                             #Stack: 1 2 3 4 5
print("Popped", x, "from back")
x = s.get()                             #Stack: 1 2 3 4
print("Popped", x, "from back")


