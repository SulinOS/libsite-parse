#include <stdio.h>
#include <header.h>
#include <string.h>
int main(int argc,char *argv[]){
	char*site=read_site("https://gitlab.com/sulinos/devel/libsite-parse");
  site=strgrep(site,"/sulinos");
  site=getLink(site,".tar.gz");
  site=strsplit(site,"\n")[0];
	printf("https://gitlab.com%s\n",site);
}

