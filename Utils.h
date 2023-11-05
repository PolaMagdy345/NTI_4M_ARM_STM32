/*******************************************/
/*		Author	: Pola Magdy			   */
/*		Version	: V01					   */
/*		Date	: 1/10/2023				   */
/*     Description: Utils.h 		       */
/*******************************************/

#ifndef UTILS_H_
#define UTILS_H_

#define READ_BIT(reg,bit)    ((reg>>bit)&1)
#define SET_BIT(reg,bit)    (reg=reg|(1<<bit))
#define CLR_BIT(reg,bit)    (reg=reg&(~(1<<bit)))
#define TGL_BIT(reg,bit)    (reg=reg^(1<<bit))


#endif /* UTILS_H_ */