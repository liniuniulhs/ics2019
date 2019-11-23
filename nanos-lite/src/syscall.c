#include "common.h"
#include "syscall.h"

_Context* do_syscall(_Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1;

  switch (a[0]) {
		case SYS_exit:	printf("next: handle SYS_exit\n"); _halt(0); break;
		case SYS_yield:	printf("next: handle SYS_yield\n"); _yield(); break;
	
		default: panic("Unhandled syscall ID = %d", a[0]);break;
  }

  return NULL;
}
