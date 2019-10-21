/* regexp.c regexp.h, extract RegexMatches in C

    Copyright (C) 2014 by Jan Helbling <jan.helbling@mailbox.org>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    
    Extract all or a single regexmatch from a string. Take a look at example.c */

#include <regex.h>
#include <stdlib.h>
 
char *regexp (const char *string,const char *patrn, int *begin, int *end) {
	int len;
	int i;
	int wcnt = 0;
	
	char *word = NULL;
	
	regex_t rgxt;
	regmatch_t match;
	
	// Compile the pattern
	regcomp(&rgxt,patrn,REG_EXTENDED);
	
	// Check if pattern matches in string
	if ((regexec(&rgxt,string,1,&match,0)) == 0) {
		// Begin, end and length of the match
		*begin	= (int)match.rm_so;
		*end	= (int)match.rm_eo;
		len	= *end-*begin;
		
		// Get some memory
		word	= (char *)malloc(len+1);
		
		// Copy the match
		for (i=*begin; i<*end; i++) {
			word[wcnt]	= string[i];
			wcnt++;
		}
		// Terminate it with a \0
		word[wcnt]		= 0x00;
	}
	
	// Free the memory of the pattern
	regfree(&rgxt);
	
	// Return the Match
	return word;
}

int RegExtractAll(const char *string, const char *pattern, char **buffer){
	int counter = 0;
	int cnt = 0;
	
	// Duplicate the string to skip already matched matches
	char *myeditableString = strdup(string);
	
	while(1){
		int a,b;
		char *match = regexp(myeditableString,pattern,&a,&b);
		if(match != NULL){
			buffer[counter++] = strdup(match);
			free(match);
			cnt++;
		} else {
			break;
		}
		// Skip string until the end of last matched match
		myeditableString += b;
	}
	return cnt;
}
