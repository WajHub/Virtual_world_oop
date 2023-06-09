from GUI.colors import Colors
from World.Body.animal import Animal


class Wolf(Animal):

    def __init__(self, point_location, world):
        super().__init__(point_location, world)
        self.set_name("Wolf")
        self.set_color(Colors.WOLF)
        self.set_power(9)
        self.set_initiative(5)

    def repel_attack(self, attacker):
        return False

