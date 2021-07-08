/* File Name:  project3_xxxxx_xxxxxxx.cpp
 * Author:     <NAME> (xxxxxx)
 * Class:      COMP 2710
 * Version:    <DATE>
 * 
 * Sources:    *********************
 *             *********************
 *             *********************
 *
 * Location:   home/xx/xxxxxx/Project_3
 * Compile:    g++ project3_xxxxx_xxxxxxx.cpp -o project3.out
 * Run:        ./project3.out
 */
 
   ////////////////////////////////////////////////////
   /////////////////////LIBRARIES//////////////////////
   ////////////////////////////////////////////////////
   
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

   ////////////////////////////////////////////////////
   /////////////////////CONSTANTS//////////////////////
   ////////////////////////////////////////////////////

const int MAX_SIZE = 100;

   ////////////////////////////////////////////////////
   /////////////////METHOD PROTOTYPES//////////////////
   ////////////////////////////////////////////////////

int readfile(int inputArray[], ifstream& inStream);

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], 
		   int inputArray2_size, int outputArray[]);
		 
void writefile(int outputArray[], int outputArray_size, string file);

   ////////////////////////////////////////////////////
   //////////////////////MAIN//////////////////////////
   ////////////////////////////////////////////////////
     
int main() {

  //Variables
   ifstream inStream1;
   string filename;
   int iArray1[MAX_SIZE];
   int iArray1_size;
   int iArray2[MAX_SIZE];
   int iArray2_size;
   int outputArray[MAX_SIZE];
   int outputArray_size;
	
	//Request first file from client
   cout << "*** Welcome to <NAME>'s sorting program ***\n";
   
         ////////////////////////////////////////////////////////////////
      	//Request first file name from client and attempt to read file//
         ////////////////////////////////////////////////////////////////
   do {
      do {
         cout << "Enter the first input file name: ";
      
      //Receive first file name from client
         cin >> filename;
      
      //Opens file using the characters entered by client
         inStream1.open((char*)filename.c_str());
      
      //Size of File 1
         iArray1_size = readfile(iArray1, inStream1);
      
      //Closes file.. because not doing this is bad. 
         inStream1.close();
      
      //Prints number of elements and each element in file or informs client file was not found.
         
         if (iArray1_size > MAX_SIZE) {
            cout << "\nFile size too large.\n" 
                 << "Please choose a smaller file.\n\n";
         }
         
         if (iArray1_size >= 0 && iArray1_size <= MAX_SIZE) {
            
            cout << "The list of " << iArray1_size << " numbers in file " << filename << " is:\n";
            for (int i = 0; i < iArray1_size; i++) {
               cout << iArray1[i] << endl;
            }
            cout << endl;
            break;
         }
      
      // Allows client to try again
      } while (inStream1.fail() || (iArray1_size > MAX_SIZE));
   
         /////////////////////////////////////////////////////////////////
      	//Request second file name from client and attempt to read file//
         /////////////////////////////////////////////////////////////////
   
      do {
      //Request second file from client
         cout << "Enter the second input file name: ";
      
      //Receive second file name from client
         cin >> filename;
      
      //Opens file using the characters entered by client
         inStream1.open((char*)filename.c_str());
      
      //Size of File 2
         iArray2_size = readfile(iArray2, inStream1);
      
      //Close the file
         inStream1.close();
      
      //Prints number of elements and each element in file or informs client file was not found.
         
         if (iArray2_size > MAX_SIZE) {
            cout << "\nFile size too large.\n" 
                 << "Please choose a smaller file.\n\n";
         }
         
         else if (iArray2_size >= 0 && iArray2_size <= MAX_SIZE) {
            cout << "The list of " << iArray2_size << " numbers in file " << filename << " is:\n";
            for (int i = 0; i < iArray2_size; i++) {
               cout << iArray2[i] << endl;
            }
            cout << endl;
            break;
         }
      
      // If file is invalid, repeat loop so user can retry.
      } while (inStream1.fail() || (iArray2_size > MAX_SIZE));
   
         /////////////////////////////
      	//Generating An Output File//
         /////////////////////////////
   
   //Required size for Output File based on File 1 and File 2
      outputArray_size = sort(iArray1, iArray1_size, iArray2, iArray2_size, outputArray);
   
   //Print number of elements and elements in new combined file using decending sort function
      if (!(outputArray_size > MAX_SIZE)) {
         cout << "The sorted list of " << outputArray_size << " numbers is: ";
         for (int i = 0; i < outputArray_size; i++) {
            cout << outputArray[i] << " ";
         }
         cout << endl;
         break;
      }
      
      else {
         cout << "Combined File Size Exceeds Limit.\n"
              << "Please choose different files.\n\n";
      }
      //If combined file size exceeds limit, ask client to enter different files.
   } while(true);

	//Request Client provide a desired output file name
   string file;
   cout << "Enter the output file name: ";
   
   //Client enters file name
   cin >> file;
   
   //Write new file in directory with desired output name
   writefile(outputArray, outputArray_size, file);
   
   //Inform Client to check directory for output file
   cout << "*** Please check the new file - " << file << " ***\n";
   cout << "*** Goodbye. ***\n";
	
}	

   ////////////////////////////////////////////////////
   //////////////////////METHODS///////////////////////
   ////////////////////////////////////////////////////
   
