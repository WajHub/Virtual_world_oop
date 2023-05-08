import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GamePanel  extends JPanel implements ActionListener {
    GamePanel() {
        this.setFocusable(true);
        this.setBackground(Color.gray);
        this.setPreferredSize(new Dimension(GameFrame.SCREEN_WIDTH, GameFrame.SCREEN_HEIGHT));
    }

    @Override
    public void actionPerformed(ActionEvent e) {

    }
}
