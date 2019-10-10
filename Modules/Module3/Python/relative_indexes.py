"""
Demonstrates using relative indexes in lists.
"""

#A list named directions containing the
#values "North", "South", "East" and "West"
directions = ["North", "South", "East", "West"]

#Prints the first element in the directions list
#using a relative (negative) index
print(directions[-4])

#Prints the last element in the directions list
#using a relative (negative) index
print(directions[-1])

#Tries to print the element in the directions list at index -5
try :
  print(directions[-5])
except IndexError:
  print("No index -5")

#Tries to print the element in the directions list at index 10
try :
  print(directions[10])
except IndexError:
  print("No index 10")
