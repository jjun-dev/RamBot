#include <iostream>
#include <string>
#include "constants.h"
#include "commands.h"
#include "basic_commands.h"

const long int GUILD_ID = GI_1;

// on_slashcommand event handler
void commands::handleCommands(const dpp::slashcommand_t& event)
{
    const std::string& command = event.command.get_command_name();

    if(command == "test") {
        event.reply(dpp::message("Test Command"));
    } else if(command == "basic") {
        basicCommands::handleCommands(event);
    } else if(command == "join") {
        dpp::guild* g = dpp::find_guild(event.command.guild_id);
        if (!g->connect_member_voice(event.command.get_issuing_user().id)) {
            event.reply("Please join in a voice channel first.");
            return;
        }
        event.reply("Joined voice channel.");
    }

};

// on_ready event handler
std::vector<dpp::slashcommand> commands::returnSlashCommands(dpp::cluster& bot) {
    std::vector<dpp::slashcommand> commands;
    commands.push_back(
        dpp::slashcommand("test", "Test Command", bot.me.id)
    );
    commands.push_back(
        dpp::slashcommand("basic", "Basic Commands", bot.me.id)
        .add_option(dpp::command_option(dpp::co_string, "validity", "is valid?", true))
    );
    commands.push_back(
        dpp::slashcommand("join", "Join Voice Channel", bot.me.id)
    );
    return commands;
};

