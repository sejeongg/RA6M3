/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (6)
#endif
/* ISR prototypes */
void ether_eint_isr(void);
void r_icu_isr(void);
void agt_int_isr(void);

/* Vector table allocations */
#define VECTOR_NUMBER_EDMAC0_EINT ((IRQn_Type) 0) /* EDMAC0 EINT (EDMAC 0 interrupt) */
#define EDMAC0_EINT_IRQn          ((IRQn_Type) 0) /* EDMAC0 EINT (EDMAC 0 interrupt) */
#define VECTOR_NUMBER_ICU_IRQ11 ((IRQn_Type) 1) /* ICU IRQ11 (External pin interrupt 11) */
#define ICU_IRQ11_IRQn          ((IRQn_Type) 1) /* ICU IRQ11 (External pin interrupt 11) */
#define VECTOR_NUMBER_AGT0_INT ((IRQn_Type) 2) /* AGT0 INT (AGT interrupt) */
#define AGT0_INT_IRQn          ((IRQn_Type) 2) /* AGT0 INT (AGT interrupt) */
#define VECTOR_NUMBER_ICU_IRQ12 ((IRQn_Type) 3) /* ICU IRQ12 (External pin interrupt 12) */
#define ICU_IRQ12_IRQn          ((IRQn_Type) 3) /* ICU IRQ12 (External pin interrupt 12) */
#define VECTOR_NUMBER_ICU_IRQ13 ((IRQn_Type) 4) /* ICU IRQ13 (External pin interrupt 13) */
#define ICU_IRQ13_IRQn          ((IRQn_Type) 4) /* ICU IRQ13 (External pin interrupt 13) */
#define VECTOR_NUMBER_ICU_IRQ14 ((IRQn_Type) 5) /* ICU IRQ14 (External pin interrupt 14) */
#define ICU_IRQ14_IRQn          ((IRQn_Type) 5) /* ICU IRQ14 (External pin interrupt 14) */
#endif /* VECTOR_DATA_H */
