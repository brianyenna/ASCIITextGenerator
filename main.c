#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

// External Variables
ascii_store ascii_collection[VOCABSIZE];
ascii_store default_ascii;

void set_default_ascii(char store[]){
	int i,j;

	store[0] = '\0';
	for (i=0; i<MAXHEIGHT; i++){
		for (j=0; j<5; j++){
			str_append(store, ' ');
		}
		str_append(store, '\n');
	}
}

int map_char_to_array_index(char a){
	int i;

	if (a == ' '){
		i = VOCABSIZE-1;
		return i;
	} else if (isalpha(a)){
		if (isupper(a)){
			i = a - 'A' + 26;
			return i;
		}
		if (islower(a)){
			i = a - 'a';
			return i;
		}
	} else { //This section is actually never called. DEBUGGING
		printf("Invalid character {%c} entered. Must be an alphabet or the space char.", a);
		return -1;
	}
}

int decide_which_char(){
	/* Purpose: returns i, which is the index position of the char in ascii_collection;
				will check if the character is an alphabet, else it returns -1 */
	char c;
	int i; 
	
	printf("Please enter the character:\n>>>");
	getchar(); //Gets rid of the \n char
	c = getchar();
	
	if (!(isalpha(c)||c==' ')){
		printf("The character you entered is not an alphabet or the space char. Please try again.");
		return -1;
	}
	
	i = map_char_to_array_index(c);
	return i;
}

void get_ascii(char store[]){
	/*Purpose: Reads the user's ASCII definition of an alphabet or number from the command line.
	 * 		   The \n character is read in and saved in the store[] char array as well. However,
	 * 		   previous_carriage_return will keep track of whether or not a \n immediately follows
	 * 		   a \n, in which case, the program will stop reading from the command line. In other
	 * 		   words, two successive carriage returns will cause the reading from the command line
	 * 		   the stop. */
	
	int previous_carriage_return = 0;
	int height_counter = 0;
	int condition = 1;
	int starting_whitespace = 1;
	int index = 0;
	char c, d;
	
	printf("Please enter the typeface design. Use carriage return to get to the next line.\n");

	while(condition){
		if (starting_whitespace){
			d = getchar();
			while (d == '\n'){
				d = getchar();
			}
			starting_whitespace = 0;
			store[index++] = d;
		} else {
			c = getchar();
			if(!previous_carriage_return){
				if(c=='\n'){
					previous_carriage_return = 1;
					height_counter++;
				}
				store[index++] = c;
			} else {
				if(c=='\n'){
					condition = 0;
				} else {
					previous_carriage_return = 0;
					store[index++] = c;
				}
			}
		}
	}

	if (height_counter != MAXHEIGHT){
		printf("Your input typeface is not %d lines high. This is invalid. Please re-enter your design.", MAXHEIGHT);
		set_default_ascii(store);
	}
}

void add_record(){
	int i;
	printf("Which character's typeface would you like to add a record for? ");
	i = decide_which_char();
	if (i == -1){
		;
	} else {
		get_ascii(ascii_collection[i].store);
		ascii_collection[i].user_defined_bool = 1;
	}
}

void save_ascii_records(char* filename){
	FILE* file;
	int i;

	file = fopen(filename, "wb");
	if (file==0){
		printf("Cannot open file: %s\n", FILENAME);
	} else{
		for (i=0; i<VOCABSIZE; i++){
			if (ascii_collection[i].user_defined_bool){
				fwrite(&ascii_collection[i], sizeof(ascii_store), 1, file);
			} else {
				fwrite(&default_ascii, sizeof(ascii_store), 1, file);
			}
		}
	}

	fclose(file);
	
	// Gets rid of trailing characters in STDIN
	char c;
	while ((c=getchar()) != '\n'){
		;
	}
}

void display_char(){
	int i;
	char c;
	
	printf("Which character's typeface would you like to display? ");
	i = decide_which_char();
	printf("%s", ascii_collection[i].store);
	getchar(); //Gets rid of \n character. DEBUGGING REQUIRED. 
}

void safe_makefile(char* filename){
	FILE* file;
	
	file = fopen(filename, "ab");
	fclose(file);
}

void load_ascii_database(char* filename){
	FILE* file;
	int numrecsread;
	
	file = fopen(FILENAME, "rb");
	if (file==0){
		printf("Cannot read file: %s\n", filename);
	} else{
		numrecsread = fread(ascii_collection, sizeof(ascii_store), VOCABSIZE, file);
	}

	if (numrecsread != VOCABSIZE){
		printf("Error: %d records were read into memory, but there ought to be %d records in total", numrecsread, VOCABSIZE);
	}

	// Gets rid of any trailing characters in STDIN
	char c;
	while ((c=getchar()) != '\n'){
		;
	}

}

