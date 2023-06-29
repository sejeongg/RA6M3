/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (10)
#endif
/* ISR prototypes */
void sci_uart_rxi_isr(void);
void sci_uart_txi_isr(void);
void sci_uart_tei_isr(void);
void sci_uart_eri_isr(void);
void r_icu_isr(void);
void can_error_isr(void);
void can_rx_isr(void);
void can_tx_isr(void);

/* Vector table allocations */
#define VECTOR_NUMBER_SCI0_RXI ((IRQn_Type) 0) /* SCI0 RXI (Receive data full) */
#define SCI0_RXI_IRQn          ((IRQn_Type) 0) /* SCI0 RXI (Receive data full) */
#define VECTOR_NUMBER_SCI0_TXI ((IRQn_Type) 1) /* SCI0 TXI (Transmit data empty) */
#define SCI0_TXI_IRQn          ((IRQn_Type) 1) /* SCI0 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI0_TEI ((IRQn_Type) 2) /* SCI0 TEI (Transmit end) */
#define SCI0_TEI_IRQn          ((IRQn_Type) 2) /* SCI0 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI0_ERI ((IRQn_Type) 3) /* SCI0 ERI (Receive error) */
#define SCI0_ERI_IRQn          ((IRQn_Type) 3) /* SCI0 ERI (Receive error) */
#define VECTOR_NUMBER_ICU_IRQ11 ((IRQn_Type) 4) /* ICU IRQ11 (External pin interrupt 11) */
#define ICU_IRQ11_IRQn          ((IRQn_Type) 4) /* ICU IRQ11 (External pin interrupt 11) */
#define VECTOR_NUMBER_CAN1_ERROR ((IRQn_Type) 5) /* CAN1 ERROR (Error interrupt) */
#define CAN1_ERROR_IRQn          ((IRQn_Type) 5) /* CAN1 ERROR (Error interrupt) */
#define VECTOR_NUMBER_CAN1_MAILBOX_RX ((IRQn_Type) 6) /* CAN1 MAILBOX RX (Reception complete interrupt) */
#define CAN1_MAILBOX_RX_IRQn          ((IRQn_Type) 6) /* CAN1 MAILBOX RX (Reception complete interrupt) */
#define VECTOR_NUMBER_CAN1_MAILBOX_TX ((IRQn_Type) 7) /* CAN1 MAILBOX TX (Transmission complete interrupt) */
#define CAN1_MAILBOX_TX_IRQn          ((IRQn_Type) 7) /* CAN1 MAILBOX TX (Transmission complete interrupt) */
#define VECTOR_NUMBER_CAN1_FIFO_RX ((IRQn_Type) 8) /* CAN1 FIFO RX (Receive FIFO interrupt) */
#define CAN1_FIFO_RX_IRQn          ((IRQn_Type) 8) /* CAN1 FIFO RX (Receive FIFO interrupt) */
#define VECTOR_NUMBER_CAN1_FIFO_TX ((IRQn_Type) 9) /* CAN1 FIFO TX (Transmit FIFO interrupt) */
#define CAN1_FIFO_TX_IRQn          ((IRQn_Type) 9) /* CAN1 FIFO TX (Transmit FIFO interrupt) */
#endif /* VECTOR_DATA_H */
