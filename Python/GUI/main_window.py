import tkinter as tk
from tkinter import scrolledtext

from GUI.Box import Box
from GUI.colors import Colors


# Width: 1000, Height: 800
class MainWindow:
    root = None
    board = None
    legend = None
    menu = None
    news = None
    text_widget = None
    world = None
    text = ""

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

        self.legend = tk.Canvas(self.root, width=800, height=150)
        self.legend.place(x=100, y=650)
        label_empty = tk.Label(self.legend, text="EMPTY", bg=Colors.EMPTY.value, pady=7, padx=7, font=("Arial", 10))
        label_empty.grid(row=0, column=0)

        label_wolf = tk.Label(self.legend, text="WOLF", bg=Colors.WOLF.value, fg="white", pady=7, padx=7,font=("Arial", 10))
        label_wolf.grid(row=0, column=1)

        label_antelope = tk.Label(self.legend, text="ANTELOPE", bg=Colors.ANTELOPE.value, pady=7, padx=7,font=("Arial", 10))
        label_antelope.grid(row=0, column=2)

        label_cybersheep = tk.Label(self.legend, text="CYBERSHEEP", bg=Colors.CYBERSHEEP.value, pady=7, padx=7,font=("Arial", 10))
        label_cybersheep.grid(row=0, column=3)

        label_fox = tk.Label(self.legend, text="FOX", bg=Colors.FOX.value, pady=7, padx=7,font=("Arial", 10))
        label_fox.grid(row=0, column=4)

        label_human = tk.Label(self.legend, text="HUMAN", bg=Colors.HUMAN.value, pady=7, padx=7,font=("Arial", 10))
        label_human.grid(row=1, column=0)

        label_sheep = tk.Label(self.legend, text="SHEEP", bg=Colors.SHEEP.value, pady=7, padx=7,font=("Arial", 10))
        label_sheep.grid(row=1, column=1)

        label_tortoise = tk.Label(self.legend, text="TORTOISE", bg=Colors.TORTOISE.value, pady=7, padx=7,font=("Arial", 10))
        label_tortoise.grid(row=1, column=2)

        label_grass = tk.Label(self.legend, text="GRASS", bg=Colors.GRASS.value, pady=7, padx=7,font=("Arial", 10))
        label_grass.grid(row=1, column=3)

        label_belladonna = tk.Label(self.legend, text="BELLADONNA", bg=Colors.BELLADONNA.value, pady=7, padx=7,font=("Arial", 10))
        label_belladonna.grid(row=1, column=4)

        label_dandelion = tk.Label(self.legend, text="DANDELION", bg=Colors.DANDELION.value, pady=7, padx=7,font=("Arial", 10))
        label_dandelion.grid(row=2, column=0)

        label_guarana = tk.Label(self.legend, text="GUARANA", bg=Colors.GUARANA.value, pady=7, padx=7,font=("Arial", 10))
        label_guarana.grid(row=2, column=1)

        label_hogweed = tk.Label(self.legend, text="SOSNOWSKYSHOGWEED", bg=Colors.SOSNOWSKYSHOGWEED.value, pady=7, padx=7,font=("Arial", 10))
        label_hogweed.grid(row=2, column=2)

        self.legend.grid_columnconfigure(0, weight=1, uniform="equal")
        self.legend.grid_columnconfigure(1, weight=1, uniform="equal")
        self.legend.grid_columnconfigure(2, weight=1, uniform="equal")
        self.legend.grid_columnconfigure(3, weight=1, uniform="equal")
        self.legend.grid_columnconfigure(4, weight=1, uniform="equal")
        self.legend.grid_columnconfigure(5, weight=1, uniform="equal")
        self.legend.grid_columnconfigure(6, weight=1, uniform="equal")


        self.menu = tk.Frame(self.root, width=350, height=100, bg="green")
        self.menu.pack(anchor="ne", pady=10, padx=10)

        self.news = tk.Frame(self.root, width=350, height=480)
        self.news.pack(anchor="e", pady=10, padx=10)
        self.text_widget = scrolledtext.ScrolledText(self.news, width=40, height=30)
        self.text_widget.pack(fill=tk.BOTH, expand=True)
        self.text_widget.insert("end", self.text)

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

    def clear_text(self):
        self.text_widget.delete('1.0', tk.END)

    def add_text(self, adding_text):
        self.text_widget.insert("end", adding_text)
