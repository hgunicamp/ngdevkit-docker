#include "../../include/game-loop/main-loop.h"
#include <ngdevkit/ng-video.h>
#include <stdlib.h>

// Retrieves the context structure for the current loop.
loopContext_t *getContext(mainLoop_t *self) { return &self->context; }

// Defines the behavior for each frame.
void mainLoopRun(mainLoop_t *self) {
  loopContext_t *context = self->getContext(self);
  context->activate(context);
  while (context->isActive(context)) {
    self->frame(self);
    // Wait until the end of the current frame time slice.
    ng_wait_vblank();
  }
}

// Informs that the current frame will be the last one in the loop.
void stopMainLoop(mainLoop_t *self) {
  loopContext_t *context = self->getContext(self);
  context->deactivate(context);
}

// Main Loop static preparation.
void prepareMainLoop(mainLoop_t *mainLoop, void (*frame)(mainLoop_t *),
                     void *extraInfo) {
  // Installing functions.
  prepareContext(mainLoop->getContext(mainLoop), extraInfo);
  mainLoop->getContext = getContext;
  mainLoop->frame = frame;
  mainLoop->run = mainLoopRun;
  mainLoop->stop = stopMainLoop;
}

// Main Loop constructor (Dynamic preparation).
mainLoop_t *newMainLoop(void(*frame), void *extraInfo) {
  mainLoop_t *mainLoop = malloc(sizeof(mainLoop_t));
  // Installing functions.
  prepareMainLoop(mainLoop, extraInfo, frame);
  // Game loop structure.
  return mainLoop;
}
