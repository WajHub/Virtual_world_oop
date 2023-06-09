import tkinter as tk
from GUI.Colors import Colors


class Box:
    world = None
    board = None
    x = None
    y = None
    color = Colors.EMPTY.value
    button = None

    def __init__(self, world, board, x, y):
        self.world = world
        self.board = board
        self.x = x
        self.y = y
        self.pixelVirtual = tk.PhotoImage(width=1, height=1)
        self.button = tk.Button(board, image=self.pixelVirtual, width=23, height=23, command=self.handle_click)
        self.button.config(bg=self.color)

    @property
    def get_button(self):
        return self.button

    def handle_click(self):
        # Tutaj możesz umieścić kod obsługujący kliknięcie przycisku
        print(f"Kliknięto przycisk na pozycji ({self.x}, {self.y})")