//Method for opening target file
int readfile(int inputArray[], ifstream& inStream) {
   int index = 0;
   
   if (!inStream.fail()) {
      inStream >> inputArray[index];
      while (!inStream.eof()) {
      
         index++;
         inStream >> inputArray[index];
      }
      return index;
   }
   
   //If invalid file is entered, prompt and terminate.
   else {
      cout <<"\nFile failed to open."
           <<"\nPlease verify file name and try again.\n\n";
      return -1;
   }
   
   return index;
}

//Method for sorting in decending order
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], 
		 int inputArray2_size, int outputArray[]) {
       
   //Gate for when sorting is complete
   bool complete = false;
   
   //Variables to track array indexes
   int a1 = 0; 
   int a2 = 0; 
   
   //Variable for output file size
   int outputSize = 0;
   
   //Continue sorting using comparision until boolean gate [T]
   while (!complete) {
   
   	//Verify there are more elements to add
      if (a1 < inputArray1_size && a2 < inputArray2_size) {
      
         //////////////////////////////////////////////////////////
      	//Compare Array 1 element value to Array 2 element value//
         //////////////////////////////////////////////////////////
         if (inputArray1[a1] <= inputArray2[a2]) {
         
            outputArray[outputSize] = inputArray1[a1];
            
            //Increment array 1 index
            a1++;
         }
         
         //////////////////////////////////////////////////////////
         //Compare Array 2 element value to Array 1 element value//
         //////////////////////////////////////////////////////////
         else if (inputArray1[a1] >= inputArray2[a2]) {
         
            outputArray[outputSize] = inputArray2[a2];
            
            //Increments array 2 index 
            a2++;
         }
      }
      
      //Array 1 has elements remaining & Array 2 empty
      else if (a1 < inputArray1_size) {
      
         outputArray[outputSize] = inputArray1[a1];
         
         //Increments array 1 after element has been added
         a1++;
      }
      
      //Array 2 has elements remaining & Array 1 empty
      else if (a2 < inputArray2_size) {
      
         outputArray[outputSize] = inputArray2[a2];
         
         //Increments array 2 after element has been added
         a2++;
      }
      
      //Array 1 and Array 2 are empty
      else {
      //Set boolean gate to true
         complete = true;
         return outputSize;
      }
      
      //Return statement
      outputSize++;
   }
   
	//Impossible return value
   return -1;
}

//Method for writing output file to directory
void writefile(int outputArray[], int outputArray_size, string file) {
   ofstream outStream;
   
	//Create new (or overwrite) output file and open it
   outStream.open((char*)file.c_str());
   
   //Verify file was created and opened
   if(!outStream.fail()) {
      for (int i = 0; i < outputArray_size; i++) {
         outStream << outputArray[i] << endl;
      }
   }
   
   //If file failed to create or open, print statement
   else { 
      cout << "Could not write to file";
   }      
   
   //Close output file
   outStream.close();
   
   /*
    * NOTE: This version does not handle "dulpicates" per the .pdf expected output.
    *       It also is a more user friendly version than other online versions as it
    *       allows the client many opportunities to re-enter the file, even at the end.
    */
}