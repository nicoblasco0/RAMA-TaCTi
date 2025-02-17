#include <stdio.h>
#include <stdlib.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    printf("%.*s", (int)realsize, (char *)contents);
    return realsize;
}
