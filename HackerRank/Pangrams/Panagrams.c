#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ss[1001];
int mark[26] = {0};

int main(){
	int l, i;
	gets(ss);
	l = strlen(ss);
	for(i=0; i<l; i++){
		if(ss[i]>='a' && ss[i]<='z')mark[ss[i]-'a'] = 1;
		else if(ss[i]>='A' && ss[i]<='Z')mark[tolower(ss[i])-'a'] = 1;

	}


	for(i=0; i<26; i++){
//		printf("%d ", i);
		if(!mark[i])break;
	}
//	printf("\n");
	if(i==26)printf("pangram\n");
	else printf("not pangram\n");
	return 0;
}
