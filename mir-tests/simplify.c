#include "../mir.h"

#include "api-loop.h"
#include "api-memop.h"

int main (void) {
  MIR_module_t m;
  MIR_item_t func1, func2;
  MIR_context_t ctx = MIR_init ();

  func1 = create_mir_func_with_loop (ctx, &m);
  func2 = create_mir_example2 (ctx, &m);
  MIR_simplify_func (ctx, func1, TRUE);
  MIR_simplify_func (ctx, func2, TRUE);
  fprintf (stderr, "Simplified code:\n");
  MIR_output (ctx, stderr);
  MIR_finish (ctx);
  return 0;
}
