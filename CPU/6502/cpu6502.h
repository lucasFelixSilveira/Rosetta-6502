#ifndef CPU6502_H
#define CPU6502_H

#include "../../config/config.h"

/* 
   CPU6502 - 6502 Emulated CPU

   This file implements the CPU (Central Processing Unit) functionality for the MOS Technology 6502.

   The MOS Technology 6502 is a widely used 8-bit microprocessor, and this implementation provides
   functions for initializing the CPU, fetching bytes and words from memory, and stack manipulation.

   This file implement instructions for functions defined in cpu6502.h

   For more information about the instructions and addressing modes, refer to Instructions.MD
*/ 


/* 
   StatusFlags - Status Flags for the CPU6502
   
   The structure defines individual status flags as bits in the Status Register (PS)
*/ 


typedef struct StatusFlags
{	
	Byte C : 1;	  // 0: Carry Flag	
	Byte Z : 1;	  // 1: Zero Flag
	Byte I : 1; 	  // 2: Interrupt disable
	Byte D : 1; 	  // 3: Decimal mode
	Byte B : 1; 	  // 4: Break
	Byte Unused : 1;  // 5: Unused
	Byte V : 1; 	  // 6: Overflow
	Byte N : 1; 	  // 7: Negative
} StatusFlags ;


/* 
   CPU6502 - CPU Structure for the MOS Technology 6502
   
   The structure represents the CPU state for the MOS Technology 6502.
*/

typedef struct {
    Byte A, X, Y;   // registers
    Byte SP;        // stack pointer
    Word PC;        // program counter
    Byte S;         // status

    union // processor status
	{
		Byte PS;	// Processor Status (PC)
		StatusFlags Flag; // Flags 
	};
} CPU6502;


// Reset:


// This function resets the CPU state to its initial values.
void resetCPU(Word ResetVector, CPU6502 *cpu, MEM6502 *memory);


// Fetch Data:


// This function fetches a byte of data from the memory using the program counter (PC).
Byte FetchByte(Word *Cycles, const MEM6502* memory, CPU6502 *cpu);

// This function fetches a 16-bit word of data from the memory using the program counter (PC).
Word FetchWord(Word *Cycles, const MEM6502* memory, CPU6502 *cpu);


// This function converts the Stack Pointer (SP) value to a memory address.
Word SPToAddress(CPU6502 *cpu);


// Stacks: 


// This function pushes a 16-bit word onto the stack.
void PushWordToStack(Word *Cycles, MEM6502 *memory, Word Value, CPU6502 *cpu);

// This function pushes the Program Counter (PC) onto the stack.
void PushPCToStack(Word *Cycles, MEM6502 *memory, CPU6502 *cpu);

// This function pops a 16-bit word from the stack.
Word PopWordFromStack(Word *Cycles, MEM6502 *memory, CPU6502 *cpu)


#endif // CPU6502_H
