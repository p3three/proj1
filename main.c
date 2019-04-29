#include <stdio.h>
 
#include <string.h>


 
 
//FUNCTIONS TO READ FROM INPUT//


//read encryption key from INPUT_KEY//
//this function requires a FILE, a pointer to an integer and an array of type char (a string) that is 27 characters long (alphabet plus end NULL)
//this function will return a value of type char
// the value will be 1 to indicate a rotation-type cypher key
// the value will be 2 to indicate a substitution-type cypher key
char read_encryption_key(FILE *INPUT_KEY, int *rotation_key, char *substitution_key);


//read string from INPUT//
//this function requires a FILE, an array of type char and the length of the string as an unsigned integer 
//the return value of this function will be an unsigned integer
unsigned int read_string(FILE *INPUT, char *string, unsigned int string_length);


//convert string to all caps//
//this function requires a string and the string length as an unsigned integer
//this function will return a value of type char
char check_all_caps(char *string, const unsigned int string_length);


/*  //UNUSED//
//FUNCTION TO DECRYPT WITHOUT KEY//
char decrypt(char *string, const unsigned int string_length, int *rotation_key, char *substitution_key);
*/


//FUNCTIONS FOR ROTATION CYPHER//

 
//functon to encode string with rotation cypher//
//this function requires a string, the length onf the string as an unsigned integer and 
// a rotation key as an integer from 1 to 25
//this function will return a value of type char
char rotation_encode(char *string, const unsigned int string_length, int rotation_key);


//function to decode string with rotation cypher//
//this function requires a string, the length onf the string as an unsigned integer and 
// a rotation key as an integer from 1 to 25
//this function will return a value of type char
char rotation_decode(char *string, const unsigned int string_length, int rotation_key);

 /*TODO
//function to decode string without rotation cypher//
char rotation_decrypt(char *string, const unsigned int string_length);
*/

//FUNCTIONS FOR SUBSTITUTION CYPHER
 
//function to encode string with substitution cypher//
//this function requires a string, the length of the string as an unsigned integer and
// a 26 letter string for a substitution key
//this function will return a value of type char
char substitution_encode(char *string, const unsigned int string_length, char *substitution_key);
 
//function to decode string with substitution cypher//
//this function requires a string, the length of the string as an unsigned integer and
// a 26 letter string for a substitution key
//this function will return a value of type char
char substitution_decode(char *string, const unsigned int string_length, char *substitution_key);

/*TODO*/
//function to decode string without substitution cypher//
//this function will return a value of type char
//this function requires a string and the length of the string as an unsigned integer
char substitution_decrypt(char *string, const unsigned int string_length);



//FUNCTION TO WRITE TO OUTPUT
//this function requires a FILE, a string and the length of the string as an unsigned integer
//this function will return a value of type char
char append_OUTPUT(FILE *OUTPUT, char *string, const unsigned int string_length );




//**************************************************//
 
                //START OF MAIN CODE//

 
