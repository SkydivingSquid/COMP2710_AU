/* File Name:  project2_martin_gbm0016.cpp
 * Author:     George Martin (gbm0016)
 * Class:      COMP 2710 - Dr. Li
 * Version:    11 June, 2021
 * 
 * Sources:    This code was entirely my own with help from Dr. Li's CANVAS files.
 *             Discussion with student Eiford if hitting <Enter> twice is acceptable.
 *             Discussion with student Zhang if showpoint was necessary. 
 *
 * Location:   home/u1/gbm0016/Project_2
 * Compile:    g++ project2_martin_gbm0016.cpp -o project2.out
 * Run:        ./project2.out
 */
 
   ////////////////////////////////////////////////////
   /////////////////////LIBRARIES//////////////////////
   ////////////////////////////////////////////////////
   
 #include <assert.h>
 #include <ctime>
 #include <iostream>
 #include <stdlib.h>
 
using namespace std;
 
   ////////////////////////////////////////////////////
   ///////////PROTOTYPES FROM HINT FILE////////////////
   ////////////////////////////////////////////////////
 
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
 
void Aaron_shoots1(bool& B_alive, bool& C_alive);

void Bob_shoots(bool& A_alive, bool& C_alive);

void Charlie_shoots(bool& A_alive, bool& B_alive);

void Aaron_shoots2(bool& B_alive, bool& C_alive);

void a_fires(void);

void a_feigns(void);

void Press_any_key(void);

   ////////////////////////////////////////////////////
   /////////////TEST FOR PROTOTYPES ABOVE//////////////
   ////////////////////////////////////////////////////
   
void test_at_least_two_alive(void);

void test_Aaron_shoots1(void);

void test_Bob_shoots(void);

void test_Charlie_shoots(void);

void test_Aaron_shoots2(void);

   ////////////////////////////////////////////////////
   ////////////////CONSTANT VARIABLES//////////////////
   ////////////////////////////////////////////////////
   
const int TOTAL_ROUNDS = 10000; // 10,000 rounds   
const int A_ACCURACY = 33; // Aaron's accuracy
const int B_ACCURACY = 50; // Bob's accuracy

// NOTE: DO NOT MODIFY C_ACCURACY!
// Modification will yeild invalid results.
const int C_ACCURACY = 100; // Charlie's accuracy

   ////////////////////////////////////////////////////
   /////////////////////VARIABLES//////////////////////
   ////////////////////////////////////////////////////
   
int Aaron_survives; // rounds where Aaron is the victor
int Bob_survives; // rounds where Bob is the victor
int Charlie_survives; // rounds where Charlie is the victor
   
   ////////////////////////////////////////////////////
   ////////////////////////MAIN////////////////////////
   ////////////////////////////////////////////////////
   
