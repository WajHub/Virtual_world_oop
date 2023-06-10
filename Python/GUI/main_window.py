import tkinter as tk

from GUI.Box import Box


# Width: 1000, Height: 800
class MainWindow:
    root = None
    board = None
    legend = None
    menu = None
    news = None
    world = None

    def __init__(self, world):
        self.world = world
        self.root = tk.Tk()
        self.root.title("Virtual World")
        self.root.geometry("1000x800")
        self.root.resizable(False, False)
        self.root.bind("<KeyPress>", self.on_key_press)
        self.root.focus_set()

        self.board = tk.Frame(self.root, width=600, height=600)
        self.board.place(x=10, y=10)
        # Tworzenie planszy 20x20 z przyciskami
        for row in range(20):
            for column in range(20):
                self.world.get_boxes[row][column] = Box(self.world, self.board, row, column)
                self.world.get_boxes[row][column].get_button.grid(row=row, column=column)

        self.legend = tk.Canvas(self.root, width=800, height=150, bg="blue")
        self.legend.place(x=100, y=620)

        self.menu = tk.Frame(self.root, width=350, height=100, bg="green")
        self.menu.pack(anchor="ne", pady=10, padx=10)

        self.news = tk.Frame(self.root, width=350, height=480, bg="yellow")
        self.news.pack(anchor="e", pady=10, padx=10)

    def on_key_press(self, event):
        self.world.set_order(event.keysym)
        if self.world.order_is_correct():
            self.world.make_turn()

    @property
    def get_board(self):
        return self.board

    def start(self):
        self.root.mainloop()

    def get_world(self):
        return self.world

