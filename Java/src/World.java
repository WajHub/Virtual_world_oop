import GUI.BoardPanel;
import GUI.WorldFrame;
import GUI.WorldPanel;
import body.Body;

import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.*;
import java.util.List;

public class World {
    private WorldFrame frame;
    private WorldPanel panel;
    private BoardPanel board_panel;
    private List<Body> bodies;
    private GUI.Box boxes [][];
    private int x_size = 20;
    private int y_size = 20;
    private int turn = 0;

    public World() {
        frame = new WorldFrame();
        panel = new WorldPanel();
        frame.add(panel);
        frame.pack();
        select_size();
    }

    void select_size() {
        boolean selected = false;
        // utwórz komponenty
        JLabel label_x = new JLabel("Select width: " + x_size);
        JLabel label_y = new JLabel("Select height: " + y_size);
        JSlider slider_x = new JSlider(JSlider.HORIZONTAL, 5, 50, 20); // ustawienia suwaka: wartość minimalna, wartość maksymalna, wartość początkowa
        JSlider slider_y = new JSlider(JSlider.HORIZONTAL, 5, 50, 20); // ustawienia suwaka: wartość minimalna, wartość maksymalna, wartość początkowa
        JButton button = new JButton("OK");

        // utwórz okno dialogowe
        JFrame dialog = new JFrame("Select board size");
        dialog.setSize(300, 200);
        dialog.setLayout(new BoxLayout(dialog.getContentPane(), BoxLayout.Y_AXIS));

        // dodaj komponenty do okna dialogowego
        dialog.add(label_x);
        dialog.add(slider_x);
        dialog.add(Box.createVerticalStrut(20)); // odstęp między komponentami
        dialog.add(label_y);
        dialog.add(slider_y);
        dialog.add(Box.createVerticalStrut(20)); // odstęp między komponentami
        dialog.add(button);

        // dodaj słuchacza zdarzeń do suwaka
        slider_x.addChangeListener(new ChangeListener() {
            public void stateChanged(ChangeEvent e) {
                x_size = slider_x.getValue();
                label_x.setText("Select width: " + x_size);
            }
        });
        slider_y.addChangeListener(new ChangeListener() {
            public void stateChanged(ChangeEvent e) {
                y_size = slider_y.getValue();
                label_y.setText("Select height: " + y_size);
            }
        });
        // dodaj słuchacza zdarzeń do przycisku OK
        button.addActionListener(e -> {
            x_size = slider_x.getValue();
            y_size = slider_y.getValue();
            // zrobić coś z wartością, na przykład zamknąć okno dialogowe i rozpocząć grę
            dialog.dispose();
            start_game();
        });
        // pokaż okno dialogowe
        dialog.setVisible(true);
    }

    void start_game() {
        board_panel = new BoardPanel(x_size, y_size);
        panel.add(board_panel);
        boxes = new GUI.Box[x_size][y_size];
        for(int i=0;i<x_size;i++){
            for(int j=0;j<y_size;j++){
                boxes[i][j] = new GUI.Box(i ,j);
                board_panel.add(boxes[i][j]);
            }
        }
        frame.pack();
    }
}
