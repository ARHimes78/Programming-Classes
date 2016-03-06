#include <iostream>
using namespace std;


int main() {
    cout << "\nName: Alan Himes\n";
    cout << "Email: ahimes1@cnm.edu\n";
    cout << "Program title: Exercise 1, Chapter 2\n\n";
    cout << "1. What is the job of the compiler? What does the linker do? Describe the differences between a compile error and a link error.\n";
    cout << "  A compiler checks that C++ statements are written with the correct syntax, and produces machine code. A linker combines all the required files together and builds an executable file. Compiler errors are caused by incorrect syntax. Link errors can be caused by failure to specify a required library or associated file.\n";
    cout << "4. Why does a C++ program need to have a main function?\n";
    cout << "  C++ needs to make sure it has a function specifically named \"main\" which contains programming statements and/or other functions.\n";
    cout << "5. What is the difference between a data type and a variable?\n";
    cout << "  A data type is the type of data a variable is declared to be: float, int, char, etc.. A variable contains an assigned value.\n";
    cout << "6. What is meant by a precedence of operations?\n";
    cout << "  The order in which operators are executed. For example: operators within parenthesis, then division/multiplication/modulus, then addition/subtraction.\n";
    cout << "7. What is the purpose of a #include statement?\n";
    cout << "  #include specifies a header file needed to use the functions within it for the program.\n";
    cout << "15. Why is it necessary to place \"using namespace std;\" in your program? Where should it be placed?\n";
    cout << "  The \"using namespace std\" avoids problems with program components having the same name. It is written after preprocessor directives (#include, #define).\n";
    cout << "17. If you divide an integer by an integer and place the result into a double, is the decimal portion of the division maintained? Explain your answer.\n";
    cout << "  The answer would not include the decimal portion. One or both variables needs to be a float or double for the decimal numbers to be included in the answer.\n";
    cout << "24. Look up the functions in the C++ string class, and list three of them. Describe their purpose.\n";
    cout << "  replace(start, size, string) Replaces part of a string with amount of other string. find(string, start) Returns position a word can be found in a string. string.size() Returns the length of a string.\n\n";
    return 0;
}