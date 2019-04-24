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
#include <bits/stdc++.h> 
 
using namespace std;
/*
std::tuple<double, char, std::string> get_student(int id)
{
    if (id == 0) return std::make_tuple(3.8, 'A', "Lisa Simpson");
    if (id == 1) return std::make_tuple(2.9, 'C', "Milhouse Van Houten");
    if (id == 2) return std::make_tuple(1.7, 'D', "Ralph Wiggum");
    throw std::invalid_argument("id");
}

*/


const int arch=4;
const int architecture=4;

struct result{
   std::string suma;
   std::string carry;
   std::string overflow;
};


void reverseStr(string& str) 
{ 
    int n = str.length(); 
  
    // Swap character starting from two 
    // corners 
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 


result addBinary(std::string a, std::string b, int carry_in) {
   
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
        s[i] = (char)(x ^ y ^ c + '0');
        cin[i+1] = (char)((x&y)|(y&c)|(x&c) + '0'); 
                
        }
    overflow =(char)((cin[arch-1] ^ cin[arch-2]) + '0');
    cout << "\n";
    cout << "Over: "<<overflow << "\nSuma:" << s << "\nCarry_out:" << cin;
    std::string suma(s);
    string overflow_output(1, overflow);
    std::string carry_out(cin);
    reverseStr(suma);
    reverseStr(carry_out);
    return result {suma,carry_out,overflow_output};
    //return std::make_tuple(s,cin);
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
    std::string uno= "1";
    int cero= 0;
    result complemento=addBinary(complemento_1,uno,cero);
    std::string c2(complemento.suma);
    return c2;

}

result subBinary(string a, string b, int carry_in){
    result resta;
    b = complemento_a_dos(b);
    resta=addBinary(a,b,carry_in);
    return resta;
}

std::string bit_to_string (std::bitset<32> mybits)
{
    string mystring;
    mystring = mybits.to_string();
    std::cout << "mystring: " << mystring << '\n';
    return mystring;
}

int main(){
    std::string c="11";
    std::string d;
    //int a = 1;
    int b = 3;
    //c=bit_to_string(bitset<32>(a));
    d=bit_to_string(bitset<32>(b)); 
    int carry = 0;
    result suma;
    suma = addBinary(c,d,carry);
    cout << "\n" << endl;
    cout << suma.carry <<  "\n" <<  suma.suma << "\n" <<suma.overflow <<endl;

    /*
    result suma;
    int carry = 0;
    char overflow;
    suma = subBinary(c,d,carry);
    cout << "\n" << endl;
    cout << suma.carry <<  "\n" <<  suma.suma << "\n" <<suma.overflow <<endl;
    d=complemento_a_dos(c);
    cout << "\nComplemento: " << d << endl; */
}


