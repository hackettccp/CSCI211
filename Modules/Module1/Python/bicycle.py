"""
Bicycle Object.
"""

#Class Header
class Bicycle :

  """
  Initializer that creates three fields
  """
  def __init__(self, gear_in, speed_in, color_in) :
    self.gear = gear_in
    self.speed = speed_in
    self.color = color_in

  #ACCESSORS
  """
  Accessor function for the gear field
  """
  def getgear(self) :
    return self.gear

  """
  Accessor function for the speed field
  """
  def getspeed(self) :
    return self.speed

  """
  Accessor function for the color field
  """
  def getcolor(self) :
    return self.color

  #MUTATORS
  """
  Mutator function for the gear field
  """
  def setgear(self, gear_in) :
      self.gear = gear_in

  """
  Mutator function for the speed field
  """
  def setspeed(self, speed_in) :
    self.speed = speed_in

  """
  Mutator function for the color field
  """
  def setcolor(self, color_in) :
    self.color = color_in


