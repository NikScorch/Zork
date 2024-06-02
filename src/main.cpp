#include "include/gamestate.h"

#include <QApplication>

// THIS IS NOT MY CODE - I STOLE THIS FROM CHATGPT BECAUSE DEBUGGING WAS HELL
// WHY ISNT THERE A STACKTRACE AFTER A SEGFAULT?????
#include <iostream>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
void sigsegv_handler(int sig) {
    std::cerr << "Caught segmentation fault (SIGSEGV)" << std::endl;
    
    const int max_frames = 64;

    void* frame_buffer[max_frames];
    int num_frames = backtrace(frame_buffer, max_frames);
    char** symbols = backtrace_symbols(frame_buffer, num_frames);


    if (symbols != nullptr) {
        for (int i = 0; i < num_frames; ++i) {
            std::cerr << symbols[i] << std::endl;

        }
        free(symbols);

    }

    _exit(EXIT_FAILURE); // Terminate the program

}

int main(int argc, char *argv[]) {
    // ALSO NOT MY CODE
    struct sigaction sa;
    sa.sa_handler = sigsegv_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGSEGV, &sa, nullptr);
    // EVERYTHING ELSE IS MY CODE FROM HERE ON

    srand(time(NULL));

    QApplication app(argc, argv);
    GameState *game = new GameState();
    game->show();
    return app.exec();
}

