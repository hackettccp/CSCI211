#Imports the Bicycle object
from bicycle import Bicycle

"""
Demonstrates the use of the Bicycle object
"""

#Creates an instance of a Bicycle Object with three arguments
test_bike = Bicycle(9, 12, "orange")

#ACCESSORS
#Prints test_bike's gear, speed, and color using accessor functions
print("test_bike's gear =", test_bike.getgear())
print("test_bike's speed =", test_bike.getspeed())
print("test_bike's color =", test_bike.getcolor())

#MUTATORS

print()
#Sets test_bike's gear to 8 using a mutator
test_bike.setgear(8);

#Sets test_bike's speed to 11
test_bike.setspeed(11)

#Sets test_bike's color to "yellow"
test_bike.setcolor("yellow")

#Prints test_bike's gear, speed, and color again
print("test_bike's gear =", test_bike.getgear())
print("test_bike's speed =", test_bike.getspeed())
print("test_bike's color =", test_bike.getcolor())


#List of Bicycles
bikes = [];

bikes.append(test_bike)
bikes.append(Bicycle(4, 8, "Blue"))
bikes.append(Bicycle(6, 13, "Red"))

print("\nBike List:")
for i in range(0, len(bikes)):
    print("bike ", i, "'s gear = ", bikes[i].getgear(), sep="")
    print("bike ", i, "'s speed = ", bikes[i].getspeed(), sep="")
    print("bike ", i, "'s color = ", bikes[i].getcolor(), sep="")
