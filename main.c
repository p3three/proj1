#include <stdio.h>
 
#include <string.h>

//for isspace// #include <ctype.h>

 
 
//FUNCTIONS TO READ FROM INPUT/

 
//read encryption key from INPUT 
char read_encryption_key(int *rotation_key, char *substitution_key);

/*unused
//read encryption key from terminal
char read_encryption_key_terminal;
*/
 
//read string from INPUT 
unsigned int read_string(char *string, unsigned int string_length);

//FUNCTIONS TO WRITE TO OUTPUT// 
//TODO//


//function to convert string to all caps// 
char check_all_caps(char *string, const unsigned int string_length);

 

//FUNCTION TO DECRYPT WITHOUT KEY
char decrypt(char *string, const unsigned int string_length, int *rotation_key, char *substitution_key);

//FUNCTIONS FOR ROTATION CYPHER//

 
//functon to encode string with rotation cypher//
char rotation_encode(char *string, const unsigned int string_length, int rotation_key);


//function to decode string with rotation cypher// 
char rotation_decode(char *string, const unsigned int string_length, int rotation_key);

 
//function to decode string without rotation cypher// 
char rotation_decrypt(char *string, const unsigned int string_length);


//FUNCTIONS FOR SUBSTITUTION CYPHER

 
//function to encode string with substitution cypher// 
char substitution_encode(char *string, const unsigned int string_length, char *substitution_key);

 
//function to decode string with substitution cypher//
char substitution_decode(char *string, const unsigned int string_length, char *substitution_key);


//function to decode string without substitution cypher// 
char substitution_decrypt(char *string, const unsigned int string_length);





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
    
    
    
    //declare rotation_key as an integer
    int rotation_key = 0;
    
    //declare array to hold substitution cypher
    char substitution_key[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    
    
    //read value for cypher form INPUT, if sucessful print encryption key to terminal //TODO// and set function type    
    char cypher_type = 0;
    
    switch ( read_encryption_key(&rotation_key, substitution_key) ) {
        case 1:
            printf("ROTATION_KEY: %d\n", rotation_key);
            cypher_type = 1;
            break;
        case 2:
            printf("SUBSTITUTION_KEY");
            check_all_caps(substitution_key, strlen(substitution_key));
            printf("SUBSTITUTION_KEY: %s\n", substitution_key);
            cypher_type = 2;
            break;
        case 0:
            printf("CASE: DECRYPT\n");
            cypher_type = 0;
            break;
    }
    if ( cypher_type != 0 ) {
        printf("CYPHER_TYPE: %d\n", cypher_type);
    }
    
    
    
    char string[1024];
    unsigned int string_length = 1024;
    /*  //unused//
    char string[1024] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    */
    
    //read string from INPUT
    read_string(string, string_length);
    
    
    //get number of characters in string 
    string_length = strlen(string);
    
    printf("STRING_LENGTH: %d\n", string_length);
    
    
    printf("STRING_");  //to print "STRING_ALL_CAPS " and then string
    
    //to convert string to all caps 
    check_all_caps(string, string_length);

    
    switch (cypher_type) {
        case 1:
            //TODO// if ( encoded == FALSE ) {
            printf("CASE_1: ROTATION_ENCODE\n");
            //encrypt with rotation cypher
            rotation_encode(string, string_length, rotation_key);
            break;
        case 2:
            //TODO//if ( encoded == FALSE ) {
            printf("CASE_2: SUBSTITUTION_ENCODE\n");
            substitution_encode(string, string_length, substitution_key);
           break;
        case 0:
            //TODO//if ( encoded == FASLE ) {
            printf("ERROR: ENCODE: CYPHER_NOT_FOUND\n");
           break;
    }
    
    switch (cypher_type) {
        case 1:
            //TODO//if ( encoded == TRUE ) {
            printf("CASE_1: ROATION_DECODE\n");
            rotation_decode(string, string_length, rotation_key);
            break;
        case 2:
            //TODO//if ( encoded == TRUE ) {
            printf("CASE_2: SUBSTITUTION_DECODE\n");
            substitution_decode(string, string_length, substitution_key);
            break;
        default:
            //TODO//if ( encoded == TRUE ) {
            printf("CASE_0: DECRYPT\n");
            //TODO// decrypt(string, string_length, &rotation_key, substitution_key);
            break;
        
    }
    
    
    //print cypher key and encrypted string to OUTPUT
//    printf("Key is: %d\n", rotation_key);
     
//    printf("The length of the string is: %d\n", string_length);
    
    printf("\n");
    printf("ROTATION_KEY: %d\n", rotation_key);
    printf("SUBSTITUTION_KEY: %s\n", substitution_key);
    
    printf("\n");
    printf("THE_STRING_IS: ");
    for ( int n = 0 ; n < string_length ; n++ ) {
        printf("%c", string[n]);
    }
    printf("\n");

     
    return 0; 
}
//************************************************//

                //END OF MAIN CODE//