int main() {
    
    //DECLARE FILES//
    
    //declare INPUT as a FILE//
    FILE *INPUT;
    
    //open INPUT as read only
    INPUT = fopen("INPUT","r");
    
    //if could not open INPUT, print error
    if ( INPUT == NULL ) {
        perror("fopen()");
    }
    
    
    //declare INPUT_KEY as a FILE//
    FILE *INPUT_KEY;
    
    //open INPUT_KEY as read only
    INPUT_KEY = fopen("INPUT_KEY","r");
    
    //if could not open INPUT, print error
    if ( INPUT_KEY == NULL ) {
        perror("fopen()");
    }
    
    
    //declare OUTPUT as a FILE
    FILE *OUTPUT;
    
    //open OUTPUT as append (write to end of file)
    OUTPUT = fopen("OUTPUT","a");
    
    //if could not open INPUT, print error
    if ( OUTPUT == NULL ) {
        perror("fopen()");
    }
    
    
    //declare rotation_key as an integer of value 0
    int rotation_key = 0;
    
    //declare substitution_key as an array of type char
    char substitution_key[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    
    //declare cypher_type as a char
    // with the value of the return of the function read_encryption_key
    char cypher_type = read_encryption_key(INPUT_KEY, &rotation_key, substitution_key);
    
    //read value for cypher key from INPUT, if sucessful print encryption key to terminal   
    //switch case based on the return value of the cypher key type
    switch ( cypher_type ) {
        case 1:  
            printf("ROTATION_KEY: %d\n", rotation_key);
            break;
        case 2:
            printf("SUBSTITUTION_KEY: %s\n", substitution_key);
            break;
        case 0:
            printf("CASE: DECRYPT\n");
            break;
        default:
            printf("ERROR: CYPHER_TYPE\n");
            return 0;
    }
    
    
    
    //unused// char string[1024] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    
    //declare string_IN, string and string_OUT as arrays of type char each 1024 characters long
    char string_IN[1024];
    char string[1024];
    char string_OUT[1024];
    
    //declare string_length as an unsigned integer with the value 1024
    unsigned int string_length = 1024;
    
    
    //read string from INPUT
    read_string(INPUT, string_IN, string_length);
    
    //get length of string_IN
    string_length = strlen(string_IN);
    
    //print the length of string_IN to the terminal
    printf("STRING_LENGTH: %d\n", string_length);
    
    //convert all letters in string_IN to capitals
    check_all_caps(string_IN, string_length);
    
    //duplicate string_IN across to string and string_OUT
    for ( int n = 0 ; n < string_length ; n++ ) {
        string[n] = string_IN[n];
        string_OUT[n] = string_IN[n];
    }
    
    
    //switch case dependng on if the cypher key is a rotation or substitution -type key or if it was not found
    switch (cypher_type) {
        //TODO// if () {;} else if () {;}
        case 1:  //if rotation-type cypher key//
            //if ( encoded == 0 ) {
                fprintf(OUTPUT,"ROTATION_ENCODE:\n");  //print "ROTATION_ENCODE:" and "\n", a new line character, to OUTPUT
                //encrypt with rotation cypher
                rotation_encode(string, string_length, rotation_key);
                append_OUTPUT(OUTPUT, string, string_length);
                fprintf(OUTPUT,"\n");  //print a new line character to OUTPUT
            //}
            //else if ( encoded == 1 ) {
                fprintf(OUTPUT,"ROATION_DECODE:\n");  //print "ROTATION_DECODE:" and a new line character to OUTPUT
                //decrypt with rotation cypher
                rotation_decode(string_OUT, string_length, rotation_key);
                append_OUTPUT(OUTPUT, string_OUT, string_length);
                fprintf(OUTPUT,"\n\n");
            //}
            break;
        case 2:  //if substitution-type cypher key
            //if ( encoded == 0 ) {
                fprintf(OUTPUT,"SUBSTITUTION_ENCODE:\n");
                substitution_encode(string, string_length, substitution_key);
                append_OUTPUT(OUTPUT, string, string_length);
                fprintf(OUTPUT,"\n");
            //}
            //else if ( encoded == 1 ) {
                substitution_decode(string, string_length, substitution_key);
                append_OUTPUT(OUTPUT, string, string_length);
                fprintf(OUTPUT,"\n");
                
                fprintf(OUTPUT,"SUBSTITUTION_DECODE:\n");
                substitution_decode(string_OUT, string_length, substitution_key);
                append_OUTPUT(OUTPUT, string_OUT, string_length);
                fprintf(OUTPUT,"\n\n");
            //}
            break;
        case 0:  //if cypher key not found
            printf("ERROR: CYPHER_NOT_FOUND\n");
            printf("ATTEMPTING DECRYPTION...\n");
            fprintf(OUTPUT,"\nERROR: CYPHER_NOT_FOUND\n");
            fprintf(OUTPUT,"ATTEMPTING DECRYPTION\n");
            fprintf(OUTPUT,"\n");
            //brute force decryption of rotation cypher
            for ( int count = 1 ; count < 26 ; count++ ) {
                rotation_key = count;
                rotation_decode(string_OUT, string_length, rotation_key);
                append_OUTPUT(OUTPUT, string_OUT, string_length);
                fprintf(OUTPUT,"\n");
            }
            fprintf(OUTPUT,"\n");
            //printf("CASE_0: DECRYPT\n");
            //TODO// decrypt(string, string_length, &rotation_key, substitution_key);
            break;
    }
    
    
    return 0; 
}
//************************************************//

                //END OF MAIN CODE//

//************************************************//


//read encryption key from INPUT
char read_encryption_key(FILE *INPUT_KEY, int *rotation_key, char *substitution_key) {
    
    int read = 0;
    char rtn = 0;
    unsigned int count = 0;
    
    rewind(INPUT_KEY);
/*    while( ( fscanf(INPUT,"#KEY: %d", rotation_key ) == 0 ) && ( count < 100 ) ) {
        count++;  //TODO increment readfrom pos
        }
    
    if ( count < 100 ) {
        rewind(INPUT);
        while( (fscanf(INPUT, "#KEY: %s", substitution_key) == 0 ) && ( count < 100 ) ) {
            count++;  //TODO increment readfrom pos
        }
    }
    */
    if ( read != 0 ) {
        rtn = 1;
    }
     else {
        for ( count = 0 ; count < 100 ; count++ ) {            //if rotation key
            read = fscanf(INPUT_KEY,"#KEY: %d[\n]", rotation_key);
            if ( read != 0 ) {
                rtn = 1;
                //printf("ROT\n");  //testing
                break;
            }
        }
    }
    
    if (rtn == 0 ) {
        rewind(INPUT_KEY);  //return curser to start of file
        
        for ( count = 0 ; count < 100 ; count++ ) {
            if ( fscanf(INPUT_KEY,"#KEY: %s[\n]", substitution_key) != 0 ) {
                if ( 1 ) {  //TODO error check substitution key///////////////////////// //TODO//
                    read = 2;
                }
                break;
            }
        }

        int sub1 = substitution_key[0];
        if ( ( read == 2 ) && ( sub1 != '/' ) ) {  //if substitution key
            rtn = 2;
        }
         else if ( read == 2 ) {
            rtn = 0;
        }
    }
    rewind(INPUT_KEY);  //return curser to start of file
    return rtn;  //if no valid key
}


//function to read string from INPUT 
unsigned int read_string(FILE *INPUT, char *string, unsigned int string_length) {
    
    unsigned int count = 0;  //initiate integer for counting loops
    unsigned int count_2 = 0; //initiate second integer for counting loops
    unsigned int rtn = 0; //initiate variable to hold value for return
    int scan = 0;
    
//    char str[1024];
    
    rewind(INPUT);
    
    for ( count = 0 ; scan == 0 && count < string_length ; count++ ) {
        scan = fscanf(INPUT,"#INPUT: %c", &string[0]);
        
    }
    if ( scan != 0 ) {
        for ( count_2 = 1 ; count < string_length ; count++ ) {
            fscanf(INPUT,"%c", &string[count]);
            count_2++;
            if ( ( string[count] == 10 ) || ( string[count]  == 12 ) || ( string[count] == 13 ) ) {
                string[count] = 0;
                break;
            }
        }
    }
    
    
    
    return rtn;
}


//function to convert string to all caps
char check_all_caps(char *string, const unsigned int string_length) {
    //while n is less than the number of characters in string do following then increase n by one then repeat
    for ( int n = 0 ; n < string_length ; n++ ) {
        
        //if the character at n is lowercase, convert to uppercase
        if ( string[n] >= 97 && string[n] <= 122 ) {
            string[n] -= 32;
        }      
    }

    return 1;
}


//functon to encode string with rotation cypher//
char rotation_encode(char *string, const unsigned int string_length, int rotation_key) {
    int rotation = ( 26 + rotation_key ) % 26;
    
    for ( int n = 0 ; n < string_length ; n++ ) {
        if ( string[n] >= 65 && string[n] <= 90 ) {
            string[n] += rotation ;
            if ( string[n] > 90 ) {
                string[n] -= 26;
            }
            else if ( string[n] < 65 ) {
                string[n] += 26;
            }
        }
    }    
    for ( int n = 0 ; n < string_length ; n++ ) {
            printf(" '");
            printf("%c",string[n]);
            printf("' ");
    }
    printf("\n");
    return 1;
}



//function to decode string with rotation cypher//
char rotation_decode(char *string, const unsigned int string_length, int rotation_key) {
    int rotation = ( 26 - rotation_key ) % 26;
    
    for ( int n = 0 ; n < string_length ; n++ ) {
        if ( string[n] >= 65 && string[n] <= 90 ) {
            string[n] += rotation ;
            if ( string[n] > 90 ) {
                string[n] -= 26;
            }
            else if ( string[n] < 65 ) {
                string[n] += 26;
            }
        }
    }    
    for ( int n = 0 ; n < string_length ; n++ ) {
            printf(" '");
            printf("%c",string[n]);
            printf("' ");
    }
    printf("\n");
    return 1;
}



//FUNCTIONS FOR SUBSTITUTION CYPHER

//function to encode string with substitution cypher
char substitution_encode(char *string, const unsigned int string_length, char *substitution_key) {
    
    for ( int n = 0 ; n < string_length ; n++ ) {        //for each character in string
        if ( string[n] >= 65 && string[n] <= 90 ) {      //if it is a capital
            string[n] = substitution_key[(string[n] - 65)];
        }
    }
    for ( int n = 0 ; n < string_length ; n++ ) {
            printf(" '");
            printf("%c",string[n]);
            printf("' ");
    }
    printf("\n");
    return 1;
}

//function to decode string with substitution cypher
char substitution_decode(char *string, const unsigned int string_length, char *substitution_key) {
    const char A_to_Z[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    
    for ( int n = 0 ; n < string_length ; n++ ) {        //for each character in string
        if ( string[n] >= 65 && string[n] <= 90 ) {      //if it is a capital
            for ( int i = 0 ; i < 26 ; i++ ) {           //...
                if ( string[n] == substitution_key[i] ) {  //work out what number of the alphabet it is
                    string[n] = A_to_Z[i];     //and substitute the character at the same place in the key
                }
            }
        }
    }
    for ( int n = 0 ; n < string_length ; n++ ) {
            printf(" '");
            printf("%c",string[n]);
            printf("' ");
    }
    printf("\n");
    return 1;    
}

/*
//FUNCTIONS TO DECRYPT WITHOUT KEY
char roatation_decrypt(string, const unsigned int string_length, *rotation_key) { ;}
char substitution_decrypt(string, const unsigned int string_length, *substitution_key) { ;}
*/

//FUNCTION TO WRITE TO OUTPUT
char append_OUTPUT(FILE *OUTPUT, char *string, const unsigned int string_length ) {
    
    for ( int n = 0 ; n < string_length ; n++ ) {
            fprintf(OUTPUT,"%c",string[n]);
    }
    fprintf(OUTPUT, "\n");
    
    return 2;
}

//END//