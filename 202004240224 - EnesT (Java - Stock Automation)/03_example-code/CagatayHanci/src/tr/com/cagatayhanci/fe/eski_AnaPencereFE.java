package tr.com.cagatayhanci.fe;

import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;

import tr.com.cagatayhanci.interfaces.FeInterfaces;
import tr.com.cagatayhanci.utilities.MenulerCom;

public class eski_AnaPencereFE extends JFrame implements FeInterfaces {

	public eski_AnaPencereFE() {
		// TODO Auto-generated constructor stub
		initPencere();
	}
	
	@Override
	public void initPencere() {
		
		JTabbedPane tabs = initTabs();
		JMenuBar bar = initBar();
		
		//add(tabs);
		setJMenuBar(bar);
		
		setTitle("Cagatay Hanci");
		pack();
		setVisible(true);
		setSize(500, 500);
		setLocationRelativeTo(null);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		
		// TODO Auto-generated method stub
		
	}

	@Override
	public JPanel initPanel() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public JMenuBar initBar() {
		JMenuBar bar = MenulerCom.initBar();
		return bar;
	}

	@Override
	public JTabbedPane initTabs() {
		// TODO Auto-generated method stub
		return null;
	}

}
