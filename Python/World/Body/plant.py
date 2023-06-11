from abc import abstractmethod, ABC
import random

from GUI.colors import Colors
from World.Body.body import Body
from World.point import Point


class Plant(Body, ABC):
    def __init__(self, point_location, world):
        super().__init__(point_location, world)
        self.set_initiative(0)

    def move(self):
        self.action()

    def action(self):
        randomNumber = random.randint(1, 100)
        if randomNumber < 7:
            free_spaces = self.world.free_spaces(self)
            if free_spaces > 0:
                new_point = Point(self.get_point_location().get_x(), self.get_point_location().get_y())
                self.random_location_empty(self, new_point)
                self.new_body(new_point)
                self.world.mainWindow.add_text(self.get_name() + " has grown on (" + str(new_point.get_x()) + ", " + str(new_point.get_y()) + ")")
            else:
                self.world.mainWindow.add_text("Nothing happened")
        else:
            self.world.mainWindow.add_text("Nothing happened")

    def collision(self, attacker):
        if self.get_power() > attacker.get_power():
            self.world.mainWindow.add_text(attacker.get_name() + " has eaten " + self.get_name() +
                    "and dies on (" + str(self.get_point_location().get_x()) + ", " + str(self.get_point_location().get_y()) + ")")
            self.world.get_boxes[attacker.get_point_location().get_y() - 1][
                attacker.get_point_location().get_x() - 1].set_color(Colors.EMPTY)
            self.world.delete_body2(attacker)
            self.world.delete_body(self)
        else:
            self.world.mainWindow.add_text(attacker.get_name() + " has eaten " + self.get_name() +
                            "on ("+ str(self.get_point_location().get_x()) + ", " + str(self.get_point_location().get_y()) + ")")
            if self.get_stronger() > 0:
                attacker.set_power(attacker.get_power() + self.get_stronger())
                self.world.mainWindow.add_text(attacker.get_name() + " has grown stronger and now has " + str(attacker.get_power()) + " power")
            self.world.delete_body(self)
            self.world.get_boxes[self.get_point_location().get_y() - 1][
                self.get_point_location().get_x() - 1].set_color(attacker.get_color())

    @abstractmethod
    def get_stronger(self):
        pass
