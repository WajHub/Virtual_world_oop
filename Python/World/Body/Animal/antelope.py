import random

from GUI.colors import Colors
from World.Body.animal import Animal
from World.point import Point


class Antelope(Animal):
    def __init__(self, point_location, world):
        super().__init__(point_location, world)
        self.set_name("Antelope")
        self.set_color(Colors.ANTELOPE)
        self.set_initiative(4)
        self.set_power(4)

    def action(self):
        point = Point(self.get_point_location().x, self.get_point_location().y)
        new_point = Point(self.get_point_location().x, self.get_point_location().y)
        range_val = 2
        while range_val > 0:
            self.random_location(new_point)
            self.set_point_location(new_point)
            if point.x == new_point.x and point.y == new_point.y:
                range_val = 2
            else:
                range_val -= 1
        self.set_last_position(point)
        self.set_point_location(new_point)

    def collision(self, attacker):
        randomNumber = random.randint(1, 100) % 2
        if randomNumber == 0 or self.get_world().free_spaces(self) == 0:
            self.collision(attacker)
        else:
            new_point = Point(self.get_point_location().x, self.get_point_location().y)
            self.random_location_empty(self, new_point)
            self.world.mainWindow.add_text("Move to (" + str(self.get_point_location().x) +
                                                       ", " + str(self.get_point_location().y) + ")")
            self.get_world().get_boxes[self.get_point_location().y - 1][self.get_point_location().x - 1].set_color(
                attacker.get_color())
            self.set_last_position(self.get_point_location())
            self.set_point_location(new_point)
            self.world.mainWindow.add_text("Run away to (" + str(self.get_point_location().x) +
                                                       ", " + str(self.get_point_location().y) + ")")
            self.get_world().get_boxes[self.get_point_location().y - 1][self.get_point_location().x - 1].set_color(
                self.get_color())

    def repel_attack(self, attacker):
        return False
