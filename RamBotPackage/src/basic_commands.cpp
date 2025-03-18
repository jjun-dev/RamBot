#include "basic_commands.h"
#include <iostream>

void basicCommands::handleCommands(const dpp::slashcommand_t& event) {

    std::string parameter = std::get<std::string>(event.get_parameter("validity"));
    std::cout << "Parameter: " << parameter << std::endl;
    
    if(parameter == "valid") {
        event.reply(dpp::message("Valid Parameter"));
    } else {
        event.reply(dpp::message("Invalid Parameter"));
    }
}

