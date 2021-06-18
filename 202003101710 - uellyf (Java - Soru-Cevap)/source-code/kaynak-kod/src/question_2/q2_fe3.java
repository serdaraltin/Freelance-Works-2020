package question_2;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class q2_fe3 {

	JFrame q2_fe2;
	private JTextField txtValue;
	public float hours;
	public String name = "";

	public q2_fe3() {
		initialize();
	}

	private void initialize() {
		q2_fe2 = new JFrame();
		q2_fe2.setResizable(false);
		q2_fe2.setBounds(100, 100, 331, 140);
		q2_fe2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		q2_fe2.getContentPane().setLayout(null);

		JLabel lblNewLabel = new JLabel("Enter the payment per hour for the employee ");
		lblNewLabel.setBounds(27, 12, 290, 17);
		q2_fe2.getContentPane().add(lblNewLabel);

		txtValue = new JTextField();
		txtValue.setBounds(27, 37, 290, 21);
		q2_fe2.getContentPane().add(txtValue);
		txtValue.setColumns(10);

		JButton btnOk = new JButton("Ok");
		btnOk.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {

				float money = hours * Float.parseFloat(txtValue.getText());
				JOptionPane.showMessageDialog(null, name + " will be paid " + money + " dollars for each week");
			}
		});
		btnOk.setBounds(151, 70, 79, 27);
		q2_fe2.getContentPane().add(btnOk);

		JButton btnCancel = new JButton("Cancel");
		btnCancel.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				q2_fe2.setVisible(false);
			}
		});
		btnCancel.setBounds(238, 70, 79, 27);
		q2_fe2.getContentPane().add(btnCancel);
	}

}
