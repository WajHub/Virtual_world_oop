from GUI.colors import Colors
from World.Body.animal import Animal
from World.point import Point


class Human(Animal):
    additional_power = 0
    age_when_used_special_skill = -10

    def __init__(self, point_location, world):
        super().__init__(point_location, world)
        self.set_name("Human")
        self.set_color(Colors.HUMAN)
        self.set_initiative(4)
        self.set_power(5)

    def repel_attack(self, attacker):
        return False

    def action(self):
        order = self.get_world().get_order()
        if self.get_world().get_order() == 'Up':
            self.set_last_position(self.get_point_location())
            self.set_point_location(Point(self.get_point_location().x, self.get_point_location().y - 1))
        elif order == "Down":
            self.set_last_position(self.get_point_location())
            self.set_point_location(Point(self.get_point_location().x, self.get_point_location().y + 1))
        elif order == "Left":
            self.set_last_position(self.get_point_location())
            self.set_point_location(Point(self.get_point_location().x - 1, self.get_point_location().y))
        elif order == "Right":
            self.set_last_position(self.get_point_location())
            self.set_point_location(Point(self.get_point_location().x + 1, self.get_point_location().y))

    def can_use_ability(self):
        if self.age_when_used_special_skill + 10 <= self.get_age():
            return True
        return False

    def set_additional_power(self, i):
        self.additional_power = i

    def get_additional_power(self):
        return self.additional_power

    def set_age_when_used_special_skill(self, age):
        self.age_when_used_special_skill = age
