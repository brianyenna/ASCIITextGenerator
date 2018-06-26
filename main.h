#define MAXCHAR 300 //max num of characters that can be stored per ASCII character
#define MAXLINELENGTH 500 // max num of characters that can be fit into a horizontal display per line
#define MAXHEIGHT 6 //max num of \n you can have for each ASCII character (i.e the number of lines the character occupies)
#define VOCABSIZE 26+26+1 //26 lower-case alphabets; 26 upper-case alphabets; 1 space char
#define FILENAME "ascii_database.bin"

typedef struct ascii_store_struct{
	char store[MAXCHAR];
	int user_defined_bool; //set to 1 if the user has defined the ascii chars, else set to 0
} ascii_store;

typedef struct horizontal_display{
	char line1[MAXLINELENGTH];
	char line2[MAXLINELENGTH];
	char line3[MAXLINELENGTH];
	char line4[MAXLINELENGTH];
	char line5[MAXLINELENGTH];	
	char line6[MAXLINELENGTH];
} h_disp;

//Function declarations
void set_default_ascii(char store[]);
int map_char_to_array_index(char c);
int decide_which_char();
void get_ascii(char store[]);
void add_record();
void save_ascii_records(char* filename);
void display_char();
void load_ascii_database(char* filename);
void use_typeface();
void find_undefined_alpha();

void safe_makefile(char* filename);
void str_append(char s[], char c);