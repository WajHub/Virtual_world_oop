from GUI.colors import Colors
from World.Body.animal import Animal
from World.point import Point


class Tortoise(Animal):
    def __init__(self, point_location, world):
        super().__init__(point_location, world)
        self.set_name("Tortoise")
        self.set_color(Colors.TORTOISE)
        self.set_initiative(1)
        self.set_power(2)
