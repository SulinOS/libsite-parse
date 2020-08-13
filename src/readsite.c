#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
struct MemoryStruct {
  char *memory;
  size_t size;
};
size_t
writefunc(void *contents, size_t size, size_t nmemb, void *userp){
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;
 
  char *ptr = realloc(mem->memory, mem->size + realsize + 1);
  if(ptr == NULL) {
    printf("not enough memory (realloc returned NULL)\n");
    return 0;
  }
 
  mem->memory = ptr;
  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;
 
  return realsize;
}
char* read_site(char *url){
  CURL *curl;
  CURLcode res;
  curl = curl_easy_init();
  if(curl) {
    struct curl_slist *chunk = NULL;
    struct MemoryStruct mem;
    mem.memory = malloc(1);
    mem.size = 0; 
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &mem);
    curl_easy_setopt(curl,CURLOPT_URL,url);
    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    curl_easy_cleanup(curl); 
    curl_slist_free_all(chunk);
    return mem.memory;
  }
}

