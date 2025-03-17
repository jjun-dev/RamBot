#include <dpp/dpp.h>
#include <iostream>
#include <string>
#include "Constants.h"

const long int GUILD_ID = GI_1;
int main() {

    dpp::cluster bot(BOT_TOKEN);

    bot.on_log(dpp::utility::cout_logger());

     
    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "pang") {
            event.reply("Pong!");
        }
    });


    bot.on_ready([&bot](const dpp::ready_t & event) {
        if (dpp::run_once<struct clear_bot_commands>()) {
            /* Now, we're going to wipe our commands */
            bot.global_bulk_command_delete();
            /* This one requires a guild id, otherwise it won't know what guild's commands it needs to wipe! */
            bot.guild_bulk_command_delete(GUILD_ID);
        }
 
        /* Because the run_once above uses a 'clear_bot_commands' struct, you can continue to register commands below! */
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.guild_command_create(dpp::slashcommand("pang", "Ping pong!", bot.me.id), GUILD_ID);
        } 
    });

    bot.start(dpp::st_wait);
}
