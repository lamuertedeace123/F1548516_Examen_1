/* Dirección base del puerto 0 */
#define PORT0_BASE 0x50000000UL

/* Registros del PORT0 */
#define PORT0_OUT      (*(volatile uint32_t *)(PORT0_BASE + 0x504))
#define PORT0_OUTSET   (*(volatile uint32_t *)(PORT0_BASE + 0x508))
#define PORT0_OUTCLR   (*(volatile uint32_t *)(PORT0_BASE + 0x50C))
#define PORT0_IN       (*(volatile uint32_t *)(PORT0_BASE + 0x510))
#define PORT0_DIR      (*(volatile uint32_t *)(PORT0_BASE + 0x514))
#define PORT0_DIRSET   (*(volatile uint32_t *)(PORT0_BASE + 0x518))
#define PORT0_DIRCLR   (*(volatile uint32_t *)(PORT0_BASE + 0x51C))
