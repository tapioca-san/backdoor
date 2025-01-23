#include "network.hpp"


void network::MAIN() {



bot.on_message_create([this](const dpp::message_create_t& event) {
if (event.msg.content.find(';') != std::string::npos) {
try {
if (event.msg.content.find(myip) != std::string::npos || event.msg.content.find("127.0.0.1") != std::string::npos || event.msg.content.find(myGroup) != std::string::npos) {
    int command = 0;
    if (findWordsOnString(event.msg.content, "shutDown"))                                                            command = 1;
    if (findWordsOnString(event.msg.content, "deBugger"))                                                            command = 2;
    if (findWordsOnString(event.msg.content, "version"))                                                             command = 3;
    if (findWordsOnString(event.msg.content, "add"))                                                                 command = 4;
    if (findWordsOnString(event.msg.content, "pl.") || findWordsOnString(event.msg.content, "op.")) command = 5;
    if (findWordsOnString(event.msg.content, "credits"))                                                             command = 6;
    if (findWordsOnString(event.msg.content, "devBot"))                                                              command = 7;

    switch (command) {
        case 1:
            event.reply("Shutting down  . . .");
            std::this_thread::sleep_for(std::chrono::seconds(3));
            bot.shutdown();
            break;
        case 2:
            if(findWordsOnString(event.msg.content, "on")){
                deBugger = true;
                event.reply("debugger ativado");
            }
            if(findWordsOnString(event.msg.content, "off")){
                deBugger = false;
                event.reply("debugger desativado");
            }
            break;
        case 3:
            event.reply(version);
            break;
        case 4:
            myGroup = cleanWordsOnString(event.msg.content, "add", false);
            if(deBugger){
                event.reply("add to: " + myGroup);
            }
            break;
        case 5:
            processCommand("op.", event);
            processCommand("pl.", event);
            break;
        case 6:
            event.reply("Pipebomb is my creator 0_0.");
            break;
        case 7:
            event.reply("https://discord.com/developers/applications");
            break;
        default:
            break;

    }
   
    
    
    
    }
} catch (const std::exception& e) {
    std::cerr << "Erro: " << e.what() << std::endl;
} // try's inside
} // inside command call
}); // bot discord
} // function





    


    