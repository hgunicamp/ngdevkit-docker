#include "../../include/game-loop/init-process.h"
#include <stddef.h>
#include <stdlib.h>

// Executes the chained initialization steps recursively.
void _runChainStep(initStep_t *self) {
  self->run(self);
  initStep_t *nextStep = self->nextStep;
  if (NULL == nextStep) {
    return;
  }
  _runChainStep(nextStep);
}

initStep_t *_setNextStep(initStep_t *self, initStep_t *nextStep) {
  self->nextStep = nextStep;
  return nextStep;
}

// Prepare the init step.
initStep_t *prepareStep(initStep_t *self, void(*stepFunct), void *args) {
  self->run = stepFunct;
  self->args = args;
  self->nextStep = NULL;
  self->setNext = _setNextStep;
  self->_runChainStep = _runChainStep;
  return self;
}

// Function to trigger the chained execution.
void _pass(initStep_t *self) { self->_runChainStep(self->nextStep); }

// Initial step in the initialization chain.
initStep_t *prepareGuardStep(initStep_t *self) {
  return prepareStep(self, _pass, NULL);
}

// Initialization step constructor.
initStep_t *newInitstep(void(*stepFunct), void *args) {
  initStep_t *initStep = malloc(sizeof(initStep_t));
  // Preparing the stage.
  prepareStep(initStep, stepFunct, args);
  // Initialization step.
  return initStep;
}
