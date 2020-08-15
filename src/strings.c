#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <header.h>

int strcount(char* buf,char* c){
    int size=1;
    for(int i=0;i<=strlen(buf);i++){
      if(buf[i]==c[0]){
        size++;
      }
    }
    return size;
}

char** strsplit( const char* s, const char* delim ) {
	void* data;
	char* _s = ( char* )s;
	const char** ptrs;
	size_t
		ptrsSize,
		nbWords = 1,
		sLen = strlen( s ),
		delimLen = strlen( delim );

	while ( ( _s = strstr( _s, delim ) ) ) {
		_s += delimLen;
		++nbWords;
	}
	ptrsSize = ( nbWords + 1 ) * sizeof( char* );
	ptrs =
	data = malloc( ptrsSize + sLen + 1 );
	if ( data ) {
		*ptrs =
		_s = strcpy( ( ( char* )data ) + ptrsSize, s );
		if ( nbWords > 1 ) {
			while ( ( _s = strstr( _s, delim ) ) ) {
				*_s = '\0';
				_s += delimLen;
				*++ptrs = _s;
			}
		}
		*++ptrs = NULL;
	}
	return data;
}
char *strgrep(char*src,char*patern){
	char *ret=malloc(sizeof(char)*(strlen(src)+1));
	strcpy(ret,"");
	char**lines=strsplit(src,"\n");
	int len=strcount(src,"\n");
	int size=0;
	for (int i=0;i<len;i++){
    int index=strindex(lines[i],patern);
		if(index!=-1){
			strcat(ret,lines[i]);
			strcat(ret,"\n");
			size=size+strlen(lines[i])+1;
		}
	}
	return realloc(ret,(sizeof(char)*(size+1)));
}
int strindex(char *src, char*find){
	int ret = -1;
	if(strlen(find)>strlen(src)){
		return ret;
	}
	for(int i=0;i<(strlen(src)-strlen(find));i++){
		for(int j=0;j<strlen(find);j++){
			if(src[i+j]==find[j]){
				ret=i;
			}else{
				ret=-1;
				break;
			}
		}
		if(ret!=-1){
			return ret;
		}
	}
	return ret;
}
char *getToken(char *src,char* token){
	char*search=malloc(sizeof(char)*(strlen(token)+3));
	strcpy(search,token);
	strcat(search,"=\"");
  char *tmp=strcut(src,search,1);
  tmp=strcut(tmp,"\"",0);
	return tmp;
}
char *strcut(char*src, char*search,int status){
	src=strgrep(src,search);
	char *ret=malloc(sizeof(char)*(strlen(src)+1));
	strcpy(ret,"");
	char**lines=strsplit(src,"\n");
	int len=strcount(src,"\n");
	int size=0;
	int index=0;
	for (int i=0;i<len;i++){
		char *line=malloc(sizeof(char)*(strlen(lines[i])+1));
		strcpy(line,lines[i]);
		index=strindex(line,search);
		if(status && index>=0){
			for(int j=index+strlen(search);j<strlen(lines[i]);j++){
				char c[2]="\0";
				c[0]=line[j];
				strcat(ret,c);
				size++;
			}
			strcat(ret,"\n");
		}else if(status==0 && index>=0){
      strncat(ret,line,index);
			strcat(ret,"\n");
		  size=size+index;
		}
	}
	return ret;
}
