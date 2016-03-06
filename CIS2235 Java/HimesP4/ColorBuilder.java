//This is the same as ColorBuilder from E2.

import java.awt.Color;

public class ColorBuilder {
	private int red, green, blue;
	private Color initialColor;
	private Color changedColor;
	private Color contrastColor;
	
	public ColorBuilder() {
		this(0, 0, 0);
		red = initialColor.getRed();
		green = initialColor.getGreen();
		blue = initialColor.getBlue();
		/*Just to prove the constructor actually sets the object to black.
		I could have just said "red = 0, etc...".
		This is also checked in getContrastColor() and toString().
		*/
		
	}
	
	public ColorBuilder(int r, int g, int b) {
		initialColor = new Color(r, g, b);
	}
	
	public void setRed(int r){
		red = r;
	}
	
	public void setGreen(int g){
		green = g;
	}
	
	public void setBlue(int b) {
		blue = b;
	}
	
	public void setRGB(int r, int g, int b) {
		red = r;
		green = g;
		blue = b;
	}
	
	public Color getMainColor() {
		changedColor = new Color(red, green, blue);
		/*The only way I could figure out how to "set" the r, g and b from setRGB
		was to create an entirely new Color object and pass the set values into its constructor.*/
		
		return changedColor;
	}
	
	public Color getContrastColor() {
		if (red == 0 && green == 0 && blue == 0)
			contrastColor = new Color(255, 255, 255);
			/*button background will be white the first time the window appears,
			or if black happens to be randomly generated.*/
			
		else {
			/*The algorithm for changing the colors for the button background:
			
			If the red value is between 96 and 160, it's subtracted or added by 128, depending on if it's above or below 128. 
			Otherwise, red is changed to its "opposite" value, making it just as light as it was dark, or vice versa.
			
			Green is changed by either dividing or multiplying its value by 2, depending on if it's above or below 128.
			Blue is the "average" of the changed red and green values.
			
			Even if the button text is grey, a contrasting background color is guaranteed.*/
			
			if (red >= 96 && red <= 160) {
				if (red < 128)
					red = red + 128;
				else
					red = red - 128;
			}
			else
				red = 255 - red;
			
			if (green < 128)
				green = green * 2;
			else
				green = green / 2;
			
			blue = (red + green) / 2;
			
			contrastColor = new Color(red, green, blue);
		}
		
		return contrastColor;
	}
	
	public String toString() {
		if (red == 0 && green == 0 && blue == 0)
			//return initialColor.toString();
			/*The above line would have returned "java.awt.Color[r=0,g=0,b=0]". The Color class
			has a toString() method.*/
			
			return "Button text: red=" + red + ", green=" + green + ", blue=" + blue + "\n"
				+ "Button background text: red=" + 255
				+ ", green=" + 255 
				+ ", blue=" + 255;
			//ints red, green and blue are set to 0 (from the constructor).
		
		else
			//return changedColor.toString();
			return "Button text: red=" + changedColor.getRed() 
				+ ", green=" + changedColor.getGreen() 
				+ ", blue=" + changedColor.getBlue() + "\n"
				+ "Button background text: red=" + red
				+ ", green=" + green 
				+ ", blue=" + blue;
			//ints red, green and blue are the button background colors when this string displays.
		
	}
}