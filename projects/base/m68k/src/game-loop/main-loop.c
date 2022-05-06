#include <game-loop/main-loop.h>
#include <ngdevkit/ng-video.h>
#include <stdlib.h>

// Retrieves the context structure for the current loop.
loopContext_t *_getContext(mainLoop_t *self) { return &self->_context; }

// Defines the behavior for each frame.
void _mainLoopRun(mainLoop_t *self) {
  loopContext_t *context = self->getContext(self);
  context->activate(context);
  while (context->isActive(context)) {
    self->_frame(self);
    // Wait until the end of the current frame time slice.
    ng_wait_vblank();
  }
}

// Informs that the current frame will be the last one in the loop.
void _stopMainLoop(mainLoop_t *self) {
  loopContext_t *context = self->getContext(self);
  context->deactivate(context);
}

// Main Loop static preparation.
void prepareMainLoop(mainLoop_t *mainLoop, void (*frame)(mainLoop_t *),
                     void *extraInfo) {
  // Installing functions.
  prepareContext(mainLoop->getContext(mainLoop), extraInfo);
  mainLoop->getContext = _getContext;
  mainLoop->_frame = frame;
  mainLoop->run = _mainLoopRun;
  mainLoop->stop = _stopMainLoop;
}

// Main Loop constructor (Dynamic preparation).
mainLoop_t *newMainLoop(void(*frame), void *extraInfo) {
  mainLoop_t *mainLoop = malloc(sizeof(mainLoop_t));
  // Installing functions.
  prepareMainLoop(mainLoop, frame, extraInfo);
  // Game loop structure.
  return mainLoop;
}
