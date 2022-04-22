// Defining the abstract struture which informs the current loop context.

#ifndef __M68K_LOOP_CONTEXT__
#define __M68K_LOOP_CONTEXT__

#include <stdbool.h>

// Structure which will represent loop context.
typedef struct loopContext {
  // Context state.
  bool active;
  void *extraInfo;
  // Functions to control the context state.
  bool (*isActive)(struct loopContext *);
  void (*activate)(struct loopContext *);
  void (*deactivate)(struct loopContext *);
  void *(*getExtraInfo)(struct loopContext *);
} loopContext_t;

// Prepare the context statically.
void prepareContext(loopContext_t *self, void *extraInfo);

// Dynamically creates a new context.
loopContext_t *newLoopContext(void *context);

#endif // __M68K_LOOP_CONTEXT__
