#include "network.hpp"

#define version "1.3"

#define token "your bot's token"
#define webhookBot "your bot's webhook"

int main(){

    network program(token, webhookBot, version);
    program.MAIN();
    program.perfomBot();




    return 0;
}