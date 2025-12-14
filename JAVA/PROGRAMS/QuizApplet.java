/* Simple Quiz Applet (AWT) */

import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

public class QuizApplet extends Applet implements ActionListener {
    Label question;
    Button[] optionButtons;
    Button submit;
    int selected = -1;
    String[] options = {"Mercury", "Venus", "Earth", "Mars"};
    int correctIndex = 2;

    public void init() {
        setLayout(new FlowLayout());
        question = new Label("Which planet is known as the Blue Planet?");
        add(question);

        optionButtons = new Button[options.length];
        for (int i = 0; i < options.length; i++) {
            optionButtons[i] = new Button(options[i]);
            optionButtons[i].setActionCommand(String.valueOf(i));
            optionButtons[i].addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    selected = Integer.parseInt(e.getActionCommand());
                }
            });
            add(optionButtons[i]);
        }

        submit = new Button("Submit");
        submit.addActionListener(this);
        add(submit);
    }

    public void actionPerformed(ActionEvent e) {
        if (selected == -1) {
            showStatus("Please select an option before submitting.");
            return;
        }
        if (selected == correctIndex) {
            showStatus("Correct! Well done.");
        } else {
            showStatus("Incorrect. Try again.");
        }
    }
}
