/************************************************************************************
 *
 * Write a program that displays a regular polygon and uses two buttons named +1
 * and -1 to increase or decrease the size of the polygon.
 * 
 * 1. Create the RegularPolygonPane class for displaying an n-sided regular
 * polygon. n is a data field in RegularPolygonPane.
 * 2. Write the code to handle the action events from the buttons to change the
 * number of the sides in a RegularPolygonPane object and redisplay it.
 *	
 ************************************************************************************/

package application;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class RegularPolygonPanel extends JFrame implements ActionListener {
	JButton btnMinus = new JButton("-1");	// Created button object to decrease shape size
	JButton btnPlus = new JButton("+1");	// Created button object to increase shape size
	JPanel panel = new JPanel();			// Created Panel object named panel
	PolyPanel poly = new PolyPanel();		// Created PolyPanel object named poly

	
	public RegularPolygonPanel() { 							// Default class constructor named RegularPaloygonPanel
		panel.add(btnPlus);									// Added plus buttons to panel
		panel.add(btnMinus);								// Added minus buttons to panel
		add(poly, BorderLayout.CENTER);						// Positioned pane in center
		add(panel, BorderLayout.SOUTH);						// Positioned panel at bottom
		btnPlus.addActionListener((ActionListener) this);	// Added actions to plus button
		btnMinus.addActionListener(this);					// Added actions to minus button
	}														// ********************Close Method********************

	public void actionPerformed(ActionEvent e) { 	// *****Handler for buttons*****
		if (e.getSource() == btnMinus) {			// Checked source for btnMinus
			poly.decreaseSize();					// Decrease Polygon size 
		} else if (e.getSource() == btnPlus) {		// Checked source for btnPlus
			poly.increaseSize();					// Increased Polygon size
		}											// ********Close Method*********
	}

	public static void main(String[] args) { 			// ***************Main Method***************
		JFrame javaFrame = new RegularPolygonPanel();	// Created a JFrame object named javaFrame
		javaFrame.setTitle("Program 4");				// Set panel title equal to Program 4
		javaFrame.setLocationRelativeTo(null);			// Set javaFram location	  
		javaFrame.setSize(300, 350);					// Set javaFrame size
		javaFrame.setVisible(true);						// Allowed javaFrame visibility
	}													// ***************Close Method**************

	class PolyPanel extends JPanel {	// Created inner panel named PolyPanel
		private int size1 = 0;			// Declared new size variable named size1
		private int size2 = 6;			// Declared new size variable named size2

		public void decreaseSize() {	// method to reduce size2
			size2--;					// reduces size of Polygon
			repaint();					// refreshes shape
		}								// ******close method******
		
		public void increaseSize() {	// method to increase size2
			size2++;					// Increases size of Polygon
			repaint();					// refreshes shape
		}								// ******close method*******

		protected void paintComponent(Graphics g) {						// Overrides paint
			size1 = (int) (Math.min(getWidth(), getHeight()) * 0.4);
			int a = getWidth() / 2;										// Calculate width
			int b = getHeight() / 2;									// Calculates height
			super.paintComponent(g);									// Called super class to refresh shape
			Polygon pol = new Polygon();								// Created new Polygon object named Pol
			pol.addPoint(a + size1, b);									// called addPoint method
			
			for (int i = 1; i < size2; i++) {
				pol.addPoint((int) (a + size1 * Math.cos(i * 2 * Math.PI / size2)),
							 (int) (b - size1 * Math.sin(i * 2 * Math.PI / size2)));
			}
			g.drawPolygon(pol);
		}
	}
}