int main() {
   
   // Allow for random assignment based on current clock time
   srand(time(0));
         
   cout<<"*** Welcome to George's Duel Simulator ***\n";
   
   test_at_least_two_alive();
   
   Press_any_key();
   
   test_Aaron_shoots1();
   
   Press_any_key();
   
   test_Bob_shoots();
   
   Press_any_key();
   
   test_Charlie_shoots();
   
   Press_any_key();
   
   test_Aaron_shoots2();
   
   Press_any_key();
   
      ////////////////////////////////////////////////////
      //////////STRAT 1 - AARON FIRES FIRST SHOT//////////
      ////////////////////////////////////////////////////
      
   cout <<"Ready to test strategy 1 (run 10000 times):\n";
   Press_any_key();
   
   int round = 0;
   
   // 10,000 rounds of "a_fires" strategy
   while (round < TOTAL_ROUNDS) { 
      a_fires();
      round++;
   }
   
   // Functions for string simplicity output (using Hint file)
   double a_outcome = static_cast<double>(Aaron_survives) / TOTAL_ROUNDS;
   double b_outcome = static_cast<double>(Bob_survives) / TOTAL_ROUNDS;
   double c_outcome = static_cast<double>(Charlie_survives) / TOTAL_ROUNDS;
  
   int a_fires_outcome = Aaron_survives; 
  
  // Aaron data string
   cout << "Aaron won " << Aaron_survives << "/" << TOTAL_ROUNDS 
       << " duels or "  << a_outcome * 100 << "%\n";
       
 // Bob data string
   cout << "Bob won " << Bob_survives << "/" << TOTAL_ROUNDS 
       << " duels or " << b_outcome * 100 << "%\n";
        
 // Charlie data string
   cout << "Charlie won " << Charlie_survives << "/" << TOTAL_ROUNDS 
       << " duels or " << c_outcome * 100 << "%\n";      
       
      ////////////////////////////////////////////////////
      ///////////////////COUNTER RESET////////////////////
      ////////////////////////////////////////////////////   
        
   Aaron_survives = 0;
   Bob_survives = 0;      
   Charlie_survives = 0; 
   round = 0;  
 
      ////////////////////////////////////////////////////
      /////////STRAT 2 - AARON FEIGNS FIRST SHOT//////////
      ////////////////////////////////////////////////////
      
   cout<<"\nReady to test strategy 2 (run 10000 times):\n";
   
   Press_any_key();
   
   // 10,000 rounds of Strat2 simulation
   while (round < TOTAL_ROUNDS) { 
      a_feigns();
      round++;
   }
   
   // Functions for string simplicity output (using my method)
   a_outcome = (double) Aaron_survives / TOTAL_ROUNDS;
   b_outcome = (double) Bob_survives / TOTAL_ROUNDS;
   c_outcome = (double) Charlie_survives / TOTAL_ROUNDS;
  
  // Aaron data string
   cout << "Aaron won " << Aaron_survives << "/" << TOTAL_ROUNDS 
       << " duels or " << a_outcome * 100 << "%\n";
       
 // Bob data string
   cout << "Bob won " << Bob_survives << "/" << TOTAL_ROUNDS 
       << " duels or " << b_outcome * 100 << "%\n";
        
 // Charlie data string
   cout << "Charlie won " << Charlie_survives << "/" << TOTAL_ROUNDS 
       << " duels or " << c_outcome * 100 << "%\n";
 
      ////////////////////////////////////////////////////
      ////////////////STRATEGY COMPARISON/////////////////
      ////////////////////////////////////////////////////
      
   if (a_fires_outcome > Aaron_survives) {
      cout << "\nStrategy 1 is better than strategy 2\n";
   }
         
   if  (a_fires_outcome < Aaron_survives) {
      cout << "\nStrategy 2 is better than stragegy 1\n";
   }
       
   if (a_fires_outcome == Aaron_survives) {
      cout << "\nThe strategies have the same outcomes\n";
   }
   
} // Final Main Brace
        
      ////////////////////////////////////////////////////
      //////////////FUNCTION IMPLEMENTATION///////////////
      ////////////////////////////////////////////////////
        
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {

   // Instantiate variable to get around jGRASP Warning
   bool boolean = false;

   // Combined if statement based on digital logic statements
   if (A_alive && (B_alive || C_alive) || (B_alive && C_alive)) {
      boolean = true;
   }

   return boolean;
} // Close Method Brace

         ////////////////////////////////////////////////////   
 
void Aaron_shoots1(bool& B_alive, bool& C_alive){
   int determinant = rand()%100;
   
   if (determinant <= A_ACCURACY) {
      
      if (C_alive) {
         C_alive = false;
      }
         
      else {
         B_alive = false;
      }
   }    
} // Close Method Brace

         ////////////////////////////////////////////////////

void Bob_shoots(bool& A_alive, bool& C_alive) {
   int determinant = rand()%100;

   if (determinant <= B_ACCURACY) {
   
      if (C_alive) {
         C_alive = false;
      }
      
      else {
         A_alive = false;
      }
   }
} // Close Method Brace

         ////////////////////////////////////////////////////

void Charlie_shoots(bool& A_alive, bool& B_alive) {
// NOTE: Charlie never misses. No need for determinant.

   if (B_alive) {
      B_alive = false;
   }
         
   else {
      A_alive = false;
   }
} // Close Method Brace

         ////////////////////////////////////////////////////

void Aaron_shoots2(bool& B_alive, bool& C_alive) {
   int determinant = rand()%100;

   // If statement based on digital logic
   if (!(B_alive && C_alive)) {
   
      if (determinant <=  A_ACCURACY) {
      
         if (C_alive) {
            C_alive = false;
         }
         
         else {
            B_alive = false;
         }
      }
   }
} // Close Method Brace

         ////////////////////////////////////////////////////

