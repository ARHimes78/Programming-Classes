#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#define FILE_IN "pop.txt"

using namespace std;

void programHeader() {
    cout << "Name: Alan Himes" << endl;
    cout << "Title: CityPop" << endl;
    cout << "Objective: To obtain data from a file, add it to a 2D array, then write a file with 3 facts from the data." << endl;
}
    
string writeToArray(string textLine, string header[8], string cities[25], int popStats[150], int i, int j, int m) {
    
    //This is one sloppy function, but it works. The purpose is to take the data from the file pop.txt and assign it to arrays.
    
    ifstream fromFile;
    fromFile.open(FILE_IN);
    char allText[32][112];
    char oneBigNumber[1135]; //these two char arrays are gigantic but will only be used within this function.
    char item1[5], item2[23], item3[21], item4[21], item5[21], item6[21], item7[21], item8[21];
    char numToArray[8];
    int digitsA[60] = {48, 55, 94, 101, 140, 147, 186, 193, 232, 238, 277, 284, 323, 330, 369, 375, 382, 413, 460, 467, 506, 512, 519, 526, 549, 644, 651, 690, 697, 704, 711, 734, 741, 748, 779, 786, 825, 832, 839, 870, 876, 883, 914, 920, 927, 934, 957, 964, 971, 978, 1001, 1008, 1047, 1054, 1061, 1068, 1091, 1098, 1105, 1112};
    int digitsB[5] = {232, 369, 506, 870, 914};
    int loop = 0;
    int d;
    bool digitCheckA;
    bool digitCheckB;
    stringstream table;
    string tada;
    
    /*I was having too much difficulty taking the text from the file for the cities, so I used this method. Some of the
    city names were listed in up to 42 characters across, and some contained characters I couldn't use, like the tilde-A
    in "Sao Paulo".*/
    
    cities[0] = "Tokyo, Japan";
    cities[1] = "Delhi, India";
    cities[2] = "Shanghai, China";
    cities[3] = "Bombay India"; 
    cities[4] = "Beijing China",
    cities[5] = "Dhaka, Bangladesh";
    cities[6] = "Karachi, Pakistan";
    cities[7] = "Cairo, Egypt";
    cities[8] = "Lagos, Nigeria";
    cities[9] = "Mexico City, Mexico";
    cities[10] = "Sao Paulo, Brazil";
    cities[11] = "Kinshasa, The Congo";
    cities[12] = "Osaka, Japan";
    cities[13] = "New York-Newark, USA";
    cities[14] = "Calcutta, India";
    cities[15] = "Guangzhou, China";
    cities[16] = "Chongqing, China";
    cities[17] = "Buenos Aires, Argentina";
    cities[18] = "Manila, Philippines"; 
    cities[19] = "Instanbul, Turkey"; 
    cities[20] = "Bangalore, India"; 
    cities[21] = "Tianjin, China"; 
    cities[22] = "Rio de Janeiro, Brazil"; 
    cities[23] = "Madras, India"; 
    cities[24] = "Jakarta, Indonesia";
    
    for(i=0; i<32; i++) {
        for(j=0; j<112; j++) {
            allText[i][j] = 0; //initializing array with null values
        }
    }
    
    //All the data from pop.txt will be stored onto a 2D array.
    for(i=0; i<32; i++) {
        getline(fromFile, textLine);
        for (j=0; j<textLine.length(); j++) {
            allText[i][j] = textLine[j];
        }
    }
    
    /*The first several lines of the file are not consistent with the table from the web, they contain spaces and tabs
    which make it difficult to use just a couple lines of code to assign them to a string array, so I'm doing it piece
    by piece. This part of the function will construct the 8 "title" elements.*/
    
    for (i=0; i<5; i++) {
        item1[i] = 0;
    }
    
    for (i=0; i<23; i++) {
        
        item2[i] = 0;


    }
    
    for (i=0; i<21; i++) {
        item3[i] = 0;
        item4[i] = 0;
        item5[i] = 0;
        item6[i] = 0;
        item7[i] = 0;
        item8[i] = 0;
    }
    
    //Creating strings of character array elements, then creating a string array of the strings.
    
    for (i=0; i<4; i++) 
        item1[i] = allText[0][i];
    
    string textToHeader1(item1); //The method I'm using to create strings from character arrays.
    
    for (i=5; i<27; i++)
        item2[i-5] = allText[0][i];
    
    string textToHeader2(item2);
    
    for (i=28; i<38; i++)
        item3[i-28] = allText[0][i];
        
    item3[10] = 32;
    
    for (i=0; i<9; i++)
        item3[i+11] = allText[1][i];
        
    string textToHeader3(item3);
    
    for (i=0; i<21; i++) { //create duplicates of "item3"
        item4[i] = item3[i];
        item5[i] = item3[i];
        item6[i] = item3[i];
        item7[i] = item3[i];
        item8[i] = item3[i];
    }
    
    for (i=11; i<15; i++) { //replace only the years of the character strings
        item4[i] = allText[2][i-11]; //this will now say 1975 instead of 1950, and so on
        item5[i] = allText[3][i-11];
        item6[i] = allText[4][i-11];
        item7[i] = allText[5][i-11];
        item8[i] = allText[6][i-11];
    }
    
    string textToHeader4(item4);
    string textToHeader5(item5);
    string textToHeader6(item6);
    string textToHeader7(item7);
    string textToHeader8(item8);
    
    header[0] = textToHeader1;
    header[1] = textToHeader2;
    header[2] = textToHeader3;
    header[3] = textToHeader4;
    header[4] = textToHeader5;
    header[5] = textToHeader6;
    header[6] = textToHeader7;
    header[7] = textToHeader8; //The string array of the title elements has now been created!
    
    //With this next section, all the statistical numbers are piled into an array of all the numbers back to back.
    
    for (i=0; i<1135; i++)
        oneBigNumber[i] = 0;
    
    for (i=7; i<32; i++) {
        for (j=2; j<112; j++) { //Set j to 2 to avoid including the "rank" numbers
            if (allText[i][j] >= 48 && allText[i][j] <= 57) { //any character within the scope of these for loops will be added to the array
                oneBigNumber[m] = allText[i][j];
                m++;
            }
            else
                continue;
        }
    }
    
    //And now, the fun part, splitting the "oneBigNumber" array into individual values for the "popStats" int array.
    
    for (i=0; i<8; i++) {
        numToArray[i] = 0;
    }    
    
    for (i=0; i<150; i++) {
        /*The numbers included in the digitsA and digitsB arrays are be checked against the loop increment number 
        to determine whether a number should be treated like a 7 or 6 digit number.*/
        for (d=0; d<60; d++) {
            digitCheckA = false;
            if (loop == digitsA[d]) {
                digitCheckA = true;
                break;
            }
        }
        
        for (d=0; d<5; d++) {
            digitCheckB = false;
            if (loop == digitsB[d]) {
                digitCheckB = true;
                break;
            }
        }
        
        if (digitCheckA == true) { 
            if (digitCheckB == true) { //6 digit numbers
                for (j=0; j<8; j++) {
                    if (j == 6 || j == 7)
                        numToArray[j] = 48; //resulting in an 8 digit number with two zeros at the end.
                    else
                        numToArray[j] = oneBigNumber[j+loop];
                }
            loop = loop-2; //Decrement the loop counter to calibrate it along with the first digits of the statistical numbers.
            popStats[i] = atoi(numToArray) / 100; //because two zeros were added to the end of the number, dividing by 100 will result in the correct number.
            }
            else { //7 digit numbers
                for (j=0; j<8; j++) {
                    if (j == 7)
                        numToArray[j] = 48;
                    else
                        numToArray[j] = oneBigNumber[j+loop];
                }
            loop--;
            popStats[i] = atoi(numToArray) / 10;
            }
            //I resorted to the method of adding one or two zeros to the end of numbers because for some reason I was having problems using atoi with 7-element character arrays.
        }
        else {
            for (j=0; j<8; j++) { //8 digit numbers
                numToArray[j] = oneBigNumber[j+loop];
            }
        popStats[i] = atoi(numToArray);
        }
        loop = loop + 8; //Most of the numbers are 8 digit numbers
    }
    
    //The array elements are now organized onto a stringstream and returned to a string in main.
    
    table << header[0] << setw(23) << header[1] << setw(21) << header[2] << setw(21) << header[3] << setw(21) << header[4] << setw(21) << header[5] << setw(21) << header[6] << setw(21) << header[7] << endl;
        
    for (i=0, j=0; i<25; i++) {
        table << setw(2) << i + 1 << ". " << setw(23) << cities[i] << setw(21) << popStats[j] << setw(21) << popStats[j + 1] << setw(21) << popStats[j + 2] << setw(21) << popStats[j + 3] << setw(21) << popStats[j + 4] << setw(21) << popStats[j + 5] << endl;
        j=j+6;
    }
    
    tada = table.str();
    return tada;
    
    //The returned table can now be written to a file, and the stored array values can be used anywhere in the program.
}


