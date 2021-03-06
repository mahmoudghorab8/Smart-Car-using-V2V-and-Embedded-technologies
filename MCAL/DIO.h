

#ifndef DIO_H_
#define DIO_H_

#define SET_BIT(Register,Pin)       (Register |=(1<<Pin))
#define CLEAR_BIT(Register,Pin)     (Register &=~(1<<Pin))
#define TOGGLE_BIT(Register,Pin)	(Register ^=(1<<Pin))
#define BIT_SET(Register,Pin)       (Register &(1<<Pin))
#define BIT_CLEARED(Register,Pin)   (!(Register &(1<<Pin)))


#endif /* DIO_H_ */
