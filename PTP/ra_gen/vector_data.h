/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (4)
#endif
/* ISR prototypes */
void r_ptp_mint_isr(void);
void r_ptp_ipls_isr(void);
void edmac_eint_isr(void);
void ether_eint_isr(void);

/* Vector table allocations */
#define VECTOR_NUMBER_EPTPC_MINT ((IRQn_Type) 0) /* EPTPC MINT (SYNFP0/1 interrupt) */
#define EPTPC_MINT_IRQn          ((IRQn_Type) 0) /* EPTPC MINT (SYNFP0/1 interrupt) */
#define VECTOR_NUMBER_EPTPC_IPLS ((IRQn_Type) 1) /* EPTPC IPLS (STCA interrupt) */
#define EPTPC_IPLS_IRQn          ((IRQn_Type) 1) /* EPTPC IPLS (STCA interrupt) */
#define VECTOR_NUMBER_EPTPC_PINT ((IRQn_Type) 2) /* EPTPC PINT (PTPEDMAC interrupt) */
#define EPTPC_PINT_IRQn          ((IRQn_Type) 2) /* EPTPC PINT (PTPEDMAC interrupt) */
#define VECTOR_NUMBER_EDMAC0_EINT ((IRQn_Type) 3) /* EDMAC0 EINT (EDMAC 0 interrupt) */
#define EDMAC0_EINT_IRQn          ((IRQn_Type) 3) /* EDMAC0 EINT (EDMAC 0 interrupt) */
#endif /* VECTOR_DATA_H */
