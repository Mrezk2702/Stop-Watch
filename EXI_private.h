


#ifndef EXI_PRIVATE_H_

#define EXI_PRIVATE_H_


void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));
#define MCUCR *((u8 *) 0x55)
#define MCUCSR *((u8 *) 0x54)
#define GICR *((u8 *) 0x5B)
#define SREG *((u8*) 0x5f)
#define GIFR *((volatile u8 *)0x5A)


#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3


#endif
