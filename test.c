#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <cJSON.h> // Include cJSON from the lib folder

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t total_size = size * nmemb;
    strcat((char *)userp, (char *)contents); // Append received data
    return total_size;
}

int main(void) {
    CURL *curl;
    CURLcode res;
    char response[4096] = ""; // Buffer to hold the response
    char user_input[512]; // Buffer to hold user input

    // Initialize libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);

    while (1) {
        // Get user input
        printf("Enter a message (or type 'stop' to exit): ");
        fgets(user_input, sizeof(user_input), stdin);
        user_input[strcspn(user_input, "\n")] = '\0';  // Remove the newline character from the input

        // Exit the loop if user types 'stop'
        if (strcmp(user_input, "stop") == 0) {
            break;
        }

        // Initialize CURL session
        curl = curl_easy_init();
        if(curl) {
            struct curl_slist *headers = NULL;

            // Create JSON payload using cJSON
            cJSON *root = cJSON_CreateObject();
            cJSON *messages = cJSON_CreateArray();
            cJSON *message = cJSON_CreateObject();

            // Populate the JSON payload with user input
            cJSON_AddStringToObject(message, "role", "user");
            cJSON_AddStringToObject(message, "content", user_input);
            cJSON_AddItemToArray(messages, message);
            cJSON_AddItemToObject(root, "messages", messages);
            cJSON_AddStringToObject(root, "model", "llama3-8b-8192");

            // Convert cJSON object to string
            const char *json_data = cJSON_PrintUnformatted(root);

            // Set the URL and options for the request
            curl_easy_setopt(curl, CURLOPT_URL, "https://api.groq.com/openai/v1/chat/completions");

            // Disable SSL verification (not recommended for production)
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);  // Disable SSL peer verification
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);  // Disable SSL host verification

            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data);

            // Set headers
            headers = curl_slist_append(headers, "Content-Type: application/json");
            headers = curl_slist_append(headers, "Authorization: Bearer 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");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

            // Set the write callback function
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);

            // Perform the request
            res = curl_easy_perform(curl);
            if(res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            } else {
                // Print only the content from the response
                cJSON *json_response = cJSON_Parse(response);
                if (json_response) {
                    cJSON *choices = cJSON_GetObjectItem(json_response, "choices");
                    if (cJSON_IsArray(choices) && cJSON_GetArraySize(choices) > 0) {
                        cJSON *first_choice = cJSON_GetArrayItem(choices, 0);
                        cJSON *message = cJSON_GetObjectItem(first_choice, "message");
                        if (cJSON_IsObject(message)) {
                            cJSON *content = cJSON_GetObjectItem(message, "content");
                            if (cJSON_IsString(content)) {
                                printf("Response content:\n%s\n", cJSON_GetStringValue(content));
                            }
                        }
                    }
                    cJSON_Delete(json_response); // Free cJSON object
                } else {
                    printf("Failed to parse JSON response.\n");
                }
            }

            // Cleanup
            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);
            cJSON_Delete(root); // Free cJSON object
            free((void *)json_data); // Free the JSON string
        }

        // Reset the response buffer for the next request
        memset(response, 0, sizeof(response));
    }

    curl_global_cleanup();
    return 0;
}
