//Alan Himes
//ahimes1@cnm.edu
//Program 7 - Polygons
//CIS2235
//File: MainP7.java, ControlPanel.java, DrawPanel.java, InfoPanel.java, PolygonCalc.java, PolygonFrame.java

package Program7;

import java.text.DecimalFormat;

/**
 *
 * @author ahimes1
 */
public class PolygonCalc {
    private int sides, radius;
    private double sideLength;
    
    
    public PolygonCalc() {
        this(3, 1);
    }
    
    public PolygonCalc(int s, int r) {
        
        setNumberSides(s);
        setRadius(r);
        
    }
    
    public void setNumberSides(int s) {
        sides = s;
        
        sideLength = calculateSideLength();
    }
    
    public void setRadius(int r) {
        radius = r;
        
        sideLength = calculateSideLength();
    }
    
    public double getPerimeter() {
        //sideLength was assigned a value using the calculateSideLength method.
        
        return sideLength * sides;//sum of length of each side.
    }
    
    public double getPolygonArea() {
        
        /*
        using http://www.mathopenref.com/apothem.html
        
        apothem = radius * cosine of 180/sides. 
        Math.tan() needs radians instead of degrees.
        */
        
        double apothem = radius * Math.cos(Math.toRadians(180/sides));
        
        return (apothem * getPerimeter())/2;//area = 1/2 of apothem times perimeter
    }
    
    public double getCircumference() {
        
        return Math.PI * (2 * radius);//pi times diameter
        
    }
    public double getCircleArea() {
        
        return Math.PI * Math.pow(radius, 2);//pi times radius squared
    }

    private double calculateSideLength() {
       /*Calculating the length of one of the sides of the 
        polygon using only radius and number of sides. 
        Splitting the polygon into triangles, one of the angles
        is the central angle.
        */
        double centralAngle = 360 / sides;
        /*
        One of these inner triangles is split in half by the apothem.
        The split triangle will consist of the hypoteneuse which is the
        radius, the adjacent which is the apothem, and the opposite which is
        half of one of the sides of the polygon.
        
        Need to find the length of the side (opposite the centralAngle) to
        get the perimeter, and the apothem to get the area.
        Will first find the length of the opposite, then multiply by 2.
        Math.sin() needs radians instead of degrees.
        
        used this Youtube video:
        https://www.youtube.com/watch?v=BJey7mjMoLo starting from 6:24.
        */
        
        //double opposite = radius * Math.sin(Math.toRadians(centralAngle/2));
        //System.out.println("Hey! " + centralAngle/2);
        double opposite = (Math.sin(Math.toRadians(centralAngle/2)) * radius);
        return opposite * 2;
    }
}