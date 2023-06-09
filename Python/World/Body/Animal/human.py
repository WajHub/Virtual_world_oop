from GUI.colors import Colors


class Human:
    def __init__(self, world, point):
        self.world = world
        self.point = point
        self.alive = True
        self.color = Colors.HUMAN.color
        self.initiative = 4
        self.strength = 5
        self.initiative_counter = 0
        self.age = 0
        self.name = "Human"

    def action(self):
        if self.alive:
            self.age += 1
            self.initiative_counter += self.initiative
            if self.initiative_counter >= 5:
                self.initiative_counter = 0
                self.move()
                self.collision()
                self.breed()
                self.starve()

    def collision(self):
        if self.alive:
            for body in self.world.bodies:
                if body.get_point_location() == self.point and body != self:
                    if isinstance(body, Human):
                        self.world.human_is_alive = False
                    elif isinstance(body, Animal):
                        if body.get_strength() < self.strength:
                            self.world.delete_body(body)
                        else:
                            self.world.delete_body(self)

    def breed(self):
        if self.alive:
            if self.age >= 5:
                if self.world.free_spaces(self) > 0:
                    self.world.add_body(Human(self.world, self.world.get_random_free_point(self)))

    def move(self):
        if self.alive:
            self.world.boxes[self.point.y - 1][self.point.x - 1].set_color(Colors.EMPTY.color)
            self.point = self.world.get_random_free_point(self)
            self.world.boxes[self.point.y - 1][self.point.x - 1].set_color(self.color)

    def starve(self):
        pass

    def get_point_location(self):
        return self.point

    def set_point_location(self, point):
        self.point = point

    def get_color(self):
        return self.color

    def set_color(self, color):
        self.color = color

    def get_alive(self):
        return self.alive

    def set_alive(self, alive):
        self.alive = alive

    def get_initiative(self):
        return self.initiative

    def set_initiative(self, initiative):
        self.initiative = initiative

    def get_strength(self):
        return self.strength

    def set_strength(self, strength):
        self.strength = strength

