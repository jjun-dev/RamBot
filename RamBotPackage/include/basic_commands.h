#ifndef BASIC_COMMANDS_H
#define BASIC_COMMANDS_H

#include <dpp/dpp.h>
#include <iostream>

namespace basicCommands {
    void handleCommands(const dpp::slashcommand_t& event);
};

#endif