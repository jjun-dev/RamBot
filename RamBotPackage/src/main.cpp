#include <dpp/dpp.h>
#include <iostream>
#include <fstream>
#include <string>

std::string getToken(const std::string& filename) {
    std::ifstream file(filename);
    if(!file) {
        std::cerr << "Error : Can't find token file" << std::endl;
        exit(1);
    }

    std::string token;
    std::getline(file, token);
    return token;
}

const std::string BOT_TOKEN = getToken("../token.txt");
int main() {
    dpp::cluster bot(BOT_TOKEN);

    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
            if (event.command.get_command_name() == "ping") {
                event.reply("Pong");
            }
            
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
            if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("ping", "Ping pont!", bot.me.id));
            }
            
    });

    bot.start(dpp::st_wait);
}
