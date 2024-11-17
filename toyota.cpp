//  Created by Samyam Paudel on 11/16/24.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using namespace std;


int readCarsYear(int carYear){
    
    cin >> carYear;
    
    if(carYear < 2021 || carYear > 2025){
        return -1;
    }
    else{
        return carYear;
    }
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* response) {
    size_t totalSize = size * nmemb;
    response->append((char*)contents, totalSize);
    return totalSize;
}

string fetchDataFromAPI(const string& url) {
    CURL* curl;
    CURLcode res;
    string response;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            cerr << "Error fetching data: " << curl_easy_strerror(res) << endl;
        }
    }
    return response;
}

string readCarModel(string models){
    

    cin >> models;
    
    if(models == "camry"){
       
    }
    else if(models == "corollla"){
        
    }
    else if(models == "sienna"){
        
    }
    else if(models == "highlander"){
        
    }
    else if(models == "rav4"){
        
    }
    else if(models == "4runner"){
        
    }
    else if(models == "crown"){
        
    }
    return models;
}

string engineType(string engines){
    cin >> engines;
    
    if(engines == "hybrid"){
            
        }
    else if(engines == "cylinder"){
        
    }
    else if(engines == "v6"){
        
    }
    return engines;
}

string modelSize(string sizes){
    cin >> sizes;
    
    if(sizes == "SUV"){
        
    }
    else if(sizes == "sedan"){
        
    }
    else if(sizes == "minivan"){
        
    }
    else if(sizes == "truck"){
        
    }
    return sizes;
}

string trimLevels(string trims){
    cin >> trims;
    
    if(trims == "xle"){
        
    }
    else if(trims == "le"){
        
    }
    else if(trims == "se"){
        
    }
    else if(trims == "xse"){
        
    }
    return trims;
}





int main(){
    
    string models;
    string trims;
    string engines;
    int carYear;
    
    string apiResponse = fetchDataFromAPI("https://api.example.com/toyota/models?year=2023");
    
    vector<string> validModels;
    
    try{
        auto jsonData = json::parse(apiResponse);
                for (const auto& model : jsonData["models"]) {
                    validModels.push_back(model["name"]);
            }
        }
    
    return 0;
}