void use_typeface(){
	char c;
	char array[MAXCHAR];
	int i = 0;
	int j, k, l;
	int condition = 1;
	int display_boolean = 1;
	
	// Initialize h_disp
	h_disp disp_array;
	disp_array.line1[0] = '\0';
	disp_array.line2[0] = '\0';
	disp_array.line3[0] = '\0';
	disp_array.line4[0] = '\0';
	disp_array.line5[0] = '\0';
	disp_array.line6[0] = '\0';

	printf("Please enter a sentence. This will be converted to the defined ASCII typeface:\n>>>");
	getchar(); //Gets rid of the \n character. DEBUGGING REQUIRED. 
	while (condition){
		c = getchar();
		// if (c=='\n'||c==EOF){
		// 	condition = 0;
		// }

		if (isalpha(c)||c==' '){
			array[i++] = c;
		} else if (c=='\n'){
			condition = 0;
		} else {
			printf("Invalid input. Only alphabets allowed.");
			display_boolean = 0;
		}
	}

	// if (display_boolean){
	// 	for (j=0; isalpha(array[j]); j++){ 
	// 		k = map_char_to_array_index(array[j]);
	// 		printf("%s", ascii_collection[k].store);
	// 	} 
	// } //For vertical display

	if (display_boolean) {
		for (j=0; j<i; j++){
			k = map_char_to_array_index(array[j]);
			//Not very intelligent code here. Manually copy and paste. DEBUGGING REQUIRED.
			for (l=0; ascii_collection[k].store[l] != '\n'; l++){
				str_append(disp_array.line1, ascii_collection[k].store[l]);
			}
			for (l++; ascii_collection[k].store[l] != '\n'; l++){
				str_append(disp_array.line2, ascii_collection[k].store[l]);
			}
			for (l++; ascii_collection[k].store[l] != '\n'; l++){
				str_append(disp_array.line3, ascii_collection[k].store[l]);
			}
			for (l++; ascii_collection[k].store[l] != '\n'; l++){
				str_append(disp_array.line4, ascii_collection[k].store[l]);
			}
			for (l++; ascii_collection[k].store[l] != '\n'; l++){
				str_append(disp_array.line5, ascii_collection[k].store[l]);
			}
			for (l++; ascii_collection[k].store[l] != '\n'; l++){
				str_append(disp_array.line6, ascii_collection[k].store[l]);
			}
		}
		printf("%s\n", disp_array.line1);
		printf("%s\n", disp_array.line2);
		printf("%s\n", disp_array.line3);
		printf("%s\n", disp_array.line4);
		printf("%s\n", disp_array.line5);
		printf("%s\n", disp_array.line6);
	}

}

void str_append(char s[], char c){
	int len = strlen(s);
	s[len] = c;
	s[len+1] = '\0';
}

void find_undefined_alpha(){
	int i;
	int num_undefined = 0;
	char c;
	char undefined_alpha[VOCABSIZE];

	undefined_alpha[0] = '\0';

	for (i=0; i<VOCABSIZE; i++){
		if (!ascii_collection[i].user_defined_bool){
			if (i<=25){
				c = 'a' + i;
				num_undefined++;
				str_append(undefined_alpha, c);
			} else {
				c = 'A' + i - 26;
				num_undefined++;
				str_append(undefined_alpha, c);
			}
		}
	}
	if (num_undefined){
		printf("The following characters still do not have custom typefaces defined for them:\n");
		printf("%s\n", undefined_alpha);
	} else {
		printf("All characters already have a custom typeface defined for them.\n");
	}

	// Gets rid of any trailing characters in STDIN
	while ((c=getchar()) != '\n'){
		;
	}
}




int main(){
	int keepgoing = 1;
	safe_makefile(FILENAME);
	set_default_ascii(default_ascii.store);
	
	while (keepgoing){
		printf("\nEnter a command");
		printf("\n'l' = re(load) existing records,");
		printf("\n'a' = add record to database,");
		printf("\n'u' = generate ASCII art for word");
		printf("\n'd' = display a single character,");
		printf("\n'f' = find undefined characters,");
		printf("\n's' = save records to database,");
		printf("\n'q' = quit program");
		printf("\n>>> ");
		// printf("\nCommands:  'l' = (re)load existing records, a' = add record, 'u' = use typeface");
		// printf("\n           'd' = display character, 'f' = find undefined characters");
		// printf("\n           's' = save records, 'q' = quit program\n>>>");
		
		switch(tolower(getchar())){
			case 'l':
				printf("Loading existing records\n");
				load_ascii_database(FILENAME);
				break;
			case 'f':
				find_undefined_alpha();
				break;
			case 'a':
				printf("Add record\n");
				add_record();
				break;
			case 'd':
				display_char();
				break;
			case 'q':
				printf("Exiting program now\n");
				keepgoing = 0;
				break;
			case 's':
				printf("Saving records made thus far\n");
				save_ascii_records(FILENAME);
				break;
			case 'u':
				printf("Using typface\n");
				use_typeface();
				break;
			case '\n':
				break;
			default:
				printf("Invalid command\n");
				break;
		}
		
	}
	
	return 0;
}
