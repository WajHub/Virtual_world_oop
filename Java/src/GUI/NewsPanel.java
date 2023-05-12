package GUI;

import javax.swing.*;
import java.awt.*;

public class NewsPanel extends JPanel {
    private String content;
    private JTextArea textArea;
    public NewsPanel() {
        content="";
        this.setFocusable(true);
        this.setBackground(Color.white);
        this.setBounds(WorldFrame.FREE_SPACE*3+BoardPanel.width, WorldFrame.FREE_SPACE*2+MenuPanel.height,
                WorldFrame.SCREEN_WIDTH-(WorldFrame.FREE_SPACE*4+BoardPanel.width), BoardPanel.height-MenuPanel.height-WorldFrame.FREE_SPACE);
        textArea = new JTextArea(content);
        textArea.setEditable(false);
        setLayout(new CardLayout());

        textArea.setMargin(new Insets(5, 5, 5, 5));
        JScrollPane scrollPane = new JScrollPane(textArea);
        add(scrollPane);
    }
    public void add_title_name(String news) {
        content += news + "  ";
        textArea.setText(content);
    }
    public void add_news(String news) {
        content += news + "\n";
        textArea.setText(content);
    }
    public void clear(){
        content="";
    }
}
