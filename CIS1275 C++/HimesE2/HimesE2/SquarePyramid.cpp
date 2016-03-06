//Alan Himes, ahimes1@cnm.edu, squarepyramid.cpp
#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>


using namespace std;


int main() {
    float length, height, volume, slant, area;

	cout.precision(3);
    cout.setf(ios::showpoint | ios::fixed);
    
    cout << "\nName: Alan Himes" << endl;
    cout << "Email: ahimes1@cnm.edu" << endl;
    cout << "Filename: squarepyramid.cpp" << endl;
    cout << "\nTitle: Square Pyramid" << endl;
    cout << "Objective: To calculate the surface area and volume of a square pyramid." << endl;
    
    //Volume: l^2 * h/3, l = length of base, h = height
    //Area: Find the slant with s = sqrt(h^2 + (l/2)^2), then 4(s*l/2). Base area not included.
    
    cout << "\nEnter the length of the pyramid's base: ";
    cin >> length;
    cout << "\nEnter the height of the pyramid: ";
    cin >> height;
    
    volume = pow(length, 2) * height/3;
    slant = sqrt(pow(height, 2) + pow(length/2, 2));
    area = 4 * (slant * length/2);
    
    cout << "\nHeight: " << height << "' \tBase: " << length << "'" << endl;
    cout << "\tThe Surface Area is " << area << " and the Volume is " << volume << ".\n" << endl;
    return 0;
}