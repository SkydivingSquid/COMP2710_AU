#include <iostream> 
using namespace std; 
int main() 
{
   double a = 30;
   double b = 10000.0;
   double pi = 3.1415926;       
   double pi_round = 3.14151926;
        
   cout.precision(5);       
            
   cout << showpoint << "a1 = " << a << '\t' <<"b1 = " << b << '\t' << "pi1 = " << pi << '\t' << "pi_round1 = " << pi_round <<'\n';          
   cout << noshowpoint << "a2 = " << a << '\t' <<"b2 = " << b << '\t' << "pi2 = " << pi << '\t' << "pi_round2 = " << pi_round <<'\n';          
   cout << fixed<< "a3 = " << a << '\t' <<"b3 = " << b << '\t' << "pi3 = " << pi << '\t' << "pi_round3 = " << pi_round <<'\n';    
}