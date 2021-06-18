package question_3;

import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.JButton;

import java.awt.event.ActionListener;
import java.util.Scanner;
import java.awt.event.ActionEvent;
import question_1.q1_fe2;

public class q3_main {

	private JFrame q3_fe1;
	private JTextField txtValue;

	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					q3_main window = new q3_main();
					window.q3_fe1.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}


	public q3_main() {
		initialize();
	}

	private void initialize() {
		q3_fe1 = new JFrame();
		q3_fe1.setResizable(false);
		q3_fe1.setBounds(100, 100, 308, 140);
		q3_fe1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		q3_fe1.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Enter the id of the month");
		lblNewLabel.setBounds(27, 12, 209, 17);
		q3_fe1.getContentPane().add(lblNewLabel);
		
		txtValue = new JTextField();
		txtValue.setBounds(27, 37, 250, 21);
		q3_fe1.getContentPane().add(txtValue);
		txtValue.setColumns(10);
		
		JButton btnOk = new JButton("Ok");
		btnOk.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {

				int gunSayisi = hesapla(Integer.parseInt(txtValue.getText()));
				JOptionPane.showMessageDialog(null, "There are "+gunSayisi+" days in this month");
			
			}
			
		});
		btnOk.setBounds(111, 68, 79, 27);
		q3_fe1.getContentPane().add(btnOk);
		
		JButton btnCancel = new JButton("Cancel");
		btnCancel.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				q3_fe1.setVisible(false);
			}
		});
		btnCancel.setBounds(198, 68, 79, 27);
		q3_fe1.getContentPane().add(btnCancel);
	}
	
	private int hesapla(int ay) {
		
		int gunSayi = 0;
		if (ay == 1 || ay == 3 || ay == 5 || ay == 7 || ay == 8 || ay == 10 || ay == 12 )
			gunSayi = 31;
		else if ( ay == 4 || ay == 6 || ay == 9 || ay == 11 )
			gunSayi = 30;
		else if ( ay == 2 )
			gunSayi = 28;
		else
			JOptionPane.showMessageDialog(null, "Please enter Valid Number between 1 to 12");

		return gunSayi;
	}
}
