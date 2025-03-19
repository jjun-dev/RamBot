#ifndef VOICE_COMMANDS_H
#define VOICE_COMMANDS_H

#include <dpp/dpp.h>

namespace voiceCommands {
    void handleCommands(const dpp::slashcommand_t& event, const std::string& command);
    void joinVoiceChannel(const dpp::slashcommand_t& event);
};

#endif