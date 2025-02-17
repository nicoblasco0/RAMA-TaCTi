#ifndef API_H_INCLUDED
#define API_H_INCLUDED

#include <curl/curl.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);

#endif // API_H_INCLUDED
