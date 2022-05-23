#include "html.h"
#include "curl/curl.h"
#pragma comment(lib,"libcurl.lib")

static size_t cb(char* data, size_t size, size_t nmemb, char* userp)
{
    size_t realsize = size * nmemb;
    HTML_CODE::memory* mem = (struct HTML_CODE::memory*)userp;

    char* ptr = static_cast<char*>(realloc(mem->response, mem->size + realsize + 1));

    if (ptr == nullptr)
        return 0;

    mem->response = ptr;
    memcpy(&(mem->response[mem->size]), data, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0;

    return realsize;
}
HTML_CODE::HTML_CODE() : chunk{0}
{
    CURL* curl_handle = curl_easy_init();
    if (curl_handle)
    {
        curl_easy_setopt(curl_handle, CURLOPT_URL, "https://www.finanz.ru/valyuty/v-realnom-vremeni-rub");
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void*)&chunk);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, cb);
        CURLcode res = curl_easy_perform(curl_handle);
        curl_easy_cleanup(curl_handle);
    }
}

char* HTML_CODE::getHtml() const
{
    return chunk.response;
}