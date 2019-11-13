"""
Demonstrates a priority queue (heapq)
"""

import heapq                                #Imports the heapq module

data = [5, 2, 4, 3, 1]                      #A list of data

heapq.heapify(data)                         #Converts the list to a heap

print("Contents of data:", list(data))      #Prints the contents as a list

heapq.heappush(data, 6)                     #Pushes 6 into the heap

print("Contents of data:", list(data))      #Prints the current contents as a list

x = heapq.heappop(data)                     #Gets the value at the top of the heap
print("Value popped:", x)

while(len(list(data))):
    print("Value popped:", heapq.heappop(data))