void analyzeData(int popStats[150], string cities[25], int i, int j, int m, int *total2030, int *diff1975, int *incrCongo) {
    int popData[25][6];
    int pop2030[25], pop1975[25], congo[6];
    int least, most;
    
    m = 0;
    
    for (i=0; i<25; i++) { //creating a 2D array version of popStats to be used only in this function for ease of use
        for (j=0; j<6; j++) {
            popData[i][j] = popStats[m + j];
        }
        m = m + 6;
    }
    
    cout << "\nThree facts based on the data from this table (pop.txt, from http://www.geohive.com/cities/agg2030.aspx):" << endl;


    
    //Creating arrays to determine the 3 data facts
    for (i=0; i<25; i++) {
        pop2030[i] = popData[i][5];
        *total2030 = *total2030 + pop2030[i];
    }
    
    cout << "\nThe combined estimated population of all 25 cities in 2030 is " << *total2030 << "." << endl;
        
    for (i=0; i<25; i++) 
        pop1975[i] = popData[i][1];
    
    least = pop1975[0];
    for (i=1; i<25; i++) {
        if (pop1975[i] < least)
            least = pop1975[i];
    }
    
    most = pop1975[0];
    for (i=1; i<25; i++) {
        if (pop1975[i] > most)
            most = pop1975[i];
    }
    
    *diff1975 = most - least;
    
    cout << "The difference between the estimated most populated and least populated cities in 1975 is " << *diff1975 << "." << endl;
    
    for (i=0; i<6; i++) 
        congo[i] = popData[11][i];
        
    *incrCongo = congo[5] - congo[0];
    
    cout << "Between 1950 and 2030 in " << cities[11] << ", the estimated population increase is " << *incrCongo << "." << endl;
    
    
}


bool writeToFile(string cities[25], string tableDisplay, string *fileName, int &total2030, int &diff1975, int &incrCongo) {
    ofstream toFile;
    stringstream addExt;
    
    cout << "\nWhat would you like to name the file to write the data?" << endl;
    
    getline(cin, *fileName);
    
    addExt << *fileName << ".txt";
    
    *fileName = addExt.str();
    
    toFile.open(*fileName);

	if (!toFile)
        return false;
    

    toFile << tableDisplay;
    toFile << "\nThe combined estimated population of all 25 cities in 2030 is " << total2030 << "." << endl;
    toFile << "The difference between the estimated most populated and least populated cities in 1975 is " << diff1975 << "." << endl;
    toFile << "Between 1950 and 2030 in " << cities[11] << ", the estimated population increase is " << incrCongo << "." << endl;
    
    return true;
}