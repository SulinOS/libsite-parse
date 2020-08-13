#include <stdio.h>
#include <header.h>
#include <string.h>
int main(int argc,char *argv[]){
	char*site=read_site("https://www.gnu.org/");
	printf("%s",getLink(site,".html"));
}

