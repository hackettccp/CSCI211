from queue import Queue

q = Queue()

#"Push"
q.put(1)                                #Queue: 1
q.put(2)                                #Queue: 1 2
q.put(3)                                #Queue: 1 2 3
q.put(4)                                #Queue: 1 2 3 4
q.put(5)                                #Queue: 1 2 3 4 5
q.put(6)                                #Queue: 1 2 3 4 5 6

#"Pop"
x = q.get()                             #Queue: 2 3 4 5 6
print("Popped", x, "from front")
x = q.get()                             #Queue: 3 4 5 6
print("Popped", x, "from front")


