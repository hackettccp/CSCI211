"""
Demonstrates sorting numbers and strings.
"""

def insertionSort(a):
  for i in range(1, len(a)):
    value = a[i]
    j = i-1
    while j >= 0 and a[j] > value:
      a[j+1] = a[j]
      j -= 1
    a[j+1] = value


nums = [5, 4, 3, 2, 1]
strings = ["Coconut", "apple", "aVocado", "Banana"]

print("Before sorting:")
for x in nums:
  print(x)
print()
for x in strings:
  print(x)
print()

insertionSort(nums)
insertionSort(strings)

print("After sorting:")
for x in nums:
  print(x)
print()
for x in strings:
  print(x)
