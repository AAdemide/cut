//pre-processors
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assign2func.h"
#include <ctype.h>

//get_fields()
//returns an integer array of the fields
//char **field-the argv array, int argc-the length of argv array
//return fields-an integer  array of the fields
//takes in the array of command line arguements and the lenght of that array
//returns an integer array of only the fields from argv

int* get_fields(char **field, int argc){
	//fields is an integer array that would be used to store the feilds, it will be returned
	int *fields=(int *) calloc(sizeof(int), argc-3);
	//parses and the fields from the commandline arguements
        for(int i=3, fld=0; i <argc;i++, fld++){
                fields[fld]=atoi(&*field[i]);
        }

	return fields;
}

//cut()
//cuts fields from a delimeted string and returns a string specified delimeted strings
//char **field-a copy of the argv array, char buffer[]-the string to be parsed, int argc-a copy of the argc variable
const char* cut(char **field, char buffer[], int argc){
	//int fld-a variable to help iterate the fields, int found-counts the number of fields that have been found--
	//--, int index-documents the difference between the current field and the last field that was found--
	//int count-documents how much space has bee used in the count array
	//int nn-the length of the string to be parsed
	//char *temp-the parsed string of the input with all the requested fields to be returned.
	//int fields[]-stores an array of the fields to be parsed
	int fld=0, found=0, index=0, count=0;
	int nn=strlen(buffer);
	char *temp=(char *) calloc(1,nn+1);
	int fields[argc-3];

	//copies the fields into the fields array from the get_fields() function
	memcpy(fields, get_fields(field, argc), sizeof(fields));

	//loops through each character in the given string
	for(int i=0; i<=nn; i++){
		//if the delimeter has been found or it is the end of the string
		if(*field[1]==buffer[i] || buffer[i] == '\0'){
			found+=1;//increase the number of variables that have been found
			if(fld>argc-1)	break;

			if(fields[fld]==found){//if the number of fields found is equal to a field in the fields array
				//start a loop to copy that field into the temp array
				for(;index<i; index++, count++){
					temp[count]=buffer[index];
				}
				//increase the fld variable by one, add the output delimeter to the return string--
				//increase the count function by one
				fld+=1;
				temp[count]=*field[2];
				count++;
				}
			if (buffer[i] != '\0')	index=i+1; //only increase the index var if it's not the end of string
		}
	}
	//if no fields were found copy whole string into temp var and return
	if(found == 0) {
		for(int i = 0; i < nn; i++) {
			temp[i] = buffer[i];
		}
		return temp;
	}

	//remove the last output the function appended
	//if the last character is a new line, remove it
	temp[strlen(temp)-1]='\0';
	if(temp[strlen(temp)-1]=='\n')	temp[strlen(temp)-1]='\0';
	free(fields);//free the memory get_fields() asked for
	return temp;
}

