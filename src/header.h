char *read_site(char*url);
char** strsplit( const char* s, const char* delim );
int strcount(char* buf,char* c);
char *strgrep(char*src,char*patern);
int strindex(char *src, char*find);
char *strcut(char*src, char*search,int status);
char *getToken(char *src,char* token);
char* getLink(char *src,char *search);
