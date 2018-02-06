#include <stdio.h>
#include "regexp.h"

int main(int argc,char *argv[]){
	int cn;
	
	char test[] = "Jan Nicolas Jonas Helbling Nolaci Nilillic";
	char pattern[] = "N[icolas]+";
	
	char **buffer = (char **)malloc(4096);
	cn = RegExtractAll(test,pattern,buffer);
	
	int i;
	
	for(i=0;i!=cn;i++){
		puts(buffer[i]);
	}
	free(buffer);
	return 0;
}
