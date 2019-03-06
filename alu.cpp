#include <iostream>
#include <cstdlib>
#include <string> 
 
using namespace std;
int main(){
/*4-bit ALU*/
        char A[5] = "0101";
        char B[5] = "0011";
        char zero[2] = "0";
        int a[5];
        int b[5];
        char Cin[2] = "0";
        int Result[5];
         
        /*Makes an int out of input A*/
        for(int i=0; i<4; i++){
            if(A[i] == zero[0]){
                a[i] = 0;
            }
            else{
                a[i] = 1;
            }
        }
        /*Makes an int out of input B*/
        for(int i=0; i<4; i++){
            if(B[i] == zero[0]){
                b[i] = 0;
            }
            else{
                b[i] = 1;
            }
        }
        cout << "4 bit ALU" << endl;
        cout << "--------------------";
        cout << "\nThe first input is:  ";
        for(int i=0; i<4; i++){
            cout << a[i];
            }
        cout << "\nThe second input is: ";
        for(int i=0; i<4; i++){
            cout << b[i];
            }
        cout << "\nThe carry-in is:        ";
        for(int i=0;i<1;i++){
            cout << Cin[i];
        }
        cout << "\n--------------------";
        /*AND*/
        for(int i=0; i<4; i++){
            Result[i] = a[i]&b[i];
            }
        cout << "\nThe Result of AND is: ";
        for(int i=0;i<4;i++){
            cout << Result[i];
        }
        cout << "\n";
        /*OR*/
        for(int i=0; i<4; i++){
            Result[i] = a[i]|b[i];
            }
        cout << "The Result of OR is:  ";
        for(int i=0;i<4;i++){
            cout << Result[i];
        }
        cout << "\n";
        /*XOR*/
        for(int i=0; i<4; i++){
            Result[i] = a[i]^b[i];
            }
        cout << "The Result of XOR is: ";
        for(int i=0;i<4;i++){
            cout << Result[i];
        }
         
        cout << "\n";
/*32 bit ALU*/
        char A2[33] = "000011111010011001011001";
        char B2[33] = "001100101101111000100101";
        char zero2[2] = "0";
        int a2[33];
        int b2[33];
        int bb[33];
        char Cin2[2] = "0";
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