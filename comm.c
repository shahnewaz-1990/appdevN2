#include <stdio.h>
#include <i386-linux-gnu/curl/curl.h>
#include "comm.h"

void sendpost(char *url, char *post){
	CURL *curl;
	CURLcode res;

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	if(curl){
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK){
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));

		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
}
