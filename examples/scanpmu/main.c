#include "types.h"
#include "console_vga.h"
#include "intr.h"
#include "msr.h"

int
main(void)
{
   ConsoleVGA_Init();
   Intr_Init();
   Intr_SetFaultHandlers(Console_UnhandledFault);

   uint64 val = rdmsr(0x1D9);
   Console_Format("IA32_DEBUGCTL %x\n", val);
   val = rdmsr(0x345);
   Console_Format("IA32_PERF_CAPABILITIES %x\n", val);
	    

   Console_Flush();
   
   return 0;
}
