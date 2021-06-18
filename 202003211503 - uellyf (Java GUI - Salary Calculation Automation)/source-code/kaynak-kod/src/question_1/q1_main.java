package question_1;

import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import question_1.q1_fe2;

public class q1_main {

	private JFrame q1_fe1;
	private JTextField txtValue;

	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					q1_main window = new q1_main();
					window.q1_fe1.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}


	public q1_main() {
		initialize();
	}

	private void initialize() {
		q1_fe1 = new JFrame();
		q1_fe1.setResizable(false);
		q1_fe1.setBounds(100, 100, 308, 140);
		q1_fe1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		q1_fe1.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Please enter the start time of work hours: ");
		lblNewLabel.setBounds(27, 12, 264, 17);
		q1_fe1.getContentPane().add(lblNewLabel);
		
		txtValue = new JTextField();
		txtValue.setBounds(27, 37, 250, 21);
		q1_fe1.getContentPane().add(txtValue);
		txtValue.setColumns(10);
		
		JButton btnOk = new JButton("Ok");
		btnOk.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {

				q1_fe2 window = new q1_fe2();
				window.start_value = Integer.parseInt(txtValue.getText());
				window.q1_fe2.setVisible(true);
				q1_fe1.setVisible(false);
			
			}
			
		});
		btnOk.setBounds(111, 68, 79, 27);
		q1_fe1.getContentPane().add(btnOk);
		
		JButton btnCancel = new JButton("Cancel");
		btnCancel.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				q1_fe1.setVisible(false);
			}
		});
		btnCancel.setBounds(198, 68, 79, 27);
		q1_fe1.getContentPane().add(btnCancel);
	}
}
