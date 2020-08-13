#include <header.h>
char* getLink(char *src,char *search){
	char*tmp=strgrep(src,search);
	tmp=strgrep(tmp,"<a");
	tmp=getToken(tmp,"href");
	return tmp;
}
