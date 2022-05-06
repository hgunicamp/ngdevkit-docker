// Defining the abstract struture which represents the main loop.

#ifndef __NG_DEVKIT_M68K_MAIN_LOOP__
#define __NG_DEVKIT_M68K_MAIN_LOOP__

#include <game-loop/loop-context.h>

// Structure which will represent the game loop.
typedef struct mainLoop {
  loopContext_t _context;
  loopContext_t *(*getContext)(struct mainLoop *);
  void (*_frame)(struct mainLoop *);
  void (*run)(struct mainLoop *);
  void (*stop)(struct mainLoop *);
} mainLoop_t;

// Main Loop static preparation.
void prepareMainLoop(mainLoop_t *mainLoop, void (*frame)(mainLoop_t *),
                     void *extraInfo);

mainLoop_t *newMainLoop(void(*frame), void *extraInfo);

#endif // __NG_DEVKIT_M68K_MAIN_LOOP__
