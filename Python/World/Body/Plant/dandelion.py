from World.Body.plant import Plant
from World.point import Point
from GUI.colors import Colors
from random import randint


class Dandelion(Plant):
    def __init__(self, point_location, world):
        super().__init__(point_location, world)
        self.set_name("Dandelion")
        self.set_power(0)
        self.set_color(Colors.DANDELION)

    def action(self):
        for i in range(3, 0, -1):
            random_number = randint(0, 200)
            if random_number % 100 < 3:
                free_spaces = self.get_world().free_spaces(self)
                if free_spaces > 0:
                    new_point = Point(self.get_point_location().get_x(), self.get_point_location().get_y())
                    self.random_location_empty(self, new_point)
                    self.new_body(new_point)
                    # self.get_world().get_news_panel().add_news(
                    #     self.get_name() + " has grown on ({}, {})".format(new_point.get_x(), new_point.get_y()))
            #     else:
            #         self.get_world().get_news_panel().add_news("Nothing happened")
            # else:
            #     self.get_world().get_news_panel().add_news("Nothing happened")

    def get_stronger(self):
        return 0
