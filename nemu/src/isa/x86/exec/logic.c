#include "cpu/exec.h"
#include "cc.h"

make_EHelper(test) {
  /*pa2.2: test only modify EFLAGS*/
	rtl_and(&s0, &(id_dest->val), &(id_src->val));
	s1 = 0;
	rtl_set_OF(&s1);
	rtl_set_CF(&s1);
	rtl_update_ZF(&s0, id_dest->width);
	rtl_update_SF(&s0, id_dest->width);

  print_asm_template2(test);
}

make_EHelper(and) {
  /*pa2.2 just copy xor below*/
	rtl_and(&s0, &(id_dest->val), &(id_src->val));
	rtl_sr(id_dest->reg, &s0, id_dest->width);
	rtl_li(&s1, 0);
	rtl_set_OF(&s1);
	rtl_set_CF(&s1);
	rtl_update_ZF(&s0, id_dest->width);
	rtl_update_SF(&s0, id_dest->width);

	print_asm_template2(and);
}

make_EHelper(xor) {
	/*pa2.1*/
	rtl_and(&s0, &(id_dest->val), &(id_src->val));
	rtl_sr(id_dest->reg, &s0, id_dest->width);
	rtl_li(&s1, 0);
	rtl_set_OF(&s1);
	rtl_set_CF(&s1);
	rtl_update_ZF(&s0, id_dest->width);
	rtl_update_SF(&s0, id_dest->width);

  print_asm_template2(xor);
}

make_EHelper(or) {
	/*pa2.2*/
	rtl_or(&s0, &(id_dest->val), &(id_src->val));
	rtl_sr(id_dest->reg, &s0, id_dest->width);
	rtl_li(&s1, 0);
	rtl_set_OF(&s1);
	rtl_set_CF(&s1);
	rtl_update_ZF(&s0, id_dest->width);
	rtl_update_SF(&s0, id_dest->width);

  print_asm_template2(or);
}

make_EHelper(sar) {
  TODO();
  // unnecessary to update CF and OF in NEMU
	
  print_asm_template2(sar);
}

make_EHelper(shl) {
  TODO();
  // unnecessary to update CF and OF in NEMU

  print_asm_template2(shl);
}

make_EHelper(shr) {
  TODO();
  // unnecessary to update CF and OF in NEMU

  print_asm_template2(shr);
}

make_EHelper(setcc) {
  uint32_t cc = decinfo.opcode & 0xf;

  rtl_setcc(&s0, cc);
  operand_write(id_dest, &s0);

  print_asm("set%s %s", get_cc_name(cc), id_dest->str);
}

make_EHelper(not) {
  TODO();

  print_asm_template1(not);
}
