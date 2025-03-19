#include <iostream>
#include <string>
#include "commands.h"
#include "constants.h"

const long int GUILD_ID = GI_1;
int main() {

    dpp::cluster bot(BOT_TOKEN);

    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
        commands::handleCommands(event);
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        bot.guild_bulk_command_create(commands::returnSlashCommands(bot), GUILD_ID);
    });

    bot.start(dpp::st_wait);
}
