#include "../include/loop-context.h"
#include <stdbool.h>
#include <stdlib.h>

// Function to inform if the context state is active.
bool isActive(loopContext_t *self) { return self->active; }
// Fucntion to change the context state to active.
void activeContext(loopContext_t *self) { self->active = true; }
// Fucntion to change the context state to inactive.
void deactiveContext(loopContext_t *self) { self->active = false; }
// Fucntion to get the context extra information.
void *getExtraInfo(loopContext_t *self) { return self->extraInfo; }

// Prepare the context statically.
void prepareContext(loopContext_t *self, void *extraInfo) {
  self->active = false;
  self->extraInfo = extraInfo;
  self->isActive = &isActive;
  self->activate = &activeContext;
  self->deactivate = &deactiveContext;
  self->getExtraInfo = &getExtraInfo;
}

// Dynamically creates a new context.
loopContext_t *newLoopContext(void *context) {
  loopContext_t *loopContext = malloc(sizeof(loopContext_t));
  prepareContext(loopContext, context);
  return loopContext;
}
