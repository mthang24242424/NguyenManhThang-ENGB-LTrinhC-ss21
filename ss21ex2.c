#include<stdio.h>
int main(){
	FILE *fptr;
	fptr =fopen("bt01.txt","r");
	char word[100];
	fgets(word,100,fptr);
	printf("gia tri dau tien trong bt01.txt la: %c",word[0]);
	fclose(fptr);
	return 0;
}