void Press_any_key(void) {
   cout << "Press any key to continue...";
   cin.ignore().get();
} // Close Method Brace

         ////////////////////////////////////////////////////

void a_fires(void) {

   // Instantiate and set variables
   bool a_alive = true;
   bool b_alive = true;
   bool c_alive = true;
   
   while (at_least_two_alive(a_alive, b_alive, c_alive)) {
      if (a_alive) {
         Aaron_shoots1(b_alive, c_alive);
      }
         
      if (b_alive) {
         Bob_shoots(a_alive, c_alive);
      }
         
      if (c_alive) {
         Charlie_shoots(a_alive, b_alive);
      }
   }
         
   if (a_alive) {
      Aaron_survives++;
   }
   
   else if (b_alive) {
      Bob_survives++;
   }
   
   else if (c_alive) {
      Charlie_survives++;
   }     
} // Close Method Brace

         ////////////////////////////////////////////////////

void a_feigns(void){

   // Instantiate and set variables
   bool a_alive = true;
   bool b_alive = true;
   bool c_alive = true;
   
   while (at_least_two_alive(a_alive, b_alive, c_alive)) {
      if (a_alive) {
         Aaron_shoots2(b_alive, c_alive);
      }
         
      if (b_alive) {
         Bob_shoots(a_alive, c_alive);
      }
         
      if (c_alive) {
         Charlie_shoots(a_alive, b_alive);
      }
   }
         
   if (a_alive) {
      Aaron_survives++;
   }
   
   else if (b_alive) {
      Bob_survives++;
   }
   
   else if (c_alive) {
      Charlie_survives++;
   }     
} // Close Method Brace

      ////////////////////////////////////////////////////
      ///////////////////UNIT TESTING/////////////////////
      ////////////////////////////////////////////////////
      
void test_at_least_two_alive(void) {

   cout << "Unit Testing 1: Function - at_least_two_alive()\n";

   cout <<"\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout <<"\tCase passed ...\n";
   
   cout <<"\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout <<"\tCase passed ...\n";
   
   cout <<"\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, false));
   cout <<"\tCase passed ...\n";
   
   cout <<"\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout <<"\tCase passed ...\n";
   
   cout<< "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false, true));
   cout << "\tCase passed ...\n";
	
   cout<< "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false, true, false));
   cout << "\tCase passed ...\n";
	
   cout<< "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true, false, false));
   cout << "\tCase passed ...\n";
	
   cout<< "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false, false, false));
   cout << "\tCase passed ...\n";
      
} // Close Test Method

         ////////////////////////////////////////////////////

void test_Aaron_shoots1(void) {

   cout << "Unit Test 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
   
   // Case 1 (Aaron v. Both)
   cout << "\tCase 1: Bob alive, Charlie alive\n"
      << "\t\tAaron is shooting at Charlie\n";
   
   // Instantiate and set variables  
   bool Bob_alive = true;
   bool Charlie_alive = true;
     
   Aaron_shoots1(Bob_alive, Charlie_alive);
   assert(true == Bob_alive);
   
   // Case 2 (Aaron v. Charlie)
   cout << "\tCase 2: Bob dead, Charlie alive\n"
        << "\t\tAaron is shooting at Charlie\n";
   
   // Set variables     
   Bob_alive = false; 
   Charlie_alive = true;
   
   Aaron_shoots1(Bob_alive, Charlie_alive);
   assert(false == Bob_alive);
	
   // Case 3 (Aaron v. Bob)
   cout << "\tCase 3: Bob alive, Charlie dead\n";
   cout << "\t\tAaron is shooting at Bob\n";
   
   // Set variables 
   Bob_alive = true; 
   Charlie_alive = false;
   
   Aaron_shoots1(Bob_alive, Charlie_alive);
   assert(false == Charlie_alive);
   
} // Close Test Method
           
            ////////////////////////////////////////////////////
   
