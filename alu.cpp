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

        //-----------------------
        //      inputs
        //-----------------------
        char A2[32] = "0000111110100110010110010000000";
        char B2[32] = "0011001011011110001001010101010";
        char Cin2[2] = "0";  
        int alu_control;
        int a2[32];
        int b2[32];
        int bb[32];
        int Result2[32];
        //-----------------------
        //      outputs
        //-----------------------

        int Zero,oVerflow,Negative,Carry,OUT;
        
        
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
                OUT = 0;
                oVerflow = 0;
                Carry = 0;
                Zero = compare(A,B,alu_control);   
                break;
            case 1: //LESS_THAN
                OUT = 0;
                Zero = compare(A,B,alu_control);
                oVerflow = 0;
                Carry = 0;
            break;
            case 2: //LESS_THAN UNSIGNED
                OUT = 0;
                Zero = compare(A,B,alu_control);
                oVerflow = 0;
                Carry = 0;
            break;
            case 3: //GREATER_THAN
                OUT = 0;
                Zero = compare(A,B,alu_control);
                oVerflow = 0;
                Carry = 0;
            break;
            case 4: //GREATER_THAN UNSIGNED
                OUT = 0;
                Zero = compare(A,B,alu_control);
                oVerflow = 0;
                Carry = 0;
            break;

            case 5: // ADD
                break;
            case 6: // ADD UNSIGNED
                break;
            case 7: // SUB UNSIGNED
                break;

            case 8: // SHIFT LEFT LOGICAL
                OUT = shift(A,B,alu_control);
                Zero = 0;
                oVerflow = 0;
                Carry = 0;
            break;
            case 9: // SHIFT RIGHT LOGICAL
                OUT = shift(A,B,alu_control);
                Zero = 0;
                oVerflow = 0;
                Carry = 0;
                break;
            case 10: // SHIFT RIGHT ARITMETIC
                OUT = shift(A,B,alu_control);
                Zero = 0;
                oVerflow = 0;
                Carry = 0;
                break;
            case 11: // BITWISE OR
                OUT = logical(A,B,alu_control);
                Zero = 0;
                oVerflow = 0; 
                Carry = 0;  
            break;
            case 12: // BITWISE XOR
                OUT = logical(A,B,alu_control);
                Zero = 0;
                oVerflow = 0;
                Carry = 0; 
            break;
            case 13: // BITWISE AND
                OUT = logical(A,B,alu_control);
                Zero = 0;
                oVerflow = 0;
                Carry = 0;
                break;
            default:
                break;
        }


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

int compare(int a2, int b2){
    int result;
    unsigned int a2_unsigned, b2_unsigned;
    int cod=0;
    for(int i = 0; i < 5; i++)
    {
        
    
    switch (i)
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
            a2_unsigned= (unsigned int)a2;
            b2_unsigned= (unsigned int)b2;
            //unsigned int j = (unsigned int)i;
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
            a2_unsigned= (unsigned int)a2;
            b2_unsigned= (unsigned int)b2;
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
    }
    return result;
}

int logical(int a2, int b2, int cod){
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
            cout << "\n";
            break;
    }
    return result;
}

int shift(int a2, int b2, int cod){
    int result;
    unsigned int a2_unsigned;
    unsigned int b2_unsigned;
    switch (cod)
    {
        case 0: // SHIFT LEFT LOGICAL
            result= a2 << b2;
        break;
        case 1: // SHIFT RIGHT LOGICAL
            a2_unsigned= abs(a2);
            b2_unsigned= abs(b2);
            result= a2_unsigned >> b2_unsigned;
        break;
        case 2: // SHIFT RIGHT ARITMETIC
            result= a2 >> b2;
        break;
    
        default:
            result=0;
            cout << "\n No shift operation was done";
            cout << result;
            cout << "\n";
            break;

    }
    return result;
}

int aritmetic(int a, int b, int cod){
    int result[2];  //result[0]: resultado de la operación , result[1]: carry out  
    switch (cod)
    {
        case 0: // ADD
            
        break;

        case 1: // ADD UNSIGNED

        break;

        case 2: // SUB UNSIGNED 

        break;

        default:
            break;
    }
    return result;
}

int to_int(int A){
 /*Makes an int out of input A (32 bits)*/
 int result;
 char zero2[2] = "0";
        for(int i=0; i<32; i++){
            if(A[i] == zero2[0]){
                result[i] = 0;
            }
            else{
                result[i] = 1;
            }
        }
        return result;
}


        


        

        


        
        
        
        
        
        

       
        
