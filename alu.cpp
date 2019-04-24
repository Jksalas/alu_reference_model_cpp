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
#include <stdlib.h> 
#include <math.h>
#include <fstream>
#include <string>
#include <bitset>
#include <tuple>
#include <stdexcept>

 
using namespace std;

const int arch=32;
const int architecture=32;

struct result{
   std::string suma;
   std::string carry;
   std::string overflow;
};

result addBinary(std::string a, std::string b, int carry_in); 
std::string complemento_a_dos(std::string bit_string);
result subBinary(std::string a, std::string b, int carry_in);
int compare(int a2, int b2,int cod);
int logical(int a2, int b2, int cod);
int shift(int a2, int b2, int cod);
int aritmetic(int a, int b, int cod);


int alu(int A, int B,int alu_control){

        /**************************/
        //        32-bit ALU
        /**************************/

        //--------------------------------------------
        //      inputs:
        // A first alu operand, B: second operand
        // alu_control: select variable
        //--------------------------------------------
        
        //-----------------------
        //      outputs
        //-----------------------

        int Zero,oVerflow,Negative,Carry,OUT;
        
        cout << "\n";
        cout << "--------------------\n";
        cout << "32 bit ALU" << endl;
        cout << "--------------------";
        cout << "\nThe first input is:                 ";
        cout << A;
        cout << "\nFirst input in binary: " << bitset<32>(A);
        cout << "\nThe second input is:                ";
        cout << B;
        cout << "\nSecond input in binary: " << bitset<32>(B);
        
        
        
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
                OUT = 0;
                Zero = compare(A,B,alu_control);
                oVerflow = 0;
                Carry = 0;
                cout << "Not found";
                break;
            case 6: // ADD UNSIGNED
                OUT = 0;
                Zero = 0;
                oVerflow = 0;
                Carry = 0;
                cout << "Not found";
                break;
            case 7: // SUB UNSIGNED
                OUT = 0;
                Zero = 0;
                oVerflow = 0;
                Carry = 0;
                cout << "Not found";
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

        
        cout << "\n";
    return 0;
}


int main(){
    int a;
    int b;
    int select;
    
    for(int i = 0; i < 20; i++)
    {
            a= rand() % 100;   
            b= rand() % 100;  
            select=rand()%13;
            alu(a,b,select);
    }
}

//********************************************
//          ------------------------
//              FUNCTIONS
//          ------------------------
//********************************************



/**************************/
//       ADD
/**************************/

result addBinary(string a, string b, int carry_in) {
   
    int ax = a.size();
    int bx = b.size();
    cout << "Size a: " << ax;
    cout << "\nSize b: " << bx;
    int len = max(ax+1, bx+1); //largo máximo de ambas entradas
    cout << "\nLen: " << len;
    char s[len-1] = {'0'};
    char cin[len-1]= {'0'};
    cin[0]=(char)(carry_in + '0');
    char overflow = '0';

    for(int i = 0; i < len; i++) {
        int x,y;
        int c = cin[i]-'0';
        if(ax-1-i < 0){
            x=0;
        }
        else{
            x = (int)(a[ax-1-i]-'0');
        }
        if(bx-1-i < 0){
            y=0;
        }
        else{
            y = (int)(b[bx-1-i]-'0');
        }
        s[i] = (char)(x ^ y ^ c + '0') ;  //Función lógica típica de la suma
        cin[i+1] = (char)((x&y)|(y&c)|(x&c) + '0'); //función de acarreo
                
        }
    overflow =(char)((cin[arch-1] ^ cin[arch-2]) + '0');
    cout << "\n";
    cout << "Over: "<<overflow << "\nSuma:" << s << "\nCarry_out:" << cin;
    std::string suma(s);
    string overflow_output(1, overflow);
    std::string carry_out(cin);
    return result {suma,carry_out,overflow_output};
    
}

string complemento_a_dos(string bit_string){
    char complemento_1[architecture];
    int i;

    for (i = 0; i < architecture; i++) 
        {
            if (bit_string[i] == '1') 
            {
                complemento_1[i] = '0';
            }
            else if (bit_string[i] == '0') 
            {
                complemento_1[i] = '1';
            }
        
        }
    string uno= "0001";
    int cero= 0;
    result complemento=addBinary(complemento_1,uno,cero);
    std::string c2(complemento.suma);
    return c2;

}

/**************************/
//       SUB
/**************************/

result subBinary(string a, string b, int carry_in){
    result resta;
    b = complemento_a_dos(b);
    resta=addBinary(a,b,carry_in);
    return resta;
}


int compare(int a2, int b2,int cod){
    int result;
    unsigned int a2_unsigned, b2_unsigned;
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
            
            cout << "\n Result of EQU is: ";
            cout << result;
            cout << "\n Result of EQU in binary: " << bitset<32>(result);
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
            cout << "\n Result of LESS THAN in binary: " << bitset<32>(result);
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
            cout << "\n Result of LESS THAN UNSIGNED in binary: " << bitset<32>(result);
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
            cout << "\n Result of GREATER THAN in binary: " << bitset<32>(result);
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
            cout << "\n Result of GREATER THAN UNSIGNED in binary: " << bitset<32>(result);
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

int logical(int a2, int b2, int cod){
    int result;
    switch (cod)
    {
        case 11:
        /**************************/
        //   BITWISE OR
        /**************************/
            result= a2 | b2;
            cout << "\n Result of BITWISE OR is: ";
            cout << result;
            cout << "\n Result of BITWISE OR in binary: " << bitset<32>(result);
            cout << "\n";
        break;
        case 12:
        /**************************/
        //   BITWISE XOR
        /**************************/
            result= a2 ^ b2;
            cout << "\n Result of BITWISE XOR is: ";
            cout << result;
            cout << "\n Result of BITWISE XOR in binary: " << bitset<32>(result);
            cout << "\n";
        break;
        case 13:
        /**************************/
        //   BITWISE AND
        /**************************/
            result= a2 & b2;
            cout << "\n Result of  BITWISE AND is: ";
            cout << result;
            cout << "\n Result of BITWISE AND in binary: " << bitset<32>(result);
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
        case 8: // SHIFT LEFT LOGICAL
            result= a2 << b2;
            cout << "\n Result of  SHIFT LEFT LOGICAL is: ";
            cout << result;
            cout << "\n Result of SHIFT LEFT LOGICAL in binary: " << bitset<32>(result);
            cout << "\n";
        break;
        case 9: // SHIFT RIGHT LOGICAL
            a2_unsigned= (unsigned int)a2;
            b2_unsigned= (unsigned int)b2;
            result= a2_unsigned >> b2_unsigned;
            cout << "\n Result of  SHIFT RIGHT LOGICAL is: ";
            cout << result;
            cout << "\n Result of SHIFT RIGHT LOGICAL in binary: " << bitset<32>(result);
            cout << "\n";
        break;
        case 10: // SHIFT RIGHT ARITMETIC
            result= a2 >> b2;
            cout << "\n Result of  SHIFT RIGHT ARITHMETIC is: ";
            cout << result;
            cout << "\n Result of SHIFT RIGHT ARITHMETIC in binary: " << bitset<32>(result);
            cout << "\n";
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
    int result;  //result[0]: resultado de la operación , result[1]: carry out 
    int oVerflow;
    switch (cod)
    {
        case 0: // ADD

                cout << "";
            
            
        break;

        case 1: // ADD UNSIGNED
                cout << "";

        break;

        case 2: // SUB UNSIGNED 
            cout << "";
        break;

        default:
            break;
    }
    return result;
}



        
        
        
        
        
        

       
        