void test_Bob_shoots(void) {

   cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
   
   // Case 1 (Bob v. Both)
   cout << "\tCase 1: Aaron alive, Charlie alive\n"
        << "\t\tBob is shooting at Charlie\n";
   
   // Instantiate and set varibales
   bool Aaron_alive = true;
   bool Charlie_alive = true;
   
   Bob_shoots(Aaron_alive, Charlie_alive);
   assert(true == Aaron_alive);
	
   // Case 2 (Bob v. Charlie)
   cout << "\tCase 2: Aaron dead, Charlie alive\n"
        << "\t\tBob is shooting at Charlie\n";
        
   // Set varibales     
   Aaron_alive = false;
   Charlie_alive = true;
   
   Bob_shoots(Aaron_alive, Charlie_alive);
   assert(false == Aaron_alive);
   
   // Case 3 (Bob v. Aaron)
   cout << "\tCase 3: Aaron alive, Charlie dead\n";
   cout << "\t\tBob is shooting at Charlie\n";
   
   // Set varibales
   Aaron_alive = true;
   Charlie_alive = false;
   
   Bob_shoots(Aaron_alive, Charlie_alive);
   assert(false == Charlie_alive);
   
} // Close Test Method

               ////////////////////////////////////////////////////
               
void test_Charlie_shoots(void) {

   cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
	
   // Case 1 (Charlie v. Both)
   cout << "\tCase 1: Aaron alive, Bob alive\n";
   cout << "\t\tCharlie is shooting at Bob\n";
   
   // Instantiate and set varibales
   bool Aaron_alive = true;
   bool Bob_alive = true;
   
   Charlie_shoots(Aaron_alive, Bob_alive);
   assert(true == Aaron_alive);
   assert(false == Bob_alive);
	
   // Case 2 (Charlie v. Bob)
   cout << "\tCase 2: Aaron dead, Bob alive\n"
        << "\t\tCharlie is shooting at Bob\n";
   
   // Set varibales
   Aaron_alive = false;
   Bob_alive = true;
   
   Charlie_shoots(Aaron_alive, Bob_alive);
   assert(false == Aaron_alive);
   assert(false == Bob_alive);
	
   // Case 3 (Charlie v. Aaron)
   cout << "\tCase 3: Aaron alive, Bob dead\n"
        << "\t\tCharlie is shooting at Aaron\n";
   
   // Set varibales
   Aaron_alive = true;
   Bob_alive = false;
   
   Charlie_shoots(Aaron_alive, Bob_alive);
   assert(false == Aaron_alive);
   assert(false == Bob_alive);
   
} // Close Test Method

               ////////////////////////////////////////////////////

void test_Aaron_shoots2(void) {

   cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
   
   // Case 1 (Aaron v. Both)
   cout << "\tCase 1: Bob alive, Charlie alive\n"
        << "\t\tAaron intentionally misses his first shot\n";
   
   // Instantiate and set varibales
   bool Bob_alive = true;
   bool Charlie_alive = true;
   
   Aaron_shoots2(Bob_alive, Charlie_alive);
   assert(true == Bob_alive);
   assert(true == Charlie_alive);
   cout << "\t\tBoth Bob and Charlie are alive.\n";
	
   // Case 2 (Aaron v. Charlie)
   cout << "\tCase 2: Bob dead, Charlie alive\n"
        << "\t\tAaron is shooting at Charlie\n";
   
   // Set varibales
   Bob_alive = false;
   Charlie_alive = true;
   
   Aaron_shoots2(Bob_alive, Charlie_alive);
   assert(false == Bob_alive);
   
   // Case 3 (Aaron v. Bob)
   cout << "\tCase 3: Bob alive, Charlie dead\n"
        << "\t\tAaron is shooting at Bob\n";
   
   // Set varibales
   Bob_alive = true;
   Charlie_alive = false;
   
   Aaron_shoots2(Bob_alive, Charlie_alive);
   assert(false == Charlie_alive);
   
} // Close Test Method

/*NOTE:  I sat here for like 15 minutes waiting for this program to "finish"
 *       the first time I ran it, not realizing that you had to press <Enter>
 *       twice. I was thinking, "maybe 10,000 loops just takes a while...
 *       then got worried I was in an infinite-loop... Finally realized that
 *       once you hit <Enter> again it ran. So... that was a thing.
 */