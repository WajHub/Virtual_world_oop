from abc import abstractmethod, ABC
from random import randint

from GUI.colors import Colors
from World.Body.body import Body
from World.point import Point


class Animal(Body, ABC):
    last_position = None

    def __init__(self, point_location, world):
        super().__init__(point_location, world)
        self.set_last_position(self.get_point_location())

    def _random_location_born(self, new_point, other):
        free_spaces = self.get_world().free_spaces(self)
        free_spaces_other = self.get_world().free_spaces(other)
        if free_spaces == 0 and free_spaces_other == 0:
            return False
        elif free_spaces == 0:
            new_point.x = other.get_point_location().x
            new_point.y = other.get_point_location().y
            while True:
                self.random_location_empty(other, new_point)
                if self.get_world().get_boxes[new_point.y - 1][new_point.x - 1].get_color() == Colors.EMPTY:
                    return True
        elif free_spaces_other == 0:
            new_point.x = self.get_point_location().x
            new_point.y = self.get_point_location().y
            while True:
                self.random_location_empty(self, new_point)
                if self.get_world().get_boxes[new_point.y - 1][new_point.x - 1].get_color() == Colors.EMPTY:
                    return True
        else:
            randomNumber = randint(1, 101) % 2
            if randomNumber > 50:
                new_point.x = self.get_point_location().x
                new_point.y = self.get_point_location().y
                while True:
                    self.random_location_empty(self, new_point)
                    if self.get_world().get_boxes[new_point.y - 1][new_point.x - 1].get_color() == Colors.EMPTY:
                        return True
            else:
                new_point.x = other.get_point_location().x
                new_point.y = other.get_point_location().y
                while True:
                    self.random_location_empty(other, new_point)
                    if self.get_world().get_boxes[new_point.y - 1][new_point.x - 1].get_color() == Colors.EMPTY:
                        return True

    def _born(self, attacker):
        if self.get_age() > 3 and attacker.get_age() > 3:
            new_point = Point(self.get_point_location().get_x(), self.get_point_location().get_y())
            if self._random_location_born(new_point, attacker):
                self.new_body(new_point)
                # self.get_world().getNews_panel().add_news(
                # "Born new animal (" + str(new_point.get_x()) + "," + str(new_point.get_y()) + ")")
        #     else:
        #         # self.get_world().getNews_panel().add_news("No place to born new animal")
        # else:
        #     # self.get_world().getNews_panel().add_news("Animals are too young to born new animal")

    def _back_move(self):
        x = self.point_location.get_x()
        y = self.point_location.get_y()
        self.set_point_location(self.get_last_position())
        self.set_last_position(Point(x, y))
        self.world.get_boxes[self.point_location.y - 1][self.point_location.x - 1].set_color(self.color)

    def action(self):
        x = self.point_location.x
        y = self.point_location.y
        point = Point(x, y)
        self.random_location(point)
        self.set_last_position(self.get_point_location())
        self.set_point_location(point)

    def move(self):
        world = self.get_world()
        self.action()
        if self.changed_position():
            if world.get_boxes[self.get_point_location().get_y() - 1][self.get_point_location().get_x() - 1].get_color() != Colors.EMPTY:
                self._back_move()
                world.get_boxes[self.point_location.y - 1][self.point_location.x - 1].set_color(Colors.EMPTY)
                tmp = world.get_body(self.last_position)
                if tmp is not None:
                    self._back_move()
                    tmp.collision(self)
            else:
                # world.get_news_panel().add_news("Move to ({}, {})".format(self.point_location.x, self.point_location.y))
                world.get_boxes[self.point_location.y - 1][self.point_location.x - 1].set_color(self.get_color())
                world.get_boxes[self.last_position.y - 1][self.last_position.x - 1].set_color(Colors.EMPTY)

    def collision(self, attacker):
        if isinstance(attacker, Animal):
            other_animal = attacker
            if other_animal.get_color() == self.get_color():
                other_animal._back_move()
                self._born(other_animal)
            else:
                if self.repel_attack(other_animal):
                    print("repel attack")
                    # self.world.get_news_panel().add_news("Repel attack")
                else:
                    if self.get_power() > other_animal.get_power():
                        # self.world.get_news_panel().add_news(self.get_name() + " is killing " + other_animal.get_name())
                        self.world.delete_body2(other_animal)
                        self.world.get_boxes[self.point_location.y - 1][
                            self.point_location.x - 1].set_color(self.get_color())
                    else:
                        # self.world.get_news_panel().add_news(other_animal.get_name() + " is killing " + self.get_name())
                        self.world.delete_body(self)
                        self.world.get_boxes[other_animal.get_point_location().y - 1][
                            other_animal.get_point_location().x - 1].set_color(other_animal.get_color())
        else:
            if self.get_power() > attacker.get_power():
                # self.world.get_news_panel().add_news(
                    # attacker.get_name() + " is eating " + self.get_name() + " and dies")
                self.world.delete_body2(attacker)
                self.world.get_boxes[attacker.get_point_location().y - 1][
                    attacker.get_point_location().x - 1].set_color(self.get_color())
            else:
                # self.world.get_news_panel().add_news(self.get_name() + " is eating " + attacker.get_name())
                self.world.delete_body(self)
                self.world.get_boxes[self.point_location.y - 1][
                    self.point_location.x - 1].set_color(attacker.get_color())

    def changed_position(self):
        return self.last_position != self.point_location

    def set_last_position(self, last_position):
        self.last_position = last_position

    def get_last_position(self):
        return self.last_position

    @abstractmethod
    def repel_attack(self, attacker):
        pass
