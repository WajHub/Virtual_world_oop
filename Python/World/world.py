from GUI.Main_window import MainWindow


class World:
    mainWindow = None
    xSize = 20
    ySize = 20

    def __init__(self):
        self.mainWindow = MainWindow()
