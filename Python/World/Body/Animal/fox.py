from GUI.colors import Colors
from World.Body.animal import Animal
from World.point import Point


class Fox(Animal):
    def __init__(self, point_location, world):
        super().__init__(point_location, world)
        self.set_name("Fox")
        self.set_initiative(7)
        self.set_power(3)
        self.set_color(Colors.FOX)

    def repel_attack(self, attacker):
        return False

    def action(self):
        point = Point(self.get_point_location().x, self.get_point_location().y)
        new_point = Point(self.get_point_location().x, self.get_point_location().y)
        tmp = True
        attempt = 0
        while tmp:
            self.random_location(new_point)
            tmp = False
            body = self.world.get_body(new_point)
            if isinstance(body, Animal):
                if body.get_power() > self.get_power():
                    new_point.x = point.x
                    new_point.y = point.y
                    tmp = True
                    attempt += 1
                    if attempt > 12:
                        tmp = False
        self.set_last_position(point)
        self.set_point_location(new_point)