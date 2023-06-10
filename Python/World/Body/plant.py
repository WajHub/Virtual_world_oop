from abc import abstractmethod, ABC
from random import random

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
            free_spaces = self.get_world().free_spaces(self)
            if free_spaces > 0:
                new_point = Point(self.get_point_location().get_x(), self.get_point_location().get_y())
                self.random_location_empty(self, new_point)
                self.new_body(new_point)
                # self.getWorld().getNews_panel().add_news(
                #     self.getName() + " has grown on (" + new_point.getX() + ", " + new_point.getY() + ")")
            # else:
            #     self.getWorld().getNews_panel().add_news("Nothing happened")
        # else:
        #     self.getWorld().getNews_panel().add_news("Nothing happened")

    def collision(self, attacker):
        if self.get_power() > attacker.get_power():
            # self.get_world().getNews_panel().add_news(
            #     attacker.getName() + " has eaten " + self.getName() + " and dies on (" + attacker.getPoint_location().getX() + ", " + attacker.getPoint_location().getY() + ")")
            self.get_world().getBoxes[attacker.get_point_location().get_y() - 1][
                attacker.get_point_location().get_x() - 1].setColor(Colors.EMPTY)
            self.get_world().delete_body2(attacker)
            self.get_world().delete_body(self)
        else:
            # self.getWorld().getNews_panel().add_news(
            #     attacker.getName() + " has eaten " + self.getName() + " on (" + self.getPoint_location().getX() + ", " + self.getPoint_location().getY() + ")")
            if self.get_stronger() > 0:
                attacker.set_power(attacker.get_ower() + self.get_stronger())
                # self.get_world().getNews_panel().add_news(
                #     attacker.getName() + " has grown stronger and now has " + str(attacker.getPower()) + " power")
            self.get_world().delete_body(self)
            self.get_world().getBoxes[self.get_point_location().get_y() - 1][
                self.getPoint_location().get_x() - 1].setColor(attacker.getColor())

    @abstractmethod
    def get_stronger(self):
        pass
