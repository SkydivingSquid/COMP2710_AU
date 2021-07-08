/* File Name:  project1_martin_gbm0016.cpp
 * Author:     George Martin (gbm0016)
 * Class:      COMP 2710 - Dr. Li
 * Version:    27 May, 2021
 * 
 * Sources:    Dr. Li assisted with using (cin) to check input types through StackOverflow in Piazza.
 *             Dr. Li also advised me to change my doubles to floats. 
 *             Student Zhang advised me to use #include <limits> to fix g++ error. 
 *             The rest of the code was entirely my own with help from Dr. Li's CANVAS files. 
 *
 * Location:   home/u1/gbm0016/Project_1
 * Compile:    g++ project1_martin_gbm0016.cpp -o project1.out
 * Run:        ./project1.out
 */
 
 #include <iostream>
 #include <limits>
using namespace std;
 
/* Program that displays detailed loan repayment information based on 
 * user input of loan amount, interest rate, and desired monthly payment. */
    
int main() {

   ////////////////////////////////////////////////////
   // VARIABLE INITIALIZATION//////////////////////////
   ////////////////////////////////////////////////////
   float loan;
   float interestRate;
   float clientPayment;
   float minPayment;
   float monthlyAPR;
   float totalInterest;
   float interest;
   float principal;
   int currentMonth;
   
   ////////////////////////////////////////////////////
   // CURRENCY FORMATTING//////////////////////////////
   ////////////////////////////////////////////////////
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   ////////////////////////////////////////////////////
   //LOAN SECTION//////////////////////////////////////
   ////////////////////////////////////////////////////
   
   // LOAN INPUT
   cout << "\nLoan Amount: "; 
   cin >> loan;
   
   /* VERIFY LOAN AMOUNT
    * If loan is invalid, user prompted to try again. */
    
   while (!(cin) || loan <= 0) {
      cout << "Invalid Loan Amount. Please Try Again.";
      cout << "\nLoan Amount: ";
      cin.clear(); 
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin >> loan;
   }
   
  //////////////////////////////////////////////////// 
  //INTEREST SECTION//////////////////////////////////
  ////////////////////////////////////////////////////
  
   //INTEREST INPUT
   cout << "Interest Rate (% per year): ";
   cin >> interestRate;
   
   /* VERIFY INTEREST AMOUNT
    * If value is invalid, user prompted to try again. */
    
   while (!(cin) || interestRate < 0) {
      cout << "Invalid Interest Rate. Please Try Again. ";
      cout << "Interest Rate (% per Year): ";
      cin.clear(); 
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin >> interestRate;
   }
   
   // SET PROPER INTEREST RATES FOR CALCULATONS
   monthlyAPR = interestRate / 12 / 100; // Monthly interest in decimal format
   
   //////////////////////////////////////////////////// 
   //PAYMENT SECTION///////////////////////////////////
   //////////////////////////////////////////////////// 
   
   //PAYMENT INPUT
   cout << "Monthly Payments: ";
   cin >> clientPayment;
   
   /* VERIFY PAYMENT AMOUNT
    * If value is invalid, user given minimum allowed value and prompted to try again. */
    
   minPayment = loan * monthlyAPR;
   
   while (!(cin) || clientPayment <= minPayment) {
   
      cout << "Invalid Monthly Payment. ";
      cout << "Monthly Payment Must Be Greater Than: $" << minPayment ; // Informs user of minimum payment amount. Very helpful!
      cout << "\nMonthly Payments: ";
      cin.clear(); 
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin >> clientPayment;
   }
   
   cout << endl;
   
   //////////////////////////////////////////////////// 
   ///AMORTIZATION TABLE///////////////////////////////
   ////////////////////////////////////////////////////

   cout << "*****************************************************************************\n"
        << "\tAmortization Table\n"
        << "*****************************************************************************\n"
        << "Month\tBalance\t\tPayment\t\tRate\tInterest\tPrincipal\n";

   ////////////////////////////////////////////////////      
   //LOOP TO FILL TABLE////////////////////////////////
   ////////////////////////////////////////////////////
   
   while (loan > 0) {
   
   //This section from HINTS on CANVAS//
      if (currentMonth == 0) {
         cout << currentMonth++ << "\t$" << loan;
         if (loan < 1000)
            cout << "\t"; // Formatting MAGIC
      
         cout << "\t" << "N/A\t\tN/A\tN/A\t\tN/A\n";
      }
      
      // This section is my code //
      else {
      
         interest = loan * monthlyAPR;
         principal = clientPayment - interest;
      
         totalInterest += interest;
         loan -= principal;
      
         if (loan < 0) {
            principal += loan;
            clientPayment += loan;
            loan = 0;
         }
          
         cout << currentMonth++ <<"\t$" << loan;
           
         if (loan < 1000) {
            cout <<"\t\t$"  << clientPayment;     
         }     
         
         if (loan >= 1000) {
            cout <<"\t$"  << clientPayment;
         }
                
         cout << "\t\t"    << monthlyAPR * 100
                 << "\t$"   << interest
                 << "\t\t$"  << principal
                 << "\n";
      }   
   }
   

// This Section is from HINTS on CANVAS //      
   cout << "*****************************************************************************\n"; 
   cout << "\nIt takes " << -- currentMonth <<  " months to pay off " 
         << "the loan.\n" 
         << "Total interest paid is: $" << totalInterest;   
   cout << endl << endl; 
      
   return 0;         
          
} // FINAL BRACE