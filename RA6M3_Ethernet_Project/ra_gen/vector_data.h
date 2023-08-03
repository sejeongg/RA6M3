/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (3)
#endif
/* ISR prototypes */
void ether_eint_isr(void);
void r_icu_isr(void);

/* Vector table allocations */
#define VECTOR_NUMBER_EDMAC0_EINT ((IRQn_Type) 0) /* EDMAC0 EINT (EDMAC 0 interrupt) */
#define EDMAC0_EINT_IRQn          ((IRQn_Type) 0) /* EDMAC0 EINT (EDMAC 0 interrupt) */
#define VECTOR_NUMBER_ICU_IRQ11 ((IRQn_Type) 1) /* ICU IRQ11 (External pin interrupt 11) */
#define ICU_IRQ11_IRQn          ((IRQn_Type) 1) /* ICU IRQ11 (External pin interrupt 11) */
#define VECTOR_NUMBER_ICU_IRQ12 ((IRQn_Type) 2) /* ICU IRQ12 (External pin interrupt 12) */
#define ICU_IRQ12_IRQn          ((IRQn_Type) 2) /* ICU IRQ12 (External pin interrupt 12) */
#endif /* VECTOR_DATA_H */
