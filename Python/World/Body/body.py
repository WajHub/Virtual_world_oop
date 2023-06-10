import random
from abc import ABC, abstractmethod

from GUI.colors import Colors
from World.point import Point


class Body(ABC):
    def __init__(self, point_location, world):
        self.initiative = None
        self.power = None
        self.name = None
        self.color = None
        self.age = 0
        self.point_location = None
        self.able_to_action = False
        self.alive = True
        self.world = world
        self.point_location = point_location

    def random_location(self, new_point):
        x = self.point_location.get_x()
        y = self.point_location.get_y()
        new_point.set_x(x)
        new_point.set_y(y)
        tmp = True
        while tmp:
            randomNumber = random.randint(1, 4)
            if randomNumber == 1:
                if x < 20:
                    new_point.set_x(new_point.get_x() + 1)
                    tmp = False
            elif randomNumber == 2:
                if x > 1:
                    new_point.set_x(new_point.get_x() - 1)
                    tmp = False
            elif randomNumber == 3:
                if y < 20:
                    new_point.set_y(new_point.get_y() + 1)
                    tmp = False
            elif randomNumber == 4:
                if y > 1:
                    new_point.set_y(new_point.get_y() - 1)
                    tmp = False

    def random_location_empty(self, body, new_point):
        x = body.get_point_location().get_x()
        y = body.get_point_location().get_y()
        # new_point = Point(x, y)
        tmp = True
        while tmp:
            randomNumber = random.randint(1, 4)
            if randomNumber == 1:
                if x < 20 and body.world.boxes[y - 1][x].color.name == 'EMPTY':
                    new_point.set_x(new_point.get_x()+1)
                    tmp = False
            elif randomNumber == 2:
                if x > 1 and body.world.boxes[y - 1][x - 2].color.name == 'EMPTY':
                    new_point.set_x(new_point.get_x()-1)
                    tmp = False
            elif randomNumber == 3:
                if y < 20 and body.world.boxes[y][x - 1].color.name == 'EMPTY':
                    new_point.set_y(new_point.get_y()+1)
                    tmp = False
            elif randomNumber == 4:
                if y > 1 and body.world.boxes[y - 2][x - 1].color.name == 'EMPTY':
                    new_point.set_y(new_point.get_y()-1)
                    tmp = False

    def new_body(self, point):
        from World.Body.Animal.wolf import Wolf
        from World.Body.Animal.antelope import Antelope
        from World.Body.Animal.sheep import Sheep
        from World.Body.Animal.fox import Fox
        from World.Body.Animal.tortoise import Tortoise
        if self.color == Colors.WOLF:
            self.world.add_body(Wolf(point, self.world))
        elif self.color == Colors.SHEEP:
            self.world.add_body(Sheep(point, self.world))
        elif self.color == Colors.ANTELOPE:
            self.world.add_body(Antelope(point, self.world))
        elif self.color == Colors.FOX:
            self.world.add_body(Fox(point, self.world))
        elif self.color == Colors.TORTOISE:
            self.world.add_body(Tortoise(point, self.world))
        # elif self.color == Colors.GRASS:
        #     # self.world.add_body(Grass(point, self.world))
        # elif self.color == Colors.DANDELION:
        #     # self.world.add_body(Dandelion(point, self.world))
        # elif self.color == Colors.GUARANA:
        #     # self.world.add_body(Guarana(point, self.world))
        # elif self.color == Colors.BELLADONNA:
        #     # self.world.add_body(Belladonna(point, self.world))
        # elif self.color == Colors.SOSNOWSKYSHOGWEED:
        #     # self.world.add_body(SosnowskysHogweed(point, self.world))

    def increment_age(self):
        self.age += 1

    @abstractmethod
    def move(self):
        pass

    @abstractmethod
    def collision(self, other):
        pass

    @abstractmethod
    def action(self):
        pass

    # Getters and setters

    def set_name(self, name):
        self.name = name

    def set_power(self, power):
        self.power = power

    def set_initiative(self, initiative):
        self.initiative = initiative

    def set_age(self, age):
        self.age = age

    def set_point_location(self, point_location):
        self.point_location = point_location

    def set_able_to_action(self, able_to_action):
        self.able_to_action = able_to_action

    def set_alive(self, alive):
        self.alive = alive

    def set_world(self, world):
        self.world = world

    def set_color(self, color):
        self.color = color

    def get_name(self):
        return self.name

    def get_power(self):
        return self.power

    def get_initiative(self):
        return self.initiative

    def get_age(self):
        return self.age

    def get_point_location(self):
        return self.point_location

    def is_able_to_action(self):
        return self.able_to_action

    def is_alive(self):
        return self.alive

    def get_world(self):
        return self.world

    def get_color(self):
        return self.color

