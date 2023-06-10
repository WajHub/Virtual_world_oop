from World.Body.plant import Plant
from World.point import Point
from GUI.colors import Colors


class Belladonna(Plant):
    def __init__(self, point_location, world):
        super().__init__(point_location, world)
        self.set_name("Belladonna")
        self.set_power(999)
        self.set_color(Colors.BELLADONNA)

    def get_stronger(self):
        return 0
