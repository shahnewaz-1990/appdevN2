#include <stdio.h>
#include <i386-linux-gnu/curl/curl.h>
#include "comm.h"

// if we interested in 
// 1. number of peaks in a piece of wac file
// 2. max decibel value of this wav, then
//our post string shouldlook like "peaks=2&max=78.9"
// the url chould be "http://www.cc.puv.fi/~e1900302/php/sound.php



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
