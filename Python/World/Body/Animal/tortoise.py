from World.Body.animal import Animal
from World.point import Point
from GUI.colors import Colors
from random import randint


class Tortoise(Animal):
    def __init__(self, point_location, world):
        super().__init__(point_location, world)
        self.set_name("Tortoise")
        self.set_color(Colors.TORTOISE)
        self.set_initiative(1)
        self.set_power(2)

    def action(self):
        point = Point(self.get_point_location().get_x(), self.get_point_location().get_y())
        new_point = Point(self.get_point_location().get_x(), self.get_point_location().get_y())
        random_number = randint(1, 101) % 4
        if random_number == 0:
            self.random_location(new_point)
        self.set_last_position(point)
        self.set_point_location(new_point)

    def repel_attack(self, attacker):
        return attacker.get_power() < 5
