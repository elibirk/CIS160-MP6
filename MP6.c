/* ========================================================
Leah Perry								  CIS 160 Fall 2014
MP6							 			 Submitted: 12/5/14
Read, edit, and write file				Revised on: -------


Data Dictionary
Variable				Used to
--------				-------
char ch					stores characters from the original file one at a time
char rchar				holds the characters as the program reverses and edits the original file
int OrigLength			stores the size of the original file
int Count				counts down characters in the original file as they are being processed for the new file
char* filename			stores the name of the file from the user
int letters				stores the number of letters in the original file
int LoLetters			stores the number of lowercase letters in the original file
int CapLetters			stores the number of capital letters in the original file
int SpacePunk			stores the number of spaces and punctuation marks in the original file
int numbers				stores the number of numbers in the original file
int Reletters			stores the number of letters in the reversed file
int ReLoLetters			stores the number of lowercase letters in the reversed file
int ReCapLetters		stores the number of capital letters in the reversed file
int ReSpacePunk			stores the number of spaces and punctuation marks in the reversed file
int Renumbers			stores the number of numbers in the reversed file
errno_t err				checks streamname stream for errors when opening
errno_t reverr			checks reversestream stream for errors when opening

Functions Called		What They Do
----------------		------------
ChangeCase				Changes uppercase letters to lowercase


C:\User\Owner\My Documents\Visual Studio 2013\Projects\MP6
==========================================================*/

//precompiler directives
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

//function prototypes go here
char ChangeCase(int rchar);//changes capital letters to lowercase

//main function
int main (void) 
{
	/* ========================================================
	Leah Perry								  CIS 160 Fall 2014
	MP6							 			 Submitted: 12/5/14
	Read, edit, and write file				Revised on: -------


	Data Dictionary
	Variable				Used to
	--------				-------
	char ch					stores characters from the original file one at a time
	char rchar				holds the characters as the program reverses and edits the original file
	int OrigLength			stores the size of the original file
	int Count				counts down characters in the original file as they are being processed for the new file
	char* filename			stores the name of the file from the user
	int letters				stores the number of letters in the original file
	int LoLetters			stores the number of lowercase letters in the original file
	int CapLetters			stores the number of capital letters in the original file
	int SpacePunk			stores the number of spaces and punctuation marks in the original file
	int numbers				stores the number of numbers in the original file
	int Reletters			stores the number of letters in the reversed file
	int ReLoLetters			stores the number of lowercase letters in the reversed file
	int ReCapLetters		stores the number of capital letters in the reversed file
	int ReSpacePunk			stores the number of spaces and punctuation marks in the reversed file
	int Renumbers			stores the number of numbers in the reversed file
	errno_t err				checks streamname stream for errors when opening
	errno_t reverr			checks reversestream stream for errors when opening

	Functions Called		What They Do
	----------------		------------
	ChangeCase				Changes uppercase letters to lowercase

	==========================================================*/
	//insert code here

	
	char* filename[5005];
	//FILE *streamname;
	char ch;
	//Character types for the original file:
	int letters = 0;
	int LoLetters = 0;
	int CapLetters = 0;
	int SpacePunk = 0;
	int numbers = 0;
	//character types for the edited file:
	int Reletters = 0;
	int ReLoLetters = 0;
	int ReCapLetters = 0;
	int ReSpacePunk = 0;
	int Renumbers = 0;

	errno_t err, reverr;//to check streams for opening errors

	printf("Enter name of file. "); //asks user for file
	scanf_s("%s", &filename,50); //scans in filename

	FILE *streamname;

	err	= fopen_s(&streamname, filename ,"r"); //opens the stream
	if (err == 0) {
		ch = fgetc(streamname);
		while (ch != EOF) {
			printf("%c", ch);
			switch (ch) { //deal w/ characters
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':
				letters++;
				LoLetters++;
				break; //end lower case letters
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
				letters++;
				CapLetters++;
				break;//end upper case letters
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				numbers++;
				break;//end numbers
			case ' ':
			case '.':
			case ',':
			case '!':
			case '?':
			case ';':
			case ':':
			case '-':
			case '(':
			case ')':
			case '[':
			case ']':
			case '{':
			case '}':
			case '\'':
			case '"':
				SpacePunk++;
				break;//end space/punctuation
			default:
				break;
			}//end sqitch case
			ch = fgetc(streamname);
		}//end while
	}//end if
	else {
		printf("File wont open. Are you sure it's in the right space?");
		system("pause");
	}


	//now to deal with reverse editing stuff


	FILE* reversestream;
	reverr = fopen_s(&reversestream, "\MP6Output.dat", "w");//opens a new stream for writing into Mp6Output
	if (reverr == 0) {
		fseek(streamname, 0, SEEK_END); //sets pointer to end of the original file
		int OrigLength = ftell(streamname); //sets fileLength as the length of the original file
		for (int Count = OrigLength; Count >= 0; Count--) //goes through the characters, stops when the beginning is reached
{
			fseek(streamname, Count, SEEK_SET); //sets the position of the stream to count so it continually shifts back
			char rchar = fgetc(streamname); //sets rchar as the character in the original file
			switch (rchar) { //deal w/ characters
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':
				Reletters++;
				ReLoLetters++;
				fprintf(reversestream, "%c", rchar);//puts the character in MP6Output.dat
				break; //end lower case letters
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
				rchar = ChangeCase(rchar);//chances rchar to lowercase
				Reletters++;
				ReLoLetters++;
				fprintf(reversestream, "%c", rchar);//puts the character in MP6Output.dat
				break;
			default:
				break;
			}
			
		}
	}
	else {
		printf("Cannot write to file.");
	}//end else
	fclose(streamname); ///closes original stream
	fclose(reversestream); //closes reverse stream
	printf("\n-------------------\nCharacter Count:\n\nOriginal File:\n\tLetters: \t\t%d\n\tLower Case Letters: \t%d\n\tCapital: \t\t%d\n\tNumbers: \t\t%d\n\tSpaces/Punctuation: \t%d\n", letters, LoLetters, CapLetters, numbers, SpacePunk);//prints info on original file
	printf("New File:\n\tLetters: \t\t%d\n\tLower Case Letters: \t%d\n\tCapital Letters: \t%d\n\tNumbers: \t\t%d\n\tSpaces/Punctuation: \t%d\n", Reletters, ReLoLetters, ReCapLetters, Renumbers, ReSpacePunk);//prints info on new file

	system("pause");//keeps window open
return 0;
} //end main function

