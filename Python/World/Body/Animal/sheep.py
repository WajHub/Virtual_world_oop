from GUI.colors import Colors
from World.Body.animal import Animal
from World.point import Point


class Sheep(Animal):
    def __init__(self, point_location, world):
        super().__init__(point_location, world)
        self.set_name("Sheep")
        self.set_color(Colors.SHEEP)
        self.set_initiative(4)
        self.set_power(4)

    def repel_attack(self, attacker):
        return False
