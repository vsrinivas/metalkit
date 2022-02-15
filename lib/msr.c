#include "types.h"

uint64 rdmsr(uint32 msr) {
	uint64 val;
	asm volatile("rdmsr" : "=A"(val) : "c"(msr));
	return val;
}

void wrmsr(uint32 msr, uint64 val) {
	asm volatile("wrmsr" :: "c"(msr), "A"(val));
}
