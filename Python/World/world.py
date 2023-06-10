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
    turn = 0
    human_is_alive = True
    human_special_ability_is_active = False
    order = None

    def __init__(self):
        self.mainWindow = MainWindow(self)
        self.start_game()

    def start_game(self):
        wolf = Wolf(Point(1, 1), self)
        self.add_body(wolf)
        self.add_body(Wolf(Point(2, 1), self))
        self.add_body(Wolf(Point(2, 3), self))
        self.add_body(Wolf(Point(2, 4), self))
        human = Human(Point(20, 20), self)
        self.add_body(human)
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
                    # news_panel.add_news("Human use special ability!!!")
                    human.set_age_when_used_special_skill(human.get_age())
                    return False
                else:
                    # news_panel.add_news("Human can't use special ability!")
                    return False

            return False

        return True

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
