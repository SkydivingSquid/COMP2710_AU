/* File Name:  project4_martin_gbm0016.cpp
 * Author:     George Martin (gbm0016)
 * Class:      COMP 2710 - Dr. Li
 * Version:    15 July, 2021
 * 
 * Sources:    Stack overflow was referenced for string to uppercase function.
 *             CodeGrepper was used for string to int (stoi) function.
 *             GeeksForGeeks was used for goto function.
 *             This rest of this code was my own with help from Dr. Li's CANVAS files.
 *
 * Location:   home/u1/gbm0016/Project_4
 * Compile:    g++ -std=c++0x project4_martin_gbm0016.cpp -o project4.out
 * Run:        ./project4.out
 *
 * Note 1:     #define UNIT_TESTING is currently commented out. Uncomment line 39 for the UNIT_TESTING version.
 * Note 2:     Compile method uses additional string in order to run without errors. Posted on Piazza as well. 
 */
 
   ////////////////////////////////////////////////////
   /////////////////////LIBRARIES//////////////////////
   ////////////////////////////////////////////////////

#include <algorithm>
#include <assert.h>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

   ////////////////////////////////////////////////////
   ////////////////////CONDITIONS//////////////////////
   ////////////////////////////////////////////////////

/* uncomment to run Triva Quiz */  
#define trivia_quiz     

/* uncomment to run Unit_Testing */
//#define UNIT_TESTING    

   ////////////////////////////////////////////////////
   /////////////////METHOD PROTOTYPES//////////////////
   ////////////////////////////////////////////////////
   
bool add(string question_in, string answer_in, int value_in);
void setup_game();
bool ask_question(int num_ask);
void preLoaded_questions(int version);

   ////////////////////////////////////////////////////
   //////////////////NODE STRUCTURE////////////////////
   ////////////////////////////////////////////////////

struct TriviaGame {
   
   //Structure as defined in Dr. Li's hint .pdf
   struct trivia_node {
      string question;
      string answer;
      int value;
      trivia_node* next;
   
      //Elements node stores
      trivia_node(string question_in, string answer_in, int value_in) {
         question = question_in;
         answer = answer_in;
         value = value_in;
         next = nullptr;
      }
    };
  
   ////////////////////////////////////////////////////
   ///////////////////NODE ITERATOR////////////////////
   ////////////////////////////////////////////////////
   
   struct trivia_itr {
      trivia_node* current;
      
      trivia_itr(trivia_node* node_in) {
         current = new trivia_node("", "", 0);
         current -> next = node_in;
      }
      
      bool has_next() {
         return current -> next != nullptr;
      }
      
      trivia_node next() {
         current = current -> next;
         return (*current);
      }
      };

   ////////////////////////////////////////////////////
   ////////////////////VARIABLES///////////////////////
   ////////////////////////////////////////////////////
   
   trivia_node* first;
   trivia_node* last;
   int size;
   int score;
   
   ////////////////////////////////////////////////////
   //////////////////////METHODS///////////////////////
   ////////////////////////////////////////////////////
   
   //Initialize empty linked list
   TriviaGame() {
      first = nullptr;
      last = nullptr;
      size = 0;
      score = 0;
   }
   
   //Adds a new node to the linked list with question/answer/value elements.
   bool add(string question_in, string answer_in, int value_in) {
      trivia_node* new_node = new trivia_node(question_in, answer_in, value_in);
      
      //If list is empty, set as headnode
      if (size == 0) {
         first = new_node;
      }
      
      //If list is not empty, add as the last node
      else {
         last -> next = new_node;
      }
      last = new_node;
      size++;
      return true; //Return true if successful
   }
   
   //Return trivia_itr(first)
   trivia_itr iterator() {
      return trivia_itr(first);
   }

    ///////////////////////////////////////////////////
    //ASK USER TO SET GAME QUESTIONS, ANSWERS, VALUES//
    ///////////////////////////////////////////////////
   void setup_game() {
   
         ///////////////////
         //Local Variables//
         ///////////////////
      string new_question;
      string new_answer;
      string value_response;
      int new_value;
      
         ////////////////////////
         //ASK FOR NEW QUESTION//
         ////////////////////////
         
      //If response is empty, warn and loop. 
      do {
         cout << "Enter a question: ";
         getline(cin, new_question);
         
         //Verify question is not empty.
         if (new_question.empty())
            cout << "Question cannot be empty space.\n";
         
      } while (new_question.empty());
      
         //////////////////////////
         //ASK FOR CORRECT ANSWER//
         //////////////////////////
      
      //If response is empty, warn and loop. 
      do {
         cout << "Enter an answer: ";
         getline(cin, new_answer);
         
         //Verify answer is not empty.
         if (new_answer.empty())
            cout << "Answer cannot be empty space.\n";
         
      } while (new_answer.empty());
      
         //////////////////////////
         //ASK FOR QUESTION VALUE//
         //////////////////////////
         
      //If response is empty or negative, warn and loop. 
      do {
      
         do {
            cout << "Enter award points: ";
            getline(cin, value_response);
            
            //Verify that value is not empty.
            if (value_response.empty())
               cout << "Award points cannot be empty space.\n";
         } while (value_response.empty()); 
         
         //Convert string value to int
         new_value = stoi(value_response);
         
         //Verify that value is non-negative
         if (new_value < 0)
            cout << "Award points must be a non-negative value.\n";
      }  while (new_value < 0);
      
      //Add question, answer, and value to linked list.
      add(new_question, new_answer, new_value);
   }
   
