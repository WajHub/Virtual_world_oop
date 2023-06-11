from GUI.colors import Colors
from World.Body.animal import Animal
from World.point import Point


class CyberSheep(Animal):
    def __init__(self, point_location, world):
        super().__init__(point_location, world)
        self.set_name("CyberSheep")
        self.set_color(Colors.CYBERSHEEP)
        self.set_initiative(4)
        self.set_power(11)

    def repel_attack(self, attacker):
        return False

    def action(self):
        if len(self.world.points_sosnowskys_hogweed) == 0:
            super().action()
        else:
            nearest_point = self.world.points_sosnowskys_hogweed[0]
            for point in self.world.points_sosnowskys_hogweed:
                if abs(self.point_location.x - point.x) + abs(self.point_location.y - point.y) < abs(
                        self.point_location.x - nearest_point.x) + abs(self.point_location.y - nearest_point.y):
                    nearest_point = point
            differencex = self.point_location.x - point.x
            if differencex > 0:
                x = self.point_location.x
                y = self.point_location.y
                self.set_last_position(self.get_point_location())
                self.set_point_location(Point(x - 1, y))
            elif differencex < 0:
                x = self.point_location.x
                y = self.point_location.y
                self.set_last_position(self.get_point_location())
                self.set_point_location(Point(x + 1, y))
            else:
                differencey = self.point_location.y - point.y
                if differencey > 0:
                    x = self.point_location.x
                    y = self.point_location.y
                    self.set_last_position(self.get_point_location())
                    self.set_point_location(Point(x, y - 1))
                elif differencey < 0:
                    x = self.point_location.x
                    y = self.point_location.y
                    self.set_last_position(self.get_point_location())
                    self.set_point_location(Point(x, y + 1))

