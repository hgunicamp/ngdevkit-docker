// Defining the abstract struture which represents the initialization process.

#ifndef __NG_DEVKIT_M68K_INIT_PROCESS__
#define __NG_DEVKIT_M68K_INIT_PROCESS__

// Structure which will represent the initialization process step.
typedef struct initStep {
  // State properties.
  void (*internalFunct)(void *args);
  void *args;
  struct initStep *nextStep;
  // Methods references.
  struct initStep *(*setNext)(struct initStep *, struct initStep *);
  void (*run)(struct initStep *);
  // Private method.
  void (*_runChainStep)(struct initStep *);
} initStep_t;

// Prepare the init step.
struct initStep *prepareStep(initStep_t *self, void(*stepFunct), void *args);

// Prepare the guard step.
struct initStep *prepareGuardStep(initStep_t *self);

// Initialization step constructor.
struct initStep *newInitstep(void(*stepFunct), void *args);

#endif // __NG_DEVKIT_M68K_INIT_PROCESS__
