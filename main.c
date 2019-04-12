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
    int *pointer_rotation_cypher = &rotation_cypher;
    
    //declare array to hold substitution cypher
    char substitution_cypher[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    
    
    //read value for cypher form INPUT, if sucessful print encryption key to terminal //TODO// and set function type    
    char cypher_type = 0;
    
    switch ( read_encryption_key(&rotation_cypher, substitution_cypher) ) {
        case 1:
            printf("ROTATION_KEY: %d\n", rotation_cypher);
            cypher_type = 1;
            break;
        case 2:
            printf("SUBSTITUTION_KEY: %s\n", substitution_cypher);
            cypher_type = 2;
            break;
        case 0:
            printf("CASE: DECRYPT\n");
            break;
    }
    if ( cypher_type != 0 ) {
        printf("CYPHER_TYPE: %d\n", cypher_type);
    }

    
    //declare string //unused// as an array of characters 
    char string[] = "TVU TVAOTH: AOL KHAH IYVBNOA AV BZ IF AOL IVAOHU ZWPLZ WPUWVPUAZ AOL LEHJA SVJHAPVU VM AOL LTWLYVY'Z ULD IHAASL ZAHAPVU. DL HSZV RUVD AOHA AOL DLHWVU ZFZALTZ VM AOPZ KLHAO ZAHY HYL UVA FLA VWLYHAPVUHS. DPAO AOL PTWLYPHS MSLLA ZWYLHK AOYVBNOVBA AOL NHSHEF PU H CHPU LMMVYA AV LUNHNL BZ, PA PZ YLSHAPCLSF BUWYVALJALK. IBA TVZA PTWVYAHUA VM HSS, DL'CL SLHYULK AOHA AOL LTWLYVY OPTZLSM PZ WLYZVUHSSF VCLYZLLPUN AOL MPUHS ZAHNLZ VM AOL JVUZAYBJAPVU VM AOPZ KLHAO ZAHY. THUF IVAOHUZ KPLK AV IYPUN BZ AOPZ PUMVYTHAPVU.";
//    char string[1024];  //unused// = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};

    
    //get number of characters in string 
    unsigned int string_length = strlen(string);

    //read string from INPUT
//    read_string(string, string_length);
    
    printf("STRING_LENGTH: %d\n", string_length);
    
    printf("#STRING: \n");
    for ( int i = 0 ; i < string_length ; i++ ) {
        printf("%c", string[i]);
    }
    printf("\n#END\n");

    
/*
    //convert to //convert string to all caps 
    check_all_caps(string, string_length);
    
    
    //verify string is valid (A,B,C,... )
*/
    
    int stringN[1024];
    
    //convert each character in string from ASCII to a number from 1 to 25
    convert_from_ASCII(string, string_length, stringN);
    
    switch (cypher_type) {
        case 1:
            //encrypt with rotation cypher
            rotation_cypher(string, string_length, rotation_cypher);
            break;
        case 2:
            //encrypt with substitution cypher
            substitution_cypher(string, string_lenght, substitution_cypher);
            break;
        case 0:
            //decript without cypher
            decrypt(string, string_length);
            break;
    }
    
    
    //convert each character in string from a number from 0 to 25 to ASCII
    convert_to_ASCII(string, string_length, stringN);
    
    
    //print cypher key and encrypted string to OUTPUT
//    printf("Key is: %d\n", rotation_cypher);
     
//    printf("The length of the string is: %d\n", string_length);
     
    printf("THE_STRING_IS:\n%s\n", string);
     
    return 0; 
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
    char rtn = 0;
    unsigned int count = 0;
    
    read = fscanf(INPUT,"#KEY: %d\n", rotation_cypher);
    
    if ( read != 0 ) {
        rtn = 1;
    }
     else {
        for ( count = 0 ; count < 100 ; count++ ) {            //if rotation key
            read = fscanf(INPUT,"#KEY: %d[\n]", rotation_cypher);
            if ( read != 0 ) {
                rtn = 1;
                printf("ROT\n");
                break;
            }
        }
    }

    
    if (rtn == 0 ) {
        rewind(INPUT);  //return curser to start of file
        
        for ( count = 0 ; count < 100 ; count++ ) {
            if ( fscanf(INPUT,"#KEY: %s[\n]", substitution_cypher) != 0 ) {
                read = 2;
                printf("SUB\n");
                break;
            }
        }

        int sub1 = substitution_cypher[0];
        /*int subL = substitution_cypher[25];*/
        if ( ( read == 2 ) && ( sub1 != '#' ) /*&& ( subL == 0 )*/ ) {  //if substitution key
            rtn = 2;
        }
         else if ( read == 2 ) {
            rtn = 0;
        }
    }
    rewind(INPUT);  //return curser to start of file
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
    
    int count = 0;  //initiate integer for counting loops
    unsigned int rtn = 0; //initiate variable to hold value for return
    int scan = 0;
    
//    char str[1024];
    
    rewind(INPUT);
    
    //for ( count = 0 ; count < 100 ; count++ ) {
    scan = fscanf(INPUT,"#INPUT: %s", string);
    while ( ( scan == 0 ) && count < 100 ) {
        scan = fscanf(INPUT,"#INPUT: %s", string);
        count++;
    }

  //  }
    
    printf("TEST_COUNT: %d\n",count);
    
    /*
    for ( count = 0 ; string[count] != '#' ; count++) {  //until end of file reached 
               
        fscanf(INPUT,"%c", &string[count]);
        
        string[count+1] = 0;
        
        count++;
    }
    */
    clearerr(INPUT);
    
    printf("STRING_IS: %s\n", string);
    
    return rtn;
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
            stringN[n] -= 65;
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

//function to determine if encode or decode
char rotation_cypher(char *string, unsigned int string_length, int rotation_cypher)
{
    //if encode return case 1;
    //if decode return case 2;
    //if ERROR return case 0;
    return 0;
}

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


/*
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
*/