    ///////////////////////////////////////////////////////
    //UNIT TEST METHOD - SET HOW MANY QUESTIONS TO ANSWER//
    ///////////////////////////////////////////////////////
   bool ask_question(int num_ask) {
     
     //Ask no questions
      if (num_ask < 1) {
         cout << "Warning - the number of trivia to be asked must equal to or be larger than 1." << endl;
         return false;
      }
      
      //Ask more questions than in list
      else if (size < num_ask) {
         cout << "Warning - There is only " << size << " trivia in the list." << endl;
         return false;
      }
      
      //Ask valid number of questions
      else {
         score = 0;
         trivia_itr cycle = iterator();
         int count = 0;
         
         //Verify bounds
         while (cycle.has_next() && count < num_ask) {
         
            //Move current node to next node
            trivia_node current = cycle.next();
            
            string user_answer;
            cout << "\nQuestion: " << current.question;
            cout << "\nAnswer: ";
            
            //Get guess-answer from end user
            getline(cin, user_answer);
            
            //Set new variable for comparison
            string upper1 = user_answer;
            string upper2 = current.answer;
            
            //Compare answers in uppercase
            transform(upper1.begin(), upper1.end(), upper1.begin(), :: toupper);
            transform(upper2.begin(), upper2.end(), upper2.begin(), :: toupper);
            
            //If answers are the same award points
            if (upper1.compare(upper2) == 0) {
               cout << "Your answer is correct! You receive " << current.value << " points." << endl;
               score += current.value;
            }
            
            //If answers are different, award 0 points; show correct answer.
            else {
               cout << "Your answer is wrong. The correct answer is: " << current.answer << endl;
            }
            cout << "Your total points: " << score << endl;
            count++;
         }
         return true;
      }
   }

    /////////////////////////////////////////////////////////////////
    //UNIT TEST METHOD - INITIALIZE TEST QUESTIONS, ANSWERS, POINTS//
    /////////////////////////////////////////////////////////////////
   void preLoaded_questions(int n) {
      add("How long was the shortest war on record?", "38", 100);
      add("What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)?", "Bank of Italy", 50);
      add("What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?", "Wii Sports", 20);
   }
   
}; // Final Structure Brace

   ////////////////////////////////////////////////////
   //////////////////////MAIN//////////////////////////
   ////////////////////////////////////////////////////

int main() {
   TriviaGame game = TriviaGame();
   
    #ifdef trivia_quiz
   cout << "*** Welcome to George's trivia quiz game ***" << endl;
   
   bool more = false;
   
   do {
      //Ask for question, answer, value
      game.setup_game();
      string user_response = "";
      while (user_response == "") {
      //Ask if user wants to add more to trivia
      here:
         cout << "Continue? (Yes/No): ";
         getline(cin, user_response);
         
         //If user does not enter a response
         if (user_response.empty()) {
            cout << "Invalid Response" << endl;
            goto here;
         }
         
         //If user indicates yes, loop
         else if (user_response.at(0) == 'y' || user_response.at(0) == 'Y') {
            more = true;
         }
         
         //If user indicates no, break boolean loop
         else if (user_response.at(0) == 'n' || user_response.at(0) == 'N') {
            more = false;
         }
         
         //If response invalue, ask user for valid response.
         else {
            cout << "Invalid Response" << endl;
            goto here;
         
         }
      }
   } while (more);
   
   //Begin game by asking questions in list
   game.ask_question(game.size);
   
   //Thank user(s) in a positive manner. Do not force them to take survey or upgrade. 
   cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***\n\n";
   
    #endif
    
   ////////////////////////////////////////////////////
   ///////////////////UNIT TESTING/////////////////////
   ////////////////////////////////////////////////////
   
    #ifdef UNIT_TESTING
   cout << "*** This is a debugging version ***" << endl;
   cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
   bool warning = game.ask_question(0);
   assert(!warning);
   cout << "Case 1 Passed\n\n";
   
   game.preLoaded_questions(1);
   cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer.";
   game.ask_question(1);
   assert(game.score == 0);
   cout << "\nCase 2.1 passed\n\n";
   
   cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." ;
   game.ask_question(1);
   assert(game.score == 100);
   cout << "\nCase 2.2 passed\n\n";
   
   cout << "Unit Test Case 3: Ask all the questions in the linked list.";
   bool played = game.ask_question(3);
   assert(played);
   cout << "\nCase 3 passed\n\n";
   
   cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
   warning = game.ask_question(5);
   assert(!warning);
   cout << "\nCase 4 passed" << endl;
   
   cout << "*** End of debugging version ***";
    #endif
   
   return 0; 
   
} //Final Main Brace