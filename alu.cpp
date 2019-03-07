//////////////////////////////////////////////////////////////////////////////////
// Company: INSTITUTO TECNOLOGICO DE COSTA RICA
// Engineer: JOAO SALAS 
// 

// Module Name: ALU_REFERENCE MODEL
// Project Name: PROYECTO DE GRADUACIÓN 
// 
//////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <string> 
#include <math.h>

 
using namespace std;
int main(){

        /**************************/
        //        32-bit ALU
        /**************************/

        //inputs
        char A2[32] = "0000111110100110010110010000000";
        char B2[32] = "0011001011011110001001010101010";
        char Cin2[2] = "0";  
        
        int a2[32];
        int b2[32];
        int bb[32];
        int Result2[32];
        //outputs
        int Zero,oVerflow,Negative,Carry_out,OUT;
        
        
        a2=to_int(A2);
        b2=to_int(B2);


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
        
        switch (alu_control)
        {
            case 0:  // EQU
                break;
            case 1: //LESS_THAN
                break;
            case 2: //LESS_THAN UNSIGNED
                break;
            case 3: //GREATER_THAN
                break;
            case 4: //GREATER_THAN UNSIGNED
                break;
            case 5: // ADD
                break;
            case 6: // ADD UNSIGNED
                break;
            case 7: // SUB UNSIGNED
                break;
            case 8: // SHIFT LEFT LOGICAL
                break;
            case 9: // SHIFT RIGHT LOGICAL
                break;
            case 10: // SHIFT RIGHT ARITMETIC
                break;
            case 11: // BITWISE OR
                break;
            case 12: // BITWISE XOR
                break;
            case 13: // BITWISE AND
                break;
            default:
                break;
        }

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


int compare(int cod){
    int result;
    unsigned int a2_unsigned;
    unsigned int b2_unsigned;
    switch (cod)
    {
        case 0:
        /**************************/
        //        EQU
        /**************************/
        if(a2==b2){
            result=1;
            }
        else{
            result=0;
            } 
        }
        cout << "\n Result of EQU is: ";
        cout << result;
        cout << "\n";
        break;
    
        case 1:
        /**************************/
        //        LESS THAN
        /**************************/
        if(a2<b2){
            result=1;
        }
        else
        {
            result=0;
        }
        cout << "\n Result of LESS THAN is: ";
        cout << result;
        cout << "\n";
        break;

    
        case 2:
        /**************************/
        //     LESS THAN UNSIGNED
        /**************************/
        a2_unsigned= abs(a2);
        b2_unsigned= abs(b2);
        if(a2_unsigned<b2_unsigned){
            result=1;
        }
        else
        {
            result=0;
        }
        cout << "\n Result of LESS THAN UNSIGNED is: ";
        cout << result;
        cout << "\n";
        break;
    
        case 3:
        /**************************/
        //     GREATER THAN
        /**************************/
        if(a2>b2){
            result=1;
        }
        else
        {
            result=0;
        }
        cout << "\n Result of GREATER THAN is: ";
        cout << result;
        cout << "\n";
        
        break;
        case 4:
         /**************************/
        //   GREATER THAN UNSIGNED
        /**************************/
        a2_unsigned= abs(a2);
        b2_unsigned= abs(b2);
        if(a2_unsigned>b2_unsigned){
            result=1;
        }
        else
        {
            result=0;
        }
        cout << "\n Result of GREATER THAN UNSIGNED is: ";
        cout << result;
        cout << "\n";
        break;
    
        default:
            result=0;
            cout << "\n No compare operation was done: ";
            cout << result;
            cout << "\n";
            break;
    }
    return result;
}

int logical(int cod){
    int result;
    switch (cod)
    {
        case 0:
        /**************************/
        //   BITWISE OR
        /**************************/
        result= a2 | b2;
        cout << "\n Result of BITWISE OR is: ";
        cout << result;
        cout << "\n";
        break;
        case 1:
        /**************************/
        //   BITWISE XOR
        /**************************/
        result= a2 ^ b2;
        cout << "\n Result of BITWISE XOR is: ";
        cout << result;
        cout << "\n";
        break;
        case 2:
        /**************************/
        //   BITWISE AND
        /**************************/
        result= a2 & b2;
        cout << "\n Result of  BITWISE AND is: ";
        cout << result;
        cout << "\n";
        break;
    
        default:
            result=0;
            cout << "\n No logical operation was done";
            cout << result;
            cout << "\n;"
            break;
    }
    return result;
}


int to_int(int A){
 /*Makes an int out of input A (32 bits)*/
 int result;
 char zero[2] = "0";
        for(int i=0; i<32; i++){
            if(A[i] == zero[0]){
                result[i] = 0;
            }
            else{
                result[i] = 1;
            }
        }
        return result;
}


        


        

        


        
        
        
        
        
        

       
        
