#include <stdio.h>
 
#include <string.h>

//for isspace// #include <ctype.h>

 
 
//FUNCTIONS TO READ FROM INPUT/

 
//read encryption key from INPUT 
char read_encryption_key(int *rotation_cypher, char *substitution_cypher);

/*unused
//read encryption key from terminal
char read_encryption_key_terminal;
*/
 
//read string from INPUT 
unsigned int read_string(char *string, unsigned int string_length);

//FUNCTIONS TO WRITE TO OUTPUT// 
//TODO//


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
 
    //declare FILES
 
    FILE *INPUT;
 
    INPUT = fopen("INPUT","r");

    if ( INPUT == NULL ) {
        perror("fopen()");
    }


    FILE *OUTPUT;

    OUTPUT = fopen("OUTPUT","a");
 
    if ( OUTPUT == NULL ) {
        perror("fopen()");
    }
    
    
    
    //declare rotation_cypher as an integer
    int rotation_cypher = 0;
    
    //declare array to hold substitution cypher
    char substitution_cypher[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    
    
    //read value for cypher form INPUT, if sucessful print encryption key to terminal //TODO// and set function type    
    char cypher_type = 0;
    
    switch ( read_encryption_key(&rotation_cypher, substitution_cypher) ) {
        case 1:
            printf("CASE_1: ROTATION_KEY\n");
            cypher_type = 1;
            break;
        case 2:
            printf("CASE_2: SUBSTITUTION_KEY\n");
            cypher_type = 2;
            break;
        case 0:
            printf("CASE_0: ERROR\n");
            break;
    }
    printf("CYPHER_TYPE: %d\n", cypher_type);
    
    //declare string //unused// as an array of characters 
    char string[1024];  //unused// = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    
    //get number of characters in string 
    unsigned int string_length = strlen(string);

    //read string from INPUT
    string_length = read_string(string, string_length);
    printf("STRING_LENGHT: %d\n", string_length);
    
/*
    //convert to //convert string to all caps 
    check_all_caps(string, string_length);
    
    
    //verify string is valid (A,B,C,... )
    
    //? int stringN[1024];
    
    //convert each character in string from ASCII to a number from 1 to 25
    convert_from_ASCII(string, string_length, stringN);
    
    //encrypt with rotation cypher 
    rotation_encode(string, string_length, rotation_cypher);
    
    
    //convert each character in string from a number from 0 to 25 to ASCII
    convert_to_ASCII(string, string_length, stringN);
    
    
    //print cypher key and encrypted string to OUTPUT
    printf("Key is: %d\n", rotation_cypher);
     
    printf("The length of the string is: %d\n", string_length);
     
    printf("The encrypted string is: %s\n", string);
     
*/  return 0; 
}
//************************************************//



                //END OF MAIN CODE//



//************************************************//


//read encryption key from INPUT
char read_encryption_key(int *rotation_cypher, char *substitution_cypher) {
    
    //declare FILE INPUT
    FILE *INPUT;
 
    INPUT = fopen("INPUT","r");

    if ( INPUT == NULL ) {
        perror("fopen()");
    }
    
    int read = 0;
    
    read = fscanf(INPUT,"#KEY: %d", rotation_cypher);            //if rotation key
    rewind(INPUT);  //return curser to start of file
    
    if (read > 0) {
        printf("KEY_IS: %d\n", *rotation_cypher);
        return 1;
    }
    
    read = fscanf(INPUT,"#KEY: %s", substitution_cypher);
    rewind(INPUT);  //return curser to start of file
    
    if ( ( read > 0 ) && ( substitution_cypher[0] != '#' ) ) {  //if substitution key
        //TODO// verify key
        printf("KEY_IS: %s\n", substitution_cypher);
        return 2;
    }
                                                                //if no valid key
    printf("ERROR: KEY NOT FOUND\n");
    return 0;
}


//function to read string from INPUT 
unsigned int read_string(char *string, unsigned int string_length) 
{ 
    FILE *INPUT;
    
    INPUT = fopen("INPUT","r");

    if ( INPUT == NULL ) {
        perror("fopen()");
    }
    
    int count = 0;  //initiate integer for counting loops
    int c = 0;
    
    for ( count = 0 ; count < 100 ; count++ ) {
        if ( fscanf(INPUT,"#INPUT: %d", c) != 0 ) {
            break;
        }
    }
    printf("TEST_COUNT: %d\n",count);
    
    for ( count = 0 ; feof(INPUT) == 0 ; count++) {  //until end of file reached 
        
        char c;
        
        fscanf(INPUT,"%c", &c);
        
        string[count] = c;
        string[count+1] = 0;
        
        count++;
    }
    clearerr(INPUT);
    
    printf("STRING_IS: %s\n", string);
    
     
    if ( count < string_length ) {
        return count;
    } 
     else {
        string[string_length] = 0;
        
        return 0; 
    }
}


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





