import tkinter as tk


# Width: 1000, Height: 800
class MainWindow:
    root = None
    board = None
    legend = None
    menu = None
    news = None

    def __init__(self):
        self.root = tk.Tk()
        self.root.title("Virtual World")
        self.root.geometry("1000x800")
        self.root.resizable(False, False)

        self.board = tk.Frame(self.root, width=600, height=600, bg="red")
        self.board.place(anchor="nw")

        self.legend = tk.Canvas(self.root, width=800, height=150, bg="blue")
        self.legend.place(x=100,y=620)

        self.menu = tk.Frame(self.root, width=350, height=100, bg="green")
        self.menu.pack(anchor="ne")

        self.news = tk.Frame(self.root, width=350, height=500, bg="yellow")
        self.news.pack(anchor="e")

        self.root.mainloop()
