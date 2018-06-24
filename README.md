# ASCII Text Generator
This bit of code can generate ASCII wordart. The default typeface provided is 'Graffiti' from http://patorjk.com/software/taag/. Users can also define their own typefaces using the commandline interface. 

## Basic Information
- All ASCII characters loaded into the program's database must be MAXHEIGHT lines high. This is to ensure consistency in the typeface.
- Only alphabets (both upper and lower-case) can be generated using this program. **Space bar support will be added soon.**
- Should any alphabet's typeface not be added to the database, the default value will be a (MAXHEIGHT x 5) block of # characters.
- The database refers to a file that is automatically generated when the code is first run, named `ascii_database.bin`. You can simply replace this file with another user-defined database to immediately obtain the typeface of your choice. 

## Instructions for use:
1. Compile and run `main.c`
2. Should you already have a pre-defined `ascii_database.bin` file (the one provided on GitHub has the Graffiti typeface pre-loaded and can be used), simply type `'l'` to load the existing database. 
    - IMPORTANT NOTE:  ALWAYS load the database first, even if its empty. Should you an existing database already be defined, and you press `'s'`, this will overwrite the ENTIRE database, so all tyepfaces will be lost.
3. Should you wish to manually define/overwrite an existing typeface, simply type `'a'` to add a record. Specify which character you are defining the typeface for. Note that this code distinguishes between upper and lower case characters, and is therefore case-sensitive. 
4. After defining your own typefaces, remember to type `'s'` on the command-line to save your changes to the `ascii_database.bin` file. Type `'l'` to re-load the database. 
5. Type `'u'` to use the typeface defined in `ascii_database.bin`. Type a word and hit enter. The ASCII word art will be generated on the command-line. 
6. Should you wish to examine an individual character in the database, type `'d'` and specify which character you are interested in viewing. This might be useful for checking if the character was defined in the first place (if undefined, it will default to a block of ### characters). Alternatively, you can simply type `'f'` to find out which characters do not have a typeface defined yet. 