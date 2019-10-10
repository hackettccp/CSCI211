"""
Demonstrates iterating/looping through a list
"""

#A list named temperatures
temperatures = [34.56, 56.45, 45.98, 47.62, 67.87, 55.12]

#Prints every value in the temperatures list using a for loop
for t in temperatures :
  print(t)

#********************************#
print()

"""
#Prints every value in the temperatures list using the
#range function in a for loop
for i in range(len(temperatures)) :
  print(temperatures[i])
"""
#********************************#
print()

"""
#Prints the first half of the temperatures list
#using a for loop
for i in range(len(temperatures)//2) :
  print(temperatures[i])
"""
#********************************#
print()

"""
#Prints the second half of the temperatures list
#using a for loop
for i in range(len(temperatures)//2, len(temperatures)) :
  print(temperatures[i])
"""
#********************************#
print()

"""
#Prints the temperatures list in reverse
#using a for loop
for i in range(len(temperatures)-1, -1, -1) :
  print(temperatures[i])
"""