//************************************************//


//read encryption key from INPUT
char read_encryption_key(int *rotation_key, char *substitution_key) {
    
    //declare FILE INPUT
    FILE *INPUT_KEY;
 
    INPUT_KEY = fopen("INPUT_KEY","r");

    if ( INPUT_KEY == NULL ) {
        perror("fopen()");
    }
    
    int read = 0;
    char rtn = 0;
    unsigned int count = 0;
    
    //read = fscanf(INPUT,"#KEY: %d\n", rotation_key);  //TODO ?convert to 
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
                //printf("SUB\n");  //testing
                break;
            }
        }

        int sub1 = substitution_key[0];
        /*int subL = substitution_key[25];*/
        if ( ( read == 2 ) && ( sub1 != '#' ) /*&& ( subL == 0 )*/ ) {  //if substitution key
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
unsigned int read_string(char *string, unsigned int string_length) 
{
    FILE *INPUT;
    
    INPUT = fopen("INPUT","r");
    
    if ( INPUT == NULL ) {
        perror("fopen()");
    }
    
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
                break;
            }
        }
    }

    
    
    printf("INPUT: TEST_COUNT: %d\n",count_2);
    
    /*
    for ( count = 0 ; string[count] != '#' ; count++) {  //until end of file reached 
               
        fscanf(INPUT,"%c", &string[count]);
        
        string[count+1] = 0;
        
        count++;
    }
    */
   
    //string_length = strlen(string);
    
    printf("THE_STRING_IS: ");
    for ( int n = 0 ; n < count ; n++ ) {
        printf("%c", string[n]);
    }
    printf("\n");
    
    return rtn;
}


//function to convert string to all caps
char check_all_caps(char *string, const unsigned int string_length)
{
    //while n is less than the number of characters in string do following then increase n by one then repeat
    for ( int n = 0 ; n < string_length ; n++ ) {
        
        //if the character at n is lowercase, convert to uppercase
        if ( string[n] >= 97 && string[n] <= 122 ) {
            string[n] -= 32;
        }      
    }
    printf("ALL_CAPS:\n");
    for ( int n = 0 ; n < string_length ; n++ ) {
        printf(" '");
        printf("%c", string[n]);
        printf("' ");
    }
    printf("\n");
    return 1;
}


//FUNCTIONS FOR ROTATION CYPHER//

//function to determine if encode or decode
char rotation_cypher(char *string, const unsigned int string_length, int rotation_key)
{
    //if encode return case 1;
    //if decode return case 2;
    //if ERROR return case 0;
    return 0;
}

//functon to encode string with rotation cypher//
char rotation_encode(char *string, const unsigned int string_length, int rotation_key)
{
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
char rotation_decode(char *string, const unsigned int string_length, int rotation_key)
{
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
            /*for ( int i = 0 ; i < 26 ; i++ ) {           //...
                if ( string[n] == alphabet_0to25[i] ) {  //work out what number of the alphabet it is
                    string[n] = substitution_key[i];     //and substitute the character at the same place in the key
                }
            }*/
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
            //string[n] = substitution_key[(string[n] - 65)];
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
//function to decode string without substitution cypher
char substitution_decrypt(char *string, const unsigned int string_length);


//FUNCTIONS TO DECRYPT WITHOUT KEY
char roatation_decrypt(string, const unsigned int string_length, *rotation_key) { ;}

char substitution_cypher(string, const unsigned int string_length, *substitution_key) { ;}

*/