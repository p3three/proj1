
#include <stdio.h>
#include <string.h>



//function to convert string to all caps//
char check_all_caps(char *string, unsigned int string_length);


//function to convert each character in string from ASCII to a number from 0 to 25//
char convert_from_ASCII(char *string, unsigned int string_length, int *stringN);

//function to convert each character in string from a number from 0 to 25 to ASCII//
char convert_to_ASCII(char *string, unsigned int string_length, int *stringN);


//FUNCTIONS FOR ROTATION CYPHER//

//functon to encode string with rotation cypher//
char rotation_encode(char *string, unsigned int string_length, int rotation_cypher);

//function to decode string with rotation cypher//
char rotation_decode(char *string, unsigned int string_length, int rotation_cypher);

//function to decode string without rotation cypher//
char rotation_decrypt(char *string, unsigned int string_length);



//FUNCTIONS FOR SUBSTITUTION CYPHER

//function to encode string with substitution cypher//
char substitution_encode(char *string, unsigned int string_length, char *substitution_cypher, unsigned int cypher_n);

//function to decode string with substitution cypher//
char substitution_decode(char *string, unsigned int string_length, char *substitution_cypher, unsigned int cypher_n);

//function to decode string without substitution cypher//
char substitution_decrypt(char *string, unsigned int string_length);



//**************************************************//
                //START OF MAIN CODE//
int main() {
    
    //declare rotation_cypher as an integer
    int rotation_cypher = 0;
    //read value for rotaion_cypher form INPUT, if sucessful set function tye to 1
    if ( scanf("#%d", &rotation_cypher) ) {
        //function = 1;
    }
    
    //declare string as an array of characters
    char string[1024];  //unused = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    scanf("%s", string);  //string in
    
    int stringN[1024];
    
    //get number of characters in string
    unsigned int string_length = strlen(string);
          
    //convert to //convert string to all caps
    check_all_caps(string, string_length);
    //verify string is valid (A,B,C,... )
    
    
    //convert each character in string from ASCII to a number from 1 to 25
    convert_from_ASCII(string, string_length, stringN);
    
    
    
    //encrypt with rotation cypher
    rotation_encode(string, string_length, rotation_cypher);
    
    
    //convert each character in string from a number from 0 to 25 to ASCII
    convert_to_ASCII(string, string_length, stringN);
    
    
    //print cypher key and encrypted string
    printf("Key is: %d\n", rotation_cypher);
    
    printf("The length of the string is: %d\n", string_length);
    
    printf("The encrypted string is: %s\n", string);
    
    return 0;
}
                //END OF MAIN CODE//
//************************************************//


/*/ UNUSED
//function to read string from INPUT
unsigned int input_string(char *string, unsigned int string_length)
{
    int n = 0;  //initiate integer for loop count
    do {
        
        scanf("%c", string[n]);
        n++;
        
    } while ( string[n] != 0 || n < string_length );
    
    if ( n < string_length ) {
        string[n] = 0;
        string_length = n;
        return string_length;    
    }
     else {
         return 0;
    }
}
/*/


//function to convert string to all caps
char check_all_caps(char *string, unsigned int string_length)
{
    
    //while n is less than the number of characters in string do following then increase n by one then repeat
    for ( int n = 0 ; n < string_length ; n++ ) {
        
        //if the character at n is lowercase convert to uppercase
        if ( string[n] >= 97 && string[n] <= 122 ) {
            string[n] -= 32;
            
        }      
        
    }
    for ( int n = 0 ; n < string_length ; n++ ) {
        printf("%d", (int)string[n]);
    }
    printf("\n");
    
    return 1;
}



//function to convert each character in string from ASCII to a number from 1 to 25
char convert_from_ASCII(char *string, unsigned int string_length, int *stringN)
{
    //convert each character in string from ASCII value to number from 0 to 25
    for ( int n ; n < string_length ; n++ ) {
        
        //if the character at string[n] is an uppercase letter convert
        if ( string[n] >= 65 && string[n] <= 90 ) {
            stringN[n] = (int)string[n] - 65;
        }
        
    }
    
    for ( int n = 0 ; n < string_length ; n++ ) {
        printf("%d", stringN[n]);
    }
    printf("\n");
    
    return 1;
}

//function to convert each character in string from a number from 0 to 25 to ASCII
char convert_to_ASCII(char *string, unsigned int string_length, int *stringN)
{
    //convert each character in string from number from 0 to 25 to ASCII value
    for ( int n ; n < string_length ; n++ ) {
        
        //if the character at string[n] is an uppercase letter convert
       if ( string[n] >= 65 && string[n] <= 90 ) {
            stringN[n] = string[n] + 65;
        }
        
    }   
    
    for ( int n = 0 ; n < string_length ; n++ ) {
        printf("%d", stringN[n]);
    }
    printf("\n");
    
    return 1;
}



//FUNCTIONS FOR ROTATION CYPHER//

//functon to encode string with rotation cypher//
char rotation_encode(char *string, unsigned int string_length, int rotation_cypher)
{
    for ( int n = 0 ; n < string_length ; n++ ) {
        if ( string[n] >= 0 && string[n] <= 25 ) {
            string[n] = ( string[n] + rotation_cypher + 26 ) % 26;
        }
    }
    printf("%s\n", string);
    return 1;
}


//function to decode string with rotation cypher//
char rotation_decode(char *string, unsigned int string_length, int rotation_cypher)
{
    for ( int n = 0 ; n < string_length ; n++ ) {
        if ( string[n] >= 0 && string[n] <= 25 ) {
            string[n] = ( string[n] - rotation_cypher + 26 ) % 26;
        }
    }    
    printf("%s\n", string);
    return 1;
}


//function to decode string without rotation cypher//
char rotation_decrypt(char *string, unsigned int string_length)
{
    
    return 1;
}



//FUNCTIONS FOR SUBSTITUTION CYPHER

//function to encode string with substitution cypher
char substitution_encode(char *string, unsigned int string_length, char *substitution_cypher, unsigned int cypher_n);

//function to decode string with substitution cypher
char substitution_decode(char *string, unsigned int string_length, char *substitution_cypher, unsigned int cypher_n);

//function to decode string without substitution cypher
char substitution_decrypt(char *string, unsigned int string_length);







