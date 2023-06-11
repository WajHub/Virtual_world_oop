from GUI.colors import Colors
from GUI.main_window import MainWindow
from World.Body.Animal.antelope import Antelope
from World.Body.Animal.fox import Fox
from World.Body.Animal.human import Human
from World.Body.Animal.sheep import Sheep
from World.Body.Animal.tortoise import Tortoise
from World.Body.Animal.wolf import Wolf
from World.Body.Plant.belladonna import Belladonna
from World.Body.Plant.dandelion import Dandelion
from World.Body.Plant.grass import Grass
from World.Body.Plant.guarana import Guarana
from World.Body.Plant.sosnowskys_hogweed import SosnowskysHogweed
from World.point import Point


class World:
    mainWindow = None
    xSize = 20
    ySize = 20
    bodies = []
    boxes = [[0 for _ in range(20)] for _ in range(20)]
    turn = 0
    human_is_alive = True
    human_special_ability_is_active = False
    order = None
    points_sosnowskys_hogweed = []

    def __init__(self):
        self.mainWindow = MainWindow(self)
        self.start_game()

    def start_game(self):
        wolf = Wolf(Point(1, 1), self)
        self.add_body(wolf)
        self.add_body(Wolf(Point(2, 1), self))
        self.add_body(Tortoise(Point(2, 4), self))
        self.add_body(Fox(Point(10, 4), self))
        self.add_body(Antelope(Point(10, 14), self))
        self.add_body(Sheep(Point(10, 10), self))

        self.add_body(Belladonna(Point(10, 11), self))
        self.add_body(Dandelion(Point(15, 11), self))
        self.add_body(Grass(Point(7, 7), self))
        self.add_body(Guarana(Point(7, 9), self))
        self.add_body(SosnowskysHogweed(Point(5, 11), self))
        human = Human(Point(20, 20), self)
        self.add_body(human)
        self.mainWindow.start()

    def make_turn(self):
        if self.turn % 10 == 0:
            self.mainWindow.clear_text()
        self.mainWindow.add_text("\nTurn: " + str(self.turn))
        i = 0
        while i < len(self.bodies):
            body = self.bodies[i]
            if body is not None:
                if body.is_able_to_action():
                    if not body.is_alive():
                        self.delete_body(body)
                    else:
                        body.increment_age()
                        self.mainWindow.add_text("\n")
                        self.mainWindow.add_text(body.get_name() + ' [' + str(body.get_power()) + "] " + "---> ")
                        body.move()
                else:
                    body.set_able_to_action(True)
            i += 1

        self.turn += 1
        self._human_special_ability()
        self.mainWindow.add_text("\n")
        self.mainWindow.add_text("\n")

    def add_body(self, body):
        for i in range(len(self.bodies)):
            if self.bodies[i].get_initiative() < body.get_initiative():
                self.bodies.insert(i, body)
                self.boxes[body.get_point_location().get_y() - 1][body.get_point_location().get_x() - 1].set_color(
                    body.get_color())
                return

        self.bodies.append(body)
        self.boxes[body.get_point_location().get_y() - 1][body.get_point_location().get_x() - 1].set_color(
            body.get_color())

    def delete_body2(self, body):
        if isinstance(body, Human):
            self.human_is_alive = False

        # boxes[body.get_point_location().y - 1][body.get_point_location().x - 1].set_color(Color_obj.EMPTY)
        body.set_alive(False)

    def delete_body(self, body):
        if isinstance(body, Human):
            self.human_is_alive = False
        # boxes[body.get_point_location().y - 1][body.get_point_location().x - 1].set_color(Color_obj.EMPTY)
        self.bodies.remove(body)

    def free_spaces(self, body):
        result = 0
        point = body.get_point_location()
        if point.get_x() == 1:
            if self.boxes[point.y - 1][point.x].get_color() == Colors.EMPTY:
                result += 1
        elif point.get_x() == 20:
            if self.boxes[point.y - 1][point.x - 2].get_color() == Colors.EMPTY:
                result += 1
        else:
            if self.boxes[point.y - 1][point.x].get_color() == Colors.EMPTY:
                result += 1
            if self.boxes[point.y - 1][point.x - 2].get_color() == Colors.EMPTY:
                result += 1

        if point.get_y() == 1:
            if self.boxes[point.y][point.x - 1].get_color() == Colors.EMPTY:
                result += 1
        elif point.get_y() == 20:
            if self.boxes[point.y - 2][point.x - 1].get_color() == Colors.EMPTY:
                result += 1
        else:
            if self.boxes[point.y][point.x - 1].get_color() == Colors.EMPTY:
                result += 1
            if self.boxes[point.y - 2][point.x - 1].get_color() == Colors.EMPTY:
                result += 1

        return result

    def get_body(self, point):
        for body in self.bodies:
            if body.get_point_location() == point:
                return body
        return None

    def order_is_correct(self):
        if self.human_is_alive:
            human = None
            for body in self.bodies:
                if isinstance(body, Human):
                    human = body
                    break
            if self.order == "Up":
                if human.get_point_location().get_y() > 1:
                    return True
                return False
            elif self.order == "Down":
                if human.get_point_location().get_y() < 20:
                    return True
                return False
            elif self.order == "Left":
                if human.get_point_location().get_x() > 1:
                    return True
                return False
            elif self.order == "Right":
                if human.get_point_location().get_x() < 20:
                    return True
                return False
            elif self.order == "1":
                if human.can_use_ability():
                    self.human_special_ability_is_active = True
                    human.set_additional_power(5)
                    human.set_power(human.get_power() + human.get_additional_power())
                    self.mainWindow.add_text("Human use special ability!!!\n")
                    human.set_age_when_used_special_skill(human.get_age())
                    return False
                else:
                    self.mainWindow.add_text("Human can't use special ability!\n")

                    return False

            return False

        return True

    def add_sosnowskys_hogweed(self, point):
        self.points_sosnowskys_hogweed.append(point)

    @property
    def get_main_window(self):
        return self.mainWindow

    @property
    def get_boxes(self):
        return self.boxes

    def set_order(self, order):
        self.order = order

    def get_order(self):
        return self.order

    def _human_special_ability(self):
        if self.human_is_alive and self.human_special_ability_is_active:
            for body in self.bodies:
                if isinstance(body, Human):
                    human = body
                    if human.get_additional_power() > 0:
                        human.set_additional_power(human.get_additional_power() - 1)
                        human.set_power(human.get_power() - 1)
                        break
                    else:
                        self.human_special_ability_is_active = False
