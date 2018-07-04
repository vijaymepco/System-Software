#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
int check_length(char line[]){
	// this function to  check the characters count.
	int count = 0;
	return count;	
}*/
int main(){
	
	// opcode creation logic has to be written.
	char opcode[][2] = {"18","58","90","40","B4","28","88","A0","24","64","9C","C4","C0","F4","3C","30","34","38","48","00","68","50","70","08","6C","74","04","D0","20","60","98","C8","44","D8","AC","A4","A8","F0","EC","0C","78","54","80","D4","14","7C","E8","84","10","1C","5C","94","B0","E0","F8","2C","B8","DC"};	
	// to do token separation with the input file.
	
	char input[25];
	int i,j,length;
	char ch;
	// intilialiing the input array with ' '
	for(i=0;i<25;i++)
		input[i] = ' ';
	// file pointers

	FILE *f_input,*f_token,*f_symtab,*f_opcode;
	
	// opening the input and token file for outputs
	
	f_input = fopen("input.txt","r");	
	
	f_token = fopen("token.txt","w+");
	
	// scanning the input file.
	ch = getc(f_input);
	i = 0;
	while(ch != EOF){
		printf("%c",ch);
		if(ch=='\n'){
			//writing a file.  i -> total length
			for(j=0;j<i;j++){
				if(j+1<i){
					if(input[j] == ' ' && input[j+1]=='#')
						fprintf(f_token,"%c",input[j]);
					else if(input[j]=='#')
						fprintf(f_token," ");
					else
						fprintf(f_token,"%c",input[j]);
				}
			}
			printf("%c",input[j-1]);
			fprintf(f_token,"%c",input[j-1]);
			fprintf(f_token,"\n");
			i=0;
		}
		else
			input[i++] = ch;
		ch = getc(f_input);	// it moves to other pointer
	}
	

	//for(i=0;i<20;i++){
		//printf("%s\n",opcode[2]);
	//}

	fclose(f_input);
	// Add other files also
}	
