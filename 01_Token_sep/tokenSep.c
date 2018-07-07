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
	//===============================================================================//
	FILE *fin;
	FILE *fout;
	FILE *fout1;
	fout1 = fopen("test.txt", "w");
	fout = fopen("symboltable.txt", "w");
	char c;
	char c1=' ';
	char c2;
	int line_number=0;
	char Start[20];
	 int val,i1,no;
				  int len;
				  int decimal=0;
    			  int place;
    			  int tempDecimal;
    char hex[20];
    int index, rem;
    char HEXVALUE[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char operant=' ';
    char num[100];
	int dec = 0;
	//char lnumber[20];
	//	int i=1
	int lno=0,flag=0;
    printf("Enter the starting address ");
    gets(Start); 
	fin = fopen("ALP.txt", "r");
	c = fgetc(fin);
    while (c != EOF)
    {   lno+=1;
    		printf("%c",c);
        //fprintf (fout1,"%c", c);
        if(c=='\n')
        	{
				flag+=1;	
        		i1=1;
				 line_number+=1;
				  
    			   place = 1;
                  len = strlen(Start);
                  len--;

    
    for(i=0; Start[i]!='\0'; i++)
    {
 
     
        if(Start[i]>='0' && Start[i]<='9')
        {
            val = Start[i] - 48;
        }
        else if(Start[i]>='a' && Start[i]<='f')
        {
            val = Start[i] - 97 + 10;
        }
        else if(Start[i]>='A' && Start[i]<='F')
        {
            val = Start[i] - 65 + 10;
        }

        decimal += val * pow(16, len);
        len--;
    }
			
        //	decimal+=3;
    	//	decimal=decimal-1000;
    		decimal+=3;
    		
    tempDecimal = decimal;

    index = 0;
    
    /* Decimal to hexadecimal conversion */
    while(tempDecimal !=0)
    {
        rem = tempDecimal % 16;

        hex[index] = HEXVALUE[rem];

        tempDecimal /= 16;


        index++;
    }
    hex[index] = '\0';

    strrev(hex);
    no = atoi (hex);
    if(flag>1)
    no=no-1000;
    
   /* if(hex[1]=='F' || hex[1]=='f')
		{
			if(hex[0]=='0')
				hex[0]='1';
		}
    if(hex[1]=='F' || hex[1]=='f')
		{
			if(hex[0]=='1')
				hex[0]='2';
		}
    if(hex[1]=='F' || hex=='f')
		{
			if(hex[0]=='2')
				hex[0]='3';
		}
	if(hex[1]=='F' || hex=='f')
		{
			if(hex[0]=='3')
				hex[0]='4';
		}
	if(hex[1]=='F' || hex=='f')
		{
			if(hex[0]=='4')
				hex[0]='5';
		}
	if(hex[1]=='F' || hex=='f')
		{
			if(hex[0]=='5')
				hex[0]='6';
		}
	if(hex[1]=='F' || hex=='f')
		{
			if(hex[0]=='6')
				hex[0]='7';
		}
		if(hex[1]=='F' || hex=='f')
		{
			if(hex[0]=='7')
				hex[0]='8';
		}
		if(hex[1]=='F' || hex=='f')
		{
			if(hex[0]=='8')
				hex[0]='9';
		}
		if(hex[1]=='F' || hex=='f')
		{
			if(hex[0]=='9')
				hex[0]='A';
		}
		if(hex[1]=='F' || hex=='f')
		{
			if(hex[0]=='A' || hex[0]=='a')
				hex[0]='B';
		}
		if(hex[1]=='F' || hex=='f')
		{
			if(hex[0]=='b' || hex[0]=='B')
				hex[0]='C';
		}
		if(hex[1]=='F' || hex=='f')
		{
			if(hex[0]=='C'|| hex[0]=='c')
				hex[0]='D';
		}
		if(hex[1]=='F' || hex=='f')
		{
			if(hex[0]=='d'|| hex[0]=='D')
				hex[0]='E';
		}
		if(hex[1]=='F' || hex=='f')
		{
			if(hex[0]=='E'|| hex[0]=='e')
				hex[0]='F';
		}
		else*/
		hex[0]=Start[i];
//		if(hex[1]=='F' || hex=='f')
//		{
//			if(hex[0]=='F'|| hex[0]=='f')
//				hex[0]='D';
//		}

    //len = strlen(num);
//	for(i=0; i<len; i++){
//		dec = dec * 10 + ( num[i] - '0' );
    
    
    
    fprintf(fout1," %s", hex);
				

     }
     if(operant=='A' || operant=='C' || operant=='B'|| operant!=' ')
	 	{
	 		fprintf(fout,"%s ", hex);
	 		fprintf(fout,"%c", operant);
	 		fprintf(fout,"\n");
	 		operant=' ';
   			
	 			
		 }
	if(c=='A' || c=='B' ||c=='C')
			{
			//	c2=fgetc(fin);
				if(c1=='\n')
					operant=c;
				
			}	
		
		fprintf(fout1,"%c", c);
		
			c1=c;
        c = fgetc(fin);
    }
 	printf("%d\n",line_number);
 	printf("%d\n",decimal);
 	printf("%s\n",hex);
    fclose(fin);
    fclose(fout);
} 
