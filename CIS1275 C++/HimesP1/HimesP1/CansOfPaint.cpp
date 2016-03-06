//Alan Himes ahimes1@cnm.edu HimesP1.exe
#include <iostream>
#include <cmath>
using namespace std;


int main() {


    cout << "\nName: Alan Himes\n";
    cout << "Title: Cans of Paint\n";
    cout << "Objective: Compute how much paint is needed\n\n";
    
    cout.setf(ios::showpoint | ios::fixed);
    cout.precision(3);
    
    float roomWidth, roomLength, ceilingHeight, roomArea, totalWindowsDoors, totalPaint, walls, ceiling, paintAmount, tempFloat = 0;
    int windowWidth, windowHeight, windowArea, doorWidth, doorHeight, doorArea, nWindows, nDoors, totalWDInt, cansOfPaint, paintMath, tempInt, tempInt2 = 0;
    windowWidth = 3;
    windowHeight = 4;
    windowArea = windowWidth * windowHeight;
    doorWidth = 3;
    doorHeight = 7;
    doorArea = doorWidth * doorHeight;
    //Created area for window and door areas this way for clarity instead of assigning 12 to the window area and 21 to the door area
    
    cout << "***WELCOME TO THE HOME DEPOT GALLON OF PAINT CALCULATOR!***\n\n";
    cout << "Please enter the room's width: ";
    cin >> roomWidth;
    cout << "Please enter the room's length: ";
    cin >> roomLength;
    cout << "Please enter the room's ceiling height: ";
    cin >> ceilingHeight;
    
    roomArea = 2 * (ceilingHeight * roomWidth) + 2 * (ceilingHeight * roomLength) + roomWidth * roomLength; 
    //Room area = 2 walls as wide as the room's width + 2 walls as wide as the room's length + ceiling area
    
    cout << "\nHow many windows are in the room? ";
    cin >> nWindows;
    cout << "How many doors are in the room? ";
    cin >> nDoors;


    totalWindowsDoors = nWindows * windowArea + nDoors * doorArea;


    ceiling = roomWidth * roomLength;
    walls = roomArea - ceiling;
    cout << "\n***";
    cout << "\n\nTotal square feet of the room's walls: " << walls;
    cout << "\nTotal square feet of the room's ceiling: " << ceiling;
    
    totalWDInt = totalWindowsDoors;
    //Using the float version of this number to subtract from the room area, int version is more presentable without the .000
    cout << "\nTotal square feet subtracted from the room due to windows and doors: " << totalWDInt;
    
    totalPaint = roomArea - totalWindowsDoors;
    //Room's paintable square feet minus the window(s) and door(s).


    paintAmount = totalPaint/350;
    //Assuming one gallon of paint covers 350 square feet
    
    /*Instead of the int variable "cansOfPaint" being rounded DOWN to the nearest number by assigning the
    float "paintAmount" to it, any additional less-than-one-gallon-remaining paint will be accounted for with 
    another can of paint. */
    paintMath = paintAmount + 1; //i.e. 2.67 gallons + 1 = 3.67
    tempInt = paintMath; //3.67 becomes 3
    tempFloat = tempInt - paintAmount; //Subtract 2.67 from 3 to get .33.
    tempInt2 = tempFloat; //Assign .33 to an integer variable and it becomes 0. If "paintAmount" was a whole number, this would be 1.
    cansOfPaint = tempInt - tempInt2; //Subtracts 0 in this case, leaving an extra can for the "decimal point amount".


    cout << "\n\nExactly " << paintAmount << " gallons of paint is needed to cover this room. ";
    cout << cansOfPaint << " can(s) of paint would be required.\n\n";
    cout << "Width: " << roomWidth << " square feet\n";
    cout << "Length: " << roomLength << " square feet\n";
    cout << "Height: " << ceilingHeight << " square feet\n";
    cout << "\nTotal area (walls and ceiling): " << roomArea << " square feet\n";
    cout << "Total paintable area: " << totalPaint << " square feet\n\n";
    cout << "Thank you for visiting Home Depot. Have a nice day!\n\n";
    return 0;
}