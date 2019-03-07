#include <iostream>
#include <cstdlib>
#include <string> 
 
using namespace std;
int main(){

/*32 bit ALU*/
        char A2[33] = "0000111110100110010110010000000";
        char B2[33] = "0011001011011110001001010101010";
        char Cin2[2] = "0";  
        char zero2[2] = "0";
        int a2[3];
        int b2[33];
        int bb[33];
        int Result2[33];
         
        /*Makes an int out of input A*/
        for(int i=0; i<32; i++){
            if(A2[i] == zero2[0]){
                a2[i] = 0;
            }
            else{
                a2[i] = 1;
            }
        }
        /*Makes an int out of input B*/
        for(int i=0; i<32; i++){
            if(B2[i] == zero2[0]){
                b2[i] = 0;
            }
            else{
                b2[i] = 1;
            }
        }
        /*Makes an int out of input B INVERSE using twos compliment*/
        for(int i=0; i<32; i++){
            if(B2[i] == zero2[0]){
                bb[i] = 1;
            }
            else{
                bb[i] = 0;
            }
        }
        bb[31]++;

        cout << "32 bit ALU" << endl;
        cout << "--------------------";
        cout << "\nThe first input is:                 ";
        for(int i=0; i<32; i++){
            cout << a2[i];
            }
        cout << "\nThe second input is:                ";
        for(int i=0; i<32; i++){
            cout << b2[i];
            }
        cout << "\nThe INVERSE of the second input is: ";
        for(int i=0; i<32; i++){
            cout << bb[i];
            }
        cout << "\nThe carry-in is:                    ";
        for(int i=0;i<1;i++){
            cout << Cin2[i];
        }
        cout << "\n--------------------";

        /**************************/
        //        EQU
        /**************************/
        int equ;
        cout << a2;
        cout << "\n--------------------";
        cout << b2;
        for(int i=0; i<32; i++){
            if(a2[i]==b2[i]){
                    equ=1;
            }
            else{
                equ=0;
            }
            
        }
        cout << "\nThe Result of EQU is: ";
        cout << equ;
        cout << "\n";
        /**************************/
        //        LESS THAN
        /**************************/

         for(int i=0; i<32; i++){
            Result2[i] = a2[i]&b2[i];
            }
        cout << "\nThe Result of AND is: ";
        for(int i=0;i<32;i++){
            cout << Result2[i];
        }
        cout << "\n";

        /**************************/
        //     LESS THAN UNSIGNED
        /**************************/
        
        /**************************/
        //     GREATER THAN
        /**************************/
        

        /**************************/
        //   GREATER THAN UNSIGNED
        /**************************/
        

        /**************************/
        //         ADD
        /**************************/
        
        /**************************/
        //     ADD UNSIGNED
        /**************************/
        
        /**************************/
        //      SUB UNSIGNED
        /**************************/
        
        /**************************/
        //    SHIFT LEFT LOGICAL
        /**************************/
        
        /**************************/
        //   SHIFT RIGHT LOGICAL
        /**************************/
        
        /**************************/
        // SHIFT RIGHT ARITMETIC
        /**************************/
        

        /**************************/
        //   BITWISE OR
        /**************************/


        /**************************/
        //   BITWISE XOR
        /**************************/


        /**************************/
        //   BITWISE AND
        /**************************/
        


        /*AND*/
        for(int i=0; i<32; i++){
            Result2[i] = a2[i]&b2[i];
            }
        cout << "\nThe Result of AND is: ";
        for(int i=0;i<32;i++){
            cout << Result2[i];
        }
        cout << "\n";
        /*OR*/
        for(int i=0; i<32; i++){
            Result2[i] = a2[i]|b2[i];
            }
        cout << "The Result of OR is:  ";
        for(int i=0;i<32;i++){
            cout << Result2[i];
        }
        cout << "\n";


        /*XOR*/
        for(int i=0; i<32; i++){
            Result2[i] = a2[i]^b2[i];
            }
        cout << "The Result of XOR is: ";
        for(int i=0;i<32;i++){
            cout << Result2[i];
        }
        cout << "\n";


        /*Sub*/
        for(int i=0; i<32; i++){
            Result2[i] = a2[i]|bb[i];
            }
        cout << "The Result of Sub is: ";
        for(int i=0;i<32;i++){
            cout << Result2[i];
        }
        cout << "\n";
    return 0;
}