// library where the types ifstream & ofstream are defined
#include<fstream> 
// needed to use the exit statement 
#include<cstdlib>
// needed to use cout & cin
#include<iostream>
using namespace std; 

void mergeAndSort(ifstream& inputFile1, ifstream& inputFile2, ofstream& outputFile);


// main function
int main() {
    // variable declarations
    // inStream is an input stream for a file. 
    ifstream inStream;
    ifstream inStream2;
    // output stream for another file.
    ofstream outStream;

    string inputFile1;
    string inputFile2;                                                                              
    string outputFile;

    // prompts the user to enter the names of the two input files and one output file.
    cout << "Enter the name of the first input file." << endl; 
    cin >> inputFile1;

    cout << "Enter the name of the second input file." << endl;
    cin >> inputFile2; 

    cout << "Enter the name of the output file." << endl;
    cin >> outputFile; 

    // connects the variables inStream & outStream to a file.
    // open the file with a function called open. 

    inStream.open(inputFile1);
    if(inStream.fail()) {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    inStream2.open(inputFile2);
    if(inStream2.fail()) {
        cout << "Input file opening failed.\n";
        exit(1);

    }

    // program can now take input from a file using the extraction operator

    // need to open the output stream(connected to a file)
    outStream.open(outputFile);
    // check to see if the output file is opended
    if(outStream.fail()) {
        cout << "Output file opening failed.\n";
        exit(1);
    }


    // call the merge function
    mergeAndSort(inStream, inStream2, outStream);
    // closing the streams using the function close:
    // closing the file disconnects the stream from the file.
    inStream.close();
    inStream2.close();
    outStream.close();
    
    return 0; 
}

void mergeAndSort(ifstream& inputFile1, ifstream& inputFile2, ofstream& outputFile) {
    int num1;
    int num2;
    

    // read the numbers from the files
    inputFile1 >> num1;
    inputFile2 >> num2;


    // read numbers from both files and compare to see which number is smaller, then send the smaller number to the output file.
    while (inputFile1 && inputFile2) {
        if (num1 <= num2) {
            outputFile << num1 << " ";
            inputFile1 >> num1;
        }
        else {
            outputFile << num2 << " ";
            inputFile2 >> num2;
        }
    }

        // write the remaining numbers in input file1 to the output file if there are any.
        while (inputFile1) {
            outputFile << num1 << " ";
            inputFile1 >> num1;
        }

        // write the remaining numbers in input file2 to the output file if there are any. 
        while (inputFile2) {
            outputFile << num2 << " ";
            inputFile2 >> num2;
        }
    }


