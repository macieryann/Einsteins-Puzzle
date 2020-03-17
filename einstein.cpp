//---------------------------------------------------------
// file: einstein.cpp
//   by: Macie Ryan
//  org: COP 2001; spring 2020
//  for: manipulating int's and strings; reversing strings
//       and converting back to int's for simple math; also
//       practicing various loops and conditional statements
//---------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {			//start program
	int original;
	char yesNo = true;

	while(true) {
		cout << "Enter a number between 100 and 999: " << endl;
		cin >> original;
		
		// change original from INT TO STRING
		string orgNum = to_string(original);
		
		// check if first digit and third digit are not the same
        	if(orgNum[0] != orgNum[2]){
        
			// check if input number is between 100 and 999
			if (original < 1000 && original > 99) {

				// first reverse
				string temp = "";
				for(int i = orgNum.length() - 1; i >= 0; i--){
				    temp = temp.append(1, orgNum[i]);
				}
				cout << temp << endl;

				// change temp back to an INT for subtraction
				int myInt = stoi(temp);

				// difference of original and reverse
				int difference = 0;
				if (original > myInt) {
					difference = original - myInt;
				} else {
					difference = myInt - original;
				}
				cout << difference << endl;

				// reverse the difference
				temp = "";
				string revDiff = to_string(difference); // turn difference into a string for the for loop

				for(int j = orgNum.length() - 1; j >= 0; j--){
					    temp = temp.append(1, revDiff[j]);
				}

				cout << temp << endl;

				// back to integers
				int finalInt = stoi(temp);

				// sum of difference and rev difference
				int finalAnswer;
				finalAnswer = finalInt + difference;
				cout << finalAnswer << endl;

			} else {
				cout << "Number must be three digits.  Try again: " << endl;
				cin >> original;
			}
    		
    		// ask user if they'd like to continue
    		cout << "Would you like to try another number (Y/N): ";
    		cin >> yesNo;
    		if (yesNo == 'N' || yesNo == 'n'){
    		    return false;
    		}
        }

}
	return 0;
}
