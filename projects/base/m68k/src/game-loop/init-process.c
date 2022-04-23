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

// Clean initialization steps recursively.
void _cleanChainStep(initStep_t *self) {
  initStep_t *previousStep = self->previousStep;
  if (NULL == previousStep) {
    return;
  }
  // Clearing the current step.
  free(self);
  // Next chain iteration.
  _cleanChainStep(previousStep);
}

// Fluent set next stage function.
initStep_t *_setNextStep(initStep_t *self, initStep_t *nextStep) {
  self->nextStep = nextStep;
  nextStep->previousStep = self;
  return nextStep;
}

// Prepare the init step.
initStep_t *prepareStep(initStep_t *self, void(*stepFunct), void *args) {
  self->run = stepFunct;
  self->args = args;
  self->nextStep = NULL;
  self->previousStep = NULL;
  self->setNext = _setNextStep;
  self->_runChainStep = _runChainStep;
  self->_cleanChainStep = _cleanChainStep;
  return self;
}

// Function to trigger the chained execution.
void _pass(initStep_t *self) { self->_runChainStep(self->nextStep); }

// Initial step in the initialization chain.
initStep_t *prepareGuardStep(initStep_t *self) {
  return prepareStep(self, _pass, NULL);
}

// Trigger the reflection clean up process.
void _cleanReflection(initStep_t *self) { self->_cleanChainStep(self); }

// Prepare the clean reflection step.
initStep_t *prepareCleanReflectionStep() {
  return newInitstep(_cleanReflection, NULL);
}

// Initialization step constructor.
initStep_t *newInitstep(void(*stepFunct), void *args) {
  initStep_t *initStep = malloc(sizeof(initStep_t));
  // Preparing the stage.
  return prepareStep(initStep, stepFunct, args);
}
