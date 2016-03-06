import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JSlider;
import java.awt.Color;
import java.awt.Container;
import java.awt.GridLayout;
import javax.swing.event.*;//for ChangeListener

public class SliderFrame extends JFrame {
	private ColorBuilder colBuild;
	private JTextArea colorText;
	private JSlider redSlide, greenSlide, blueSlide;
	private int redValue, greenValue, blueValue;
	
	public SliderFrame() {
		redValue = 0;
		greenValue = 0;
		blueValue = 0;
		
		setSize(800, 400);
		setTitle("Alan Himes, Program 4");
		setLocationRelativeTo(null);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		colBuild = new ColorBuilder();
		colorText = new JTextArea("red=" + redValue + " green=" + greenValue + " blue="  + blueValue);
		
		colorText.setBackground(colBuild.getMainColor());
		colorText.setForeground(colBuild.getContrastColor());
		
		redSlide = new JSlider(0, 255, 0);
		redSlide.setMajorTickSpacing(16);
		redSlide.setMinorTickSpacing(4);
		redSlide.setPaintTicks(true);
		redSlide.setPaintLabels(true);
		
		greenSlide = new JSlider(0, 255, 0);
		greenSlide.setMajorTickSpacing(16);
		greenSlide.setMinorTickSpacing(4);
		greenSlide.setPaintTicks(true);
		greenSlide.setPaintLabels(true);
		
		blueSlide = new JSlider(0, 255, 0);
		blueSlide.setMajorTickSpacing(16);
		blueSlide.setMinorTickSpacing(4);
		blueSlide.setPaintTicks(true);
		blueSlide.setPaintLabels(true);
		
		Container window = getContentPane();
		
		window.setLayout(new GridLayout(4,0));
		window.add(colorText);
		window.add(redSlide);
		window.add(greenSlide);
		window.add(blueSlide);
		
		redSlide.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {
				redValue = redSlide.getValue();
				colBuild.setRed(redValue);
				slideColors();
			}
		});
		
		greenSlide.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {
				greenValue = greenSlide.getValue();
				colBuild.setGreen(greenValue);
				slideColors();
			}
		});
		
		blueSlide.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {
				blueValue = blueSlide.getValue();
				colBuild.setBlue(blueValue);
				slideColors();
			}
		});
		
	}
	
	private void slideColors(){
		colBuild.setRGB(redValue, greenValue, blueValue);
		colorText.setText("red=" + redValue + " green=" + greenValue + " blue="  + blueValue);
		colorText.setBackground(colBuild.getMainColor());
		colorText.setForeground(colBuild.getContrastColor());
	}
}
