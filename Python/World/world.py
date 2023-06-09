from GUI.colors import Colors
from GUI.main_window import MainWindow
from World.Body.Animal.human import Human
from World.Body.Animal.wolf import Wolf
from World.point import Point


class World:
    mainWindow = None
    xSize = 20
    ySize = 20
    bodies = []
    boxes = [[0 for _ in range(20)] for _ in range(20)]
    turn=0

    def __init__(self):
        self.mainWindow = MainWindow(self)
        self.start_game()

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

    def start_game(self):
        wolf = Wolf(Point(1, 10), self)
        self.add_body(wolf)
        self.mainWindow.start()

    def make_turn(self):
        i = 0
        while i < len(self.bodies):
            body = self.bodies[i]
            if body is not None:
                if body.is_able_to_action():
                    if not body.is_alive():
                        self.delete_body(body)
                    else:
                        body.increment_age()
                        # self.news_panel.add_title_name(body.get_name() + "---> ")
                        body.move()
                else:
                    body.set_able_to_action(True)
            i += 1

        self.turn += 1
        # self.human_special_ability()
        # self.news_panel.add_news(" ")

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

        if point.x == 1:
            if self.boxes[point.y - 1][point.x].get_color() == Colors.EMPTY.color:
                result += 1
        elif point.x == self.x_size:
            if self.boxes[point.y - 1][point.x - 2].get_color() == Colors.EMPTY.color:
                result += 1
        else:
            if self.boxes[point.y - 1][point.x].get_color() == Colors.EMPTY.color:
                result += 1
            if self.boxes[point.y - 1][point.x - 2].get_color() == Colors.EMPTY.color:
                result += 1

        if point.y == 1:
            if self.boxes[point.y][point.x - 1].get_color() == Colors.EMPTY.color:
                result += 1
        elif point.y == self.y_size:
            if self.boxes[point.y - 2][point.x - 1].get_color() == Colors.EMPTY.color:
                result += 1
        else:
            if self.boxes[point.y][point.x - 1].get_color() == Colors.EMPTY.color:
                result += 1
            if self.boxes[point.y - 2][point.x - 1].get_color() == Colors.EMPTY.color:
                result += 1

        return result

    def get_body(self, point):
        for body in self.bodies:
            if body.get_point_location() == point:
                return body
        return None

    @property
    def get_main_window(self):
        return self.mainWindow

    @property
    def get_boxes(self):
        return self.boxes
