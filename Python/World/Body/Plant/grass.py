from World.Body.plant import Plant
from World.point import Point
from GUI.colors import Colors


class Grass(Plant):
    def __init__(self, point_location, world):
        super().__init__(point_location, world)
        self.set_name("Grass")
        self.set_power(0)
        self.set_color(Colors.GRASS)

    def get_stronger(self):
        return 0
