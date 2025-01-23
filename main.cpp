#include "network.hpp"

#define version "1.3"

#define token "Your token bot"
#define webhookBot "Your webhook bot"

int main(){

    network program(token, webhookBot, version);
    program.MAIN();
    program.perfomBot();




    return 0;
}