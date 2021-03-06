#include <am.h>
#include <amdev.h>
#include <nemu.h>

#define KEYDOWN_MASK 0x8000

size_t __am_input_read(uintptr_t reg, void *buf, size_t size) {
  switch (reg) {
    case _DEVREG_INPUT_KBD: {
      _DEV_INPUT_KBD_t *kbd = (_DEV_INPUT_KBD_t *)buf;
      kbd->keydown = 0;
      //kbd->keydown = (inl(KBD_ADDR) & 0x8000)==0 ? 0 : 1;
			//kbd->keycode = _KEY_NONE;
      kbd->keycode = inl(KBD_ADDR);
			return sizeof(_DEV_INPUT_KBD_t);
    }
  }
  return 0;
}
