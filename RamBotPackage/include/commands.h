#ifndef COMMANDS_H
#define COMMANDS_H
#include <dpp/dpp.h>
#include <iostream>

namespace commands {
    void handleCommands(const dpp::slashcommand_t& event);
        std::vector<dpp::slashcommand> returnSlashCommands(dpp::cluster& bot);
};


#endif