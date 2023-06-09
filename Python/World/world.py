from GUI.Main_window import MainWindow


class World:
    mainWindow = None
    xSize = 20
    ySize = 20
    bodies = []
    boxes = [[0 for _ in range(20)] for _ in range(20)]

    def __init__(self):
        self.mainWindow = MainWindow(self)

    @property
    def get_main_window(self):
        return self.mainWindow

    @property
    def get_boxes(self):
        return self.boxes
