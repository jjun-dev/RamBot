#include <dpp/dpp.h>
#include <iostream>
#include <string>
#include "Constants.h"

const long int GUILD_ID = GI_1;
int main() {

    dpp::cluster bot(BOT_TOKEN);

    bot.on_log(dpp::utility::cout_logger());

     
    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "ping") {
            event.reply("Pong!");
        }
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.guild_command_create(dpp::slashcommand("ping", "Ping pong!", bot.me.id), GUILD_ID);
        }
    });

    bot.start(dpp::st_wait);
}
