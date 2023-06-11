import tkinter as tk
from tkinter import simpledialog, messagebox

from GUI.colors import Colors
from World.Body.Animal.antelope import Antelope
from World.Body.Animal.cybersheep import CyberSheep
from World.Body.Animal.fox import Fox
from World.Body.Animal.sheep import Sheep
from World.Body.Animal.tortoise import Tortoise
from World.Body.Animal.wolf import Wolf
from World.Body.Plant.dandelion import Dandelion
from World.Body.Plant.belladonna import  Belladonna
from World.Body.Plant.grass import Grass
from World.Body.Plant.guarana import Guarana
from World.Body.Plant.sosnowskys_hogweed import SosnowskysHogweed
from World.point import Point


class Box:
    world = None
    board = None
    x = None
    y = None
    color = Colors.EMPTY
    button = None
    option_var = None

    def __init__(self, world, board, x, y):
        self.option_var = tk.StringVar()
        self.world = world
        self.board = board
        self.x = x
        self.y = y
        self.pixelVirtual = tk.PhotoImage(width=1, height=1)
        self.button = tk.Button(board, image=self.pixelVirtual, width=23, height=23, command=self.handle_click)
        self.button.config(bg=self.color.value)

    @property
    def get_button(self):
        return self.button

    def get_color(self):
        return self.color

    def set_color(self, color):
        self.color = color
        self.button.config(bg=self.color.value)

    def handle_click(self):
        if self.color == Colors.EMPTY:
            # print(f"Kliknięto przycisk na pozycji ({self.x}, {self.y})")
            choice_window = tk.Toplevel(self.board)
            options = ['Antelope', 'Cyber sheep', 'Fox',  'Sheep', 'Tortoise', 'Wolf', 'Grass', 'Guarana','Sosnowsky\'s hogweed', 'Dandelion', 'Belldonna']

            self.option_var.set(options[0])

            for option in options:
                rb = tk.Radiobutton(choice_window, text=option, variable=self.option_var, value=option)
                rb.pack(anchor='w')
            confirm_button = tk.Button(choice_window, text="Submit", command=self.add_body)
            confirm_button.pack()

    def add_body(self):
        if self.option_var.get() == "Antelope":
            self.world.add_body(Antelope(Point(self.y+1, self.x+1),self.world))
        elif self.option_var.get() == "Cyber sheep":
            self.world.add_body(CyberSheep(Point(self.y+1, self.x+1), self.world))
        elif self.option_var.get() == "Fox":
            self.world.add_body(Fox(Point(self.y+1, self.x+1), self.world))
        elif self.option_var.get() == "Sheep":
            self.world.add_body(Sheep(Point(self.y+1, self.x+1), self.world))
        elif self.option_var.get() == "Tortoise":
            self.world.add_body(Tortoise(Point(self.y+1, self.x+1), self.world))
        elif self.option_var.get() == "Wolf":
            self.world.add_body(Wolf(Point(self.y+1, self.x+1), self.world))
        elif self.option_var.get() == "Grass":
            self.world.add_body(Grass(Point(self.y+1, self.x+1), self.world))
        elif self.option_var.get() == "Guarana":
            self.world.add_body(Guarana(Point(self.y+1, self.x+1), self.world))
        elif self.option_var.get() == "Sosnowsky\'s hogweed":
            self.world.add_body(SosnowskysHogweed(Point(self.y+1, self.x+1), self.world))
        elif self.option_var.get() == "Dandelion":
            self.world.add_body(Dandelion(Point(self.y+1, self.x+1), self.world))
        elif self.option_var.get() == "Belldonna":
            self.world.add_body(Belladonna(Point(self.y+1, self.x+1), self.world))


