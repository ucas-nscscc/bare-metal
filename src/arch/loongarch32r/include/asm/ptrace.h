#ifndef _ARCH_PTRACE_H
#define _ARCH_PTRACE_H

#include <types.h>

struct pt_regs {
	uint gpr[32];
	uint csr_crmd;
	uint csr_prmd;
	uint csr_ecfg;
	uint csr_estat;
};

#endif
