#include "include/gamestate.h"

#include <QApplication>

#ifdef DEBUG
#pragma message("Stacktrace code included")
// SOURCE/CREDIT: https://stackoverflow.com/questions/77005/how-to-automatically-generate-a-stacktrace-when-my-program-crashes
#include <stdio.h>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
void sigsegv_handler(int sig) {
  void *array[10];          // take max 10 references
  size_t size;              // how many traces are returned

  // get void*'s for 10 entries on the stack
  size = backtrace(array, 10);

  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);     // unpack traces and send to STDERR
  exit(1);                  // end program immediately
}
#endif

int main(int argc, char *argv[]) {
#ifdef DEBUG
    signal(SIGSEGV, sigsegv_handler);
#endif

    srand(time(NULL));

    QApplication app(argc, argv);
    GameState *game = new GameState();
    game->show();
    return app.exec();
}

