package question_1;


import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class q1_fe2 {

	JFrame q1_fe2;
	private JTextField txtValue;
	public int start_value = 0;
	
	public q1_fe2() {
		initialize();
	}

	private void initialize() {
		q1_fe2 = new JFrame();
		q1_fe2.setResizable(false);
		q1_fe2.setBounds(100, 100, 308, 140);
		q1_fe2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		q1_fe2.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Please enter the finish time of work hours: ");
		lblNewLabel.setBounds(27, 12, 264, 17);
		q1_fe2.getContentPane().add(lblNewLabel);
		
		txtValue = new JTextField();
		txtValue.setBounds(27, 37, 250, 21);
		q1_fe2.getContentPane().add(txtValue);
		txtValue.setColumns(10);
		
		JButton btnOk = new JButton("Ok");
		btnOk.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				int finish_value = Integer.parseInt(txtValue.getText());
				String request = hesapla(start_value, finish_value);
				
				JOptionPane.showMessageDialog(null, "Employee worked "+request);
			}
		});
		btnOk.setBounds(111, 68, 79, 27);
		q1_fe2.getContentPane().add(btnOk);
		
		JButton btnCancel = new JButton("Cancel");
		btnCancel.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				q1_fe2.setVisible(false);
			}
		});
		btnCancel.setBounds(198, 68, 79, 27);
		q1_fe2.getContentPane().add(btnCancel);
	}
	
	public String hesapla(int v1,int v2)
	{
		int between = Math.abs(v1 - v2);
		int reamining = between % 100;
		between /= 100;
		if (reamining > 40)
			reamining = 30;
		
		return between + " hours and " + reamining + " minutes";
	}
}