//insert function definitions here

char ChangeCase(int rchar){//changes capital letters to lower case
	/* ========================================================
	Leah Perry								  CIS 160 Fall 2014
	MP6							 			 Submitted: 12/5/14
	Changes a char to lowercase				Revised on: -------


	Data Dictionary
	Variable				Used to
	--------				-------
	rchar					store the character being changed

	Functions Called		What They Do
	----------------		------------


	==========================================================*/
switch (rchar) {
case 'A':
	rchar = 'a';
	break;
case 'B':
	rchar = 'b';
	break;
case 'C':
	rchar = 'c';
	break;
case 'D':
	rchar = 'd';
	break;
case 'E':
	rchar = 'e';
	break;
case 'F':
	rchar = 'f';
	break;
case 'G':
	rchar = 'g';
	break;
case 'H':
	rchar = 'h';
	break;
case 'I':
	rchar = 'i';
	break;
case 'J':
	rchar = 'j';
	break;
case 'K':
	rchar = 'k';
	break;
case 'L':
	rchar = 'l';
	break;
case 'M':
	rchar = 'm';
	break;
case 'N':
	rchar = 'n';
	break;
case 'O':
	rchar = 'o';
	break;
case 'P':
	rchar = 'p';
	break;
case 'Q':
	rchar = 'q';
	break;
case 'R':
	rchar = 'r';
	break;
case 'S':
	rchar = 's';
	break;
case 'T':
	rchar = 't';
	break;
case 'U':
	rchar = 'u';
	break;
case 'V':
	rchar = 'v';
	break;
case 'W':
	rchar = 'w';
	break;
case 'X':
	rchar = 'x';
	break;
case 'Y':
	rchar = 'y';
	break;
case 'Z':
	rchar = 'z';
	break;
default:
	break;
}//end switchcase
return rchar; //returns the lower case
}//end ChangeCase