from World.Body import Animal
from World.Body.plant import Plant
from World.point import Point
from GUI.colors import Colors
from random import randint


class SosnowskysHogweed(Plant):
    def __init__(self, point_location, world):
        super().__init__(point_location, world)
        self.set_name("SosnowskysHogweed")
        self.set_power(999)
        self.set_color(Colors.SOSNOWSKYSHOGWEED)

    def kill_around(self):
        point = Point(self.get_point_location().get_x(), self.get_point_location().get_y())
        directions_y = [-1, 0, 1, 0, 1, -1, 1, -1]
        directions_x = [0, 1, 0, -1, 1, -1, -1, 1]
        for i in range(8):
            if (
                    1 <= point.get_x() + directions_x[i] <= self.get_world().get_x_size()
                    and 1 <= point.get_y() + directions_y[i] <= self.get_world().get_y_size()
            ):
                body = self.get_world().get_body(
                    Point(
                        point.get_x() + directions_x[i],
                        point.get_y() + directions_y[i]
                    )
                )
                if isinstance(body, Animal):
                    self.get_world().delete_body2(body)
                    self.get_world().get_boxes[point.get_y() + directions_y[i] - 1][
                        point.get_x() + directions_x[i] - 1
                        ].set_color(Colors.EMPTY)
                    # self.get_world().get_news_panel().add_news(
                    #     self.get_name()
                    #     + " has killed "
                    #     + body.get_name()
                    #     + " on ("
                    #     + str(body.get_point_location().get_x())
                    #     + ", "
                    #     + str(body.get_point_location().get_y())
                    #     + ")"
                    # )

    def collision(self, attacker):
        # self.get_world().get_news_panel().add_news(
        #     attacker.get_name()
        #     + " has eaten "
        #     + self.get_name()
        #     + " and dies on ("
        #     + str(self.get_point_location().get_x())
        #     + ", "
        #     + str(self.get_point_location().get_y())
        #     + ")"
        # )
        self.get_world().get_boxes[attacker.get_point_location().get_y() - 1][
            attacker.get_point_location().get_x() - 1
            ].set_color(Colors.EMPTY)
        self.get_world().delete_body2(attacker)
        self.get_world().delete_body(self)

    def action(self):
        random_number = randint(1, 101)
        if random_number < 2:
            free_spaces = self.get_world().free_spaces(self)
            if free_spaces > 0:
                new_point = Point(
                    self.get_point_location().get_x(), self.get_point_location().get_y()
                )
                self.random_location_empty(self, new_point)
                self.new_body(new_point)
                # self.get_world().get_news_panel().add_news(
                #     self.get_name()
                #     + " has grown on ("
                #     + str(new_point.get_x())
                #     + ", "
                #     + str(new_point.get_y())
                #     + ")"
                # )
        #     else:
        #         self.get_world().get_news_panel().add_news("Nothing happened")
        # else:
        #     self.get_world().get_news_panel().add_news("Nothing happened")
        self.kill_around()

    def get_stronger(self):
        return 0
