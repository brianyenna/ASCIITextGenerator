# ASCII Text Generator
This bit of code can generate ASCII wordart. The default typeface provided is 'Graffiti' from http://patorjk.com/software/taag/. Users can also define their own typefaces using the command-line interface. 

## Basic Information
- All ASCII characters loaded into the program's database must be MAXHEIGHT lines high. This is to ensure consistency in the typeface.
- Only alphabets (both upper and lower-case) can be generated using this program (along with the space character). Special characters are not supported yet.
- Should any alphabet's typeface not be added to the database, the default value will be a (MAXHEIGHT x 5) block of `space` characters.
- The database refers to a file that is automatically generated when the code is first run, named `ascii_database.bin`. You can simply replace this file with another user-defined database to immediately obtain the typeface of your choice. 
- A more interesting use case: instead of specifying a typeface for each character, the user can instead associate each characer (both upper and lower case characters) with any type of ASCII art they design (as long as it is within MAXCHAR). Some pre-defined databases have been created under the ./DefinedDatabases directory. Anyone can try out the databases there. You can either copy over the database to the root directory and rename the file as `ascii_database.bin`, or you can change the `FILENAME` symbolic constant to the file name path. 

## Instructions for use:
**IMPORTANT NOTE:**  ALWAYS load the database first, even if its empty. Should an existing database already be defined, and you press `'s'`, the ENTIRE database will be overwritten, so all tyepfaces will be lost.

1. Compile and run `main.c`
2. Should you already have a pre-defined `ascii_database.bin` file (the one provided on GitHub has the Graffiti typeface pre-loaded and can be used), simply type `'l'` to load the existing database. 
3. Should you wish to manually define/overwrite an existing typeface, simply type `'a'` to add a record. Specify which character you are defining the typeface for. Note that this code distinguishes between upper and lower case characters, and is therefore case-sensitive. 
4. After defining your own typefaces, remember to type `'s'` on the command-line to save your changes to the `ascii_database.bin` file. Type `'l'` to re-load the database. 
5. Type `'u'` to use the typeface defined in `ascii_database.bin`. Type a word and hit enter. The ASCII word art will be generated on the command-line. 
6. Should you wish to examine an individual character in the database, type `'d'` and specify which character you are interested in viewing. This might be useful for checking if the character was defined in the first place (if undefined, it will default to a block of (space) characters). Alternatively, you can simply type `'f'` to find out which characters do not have a typeface defined yet. 
