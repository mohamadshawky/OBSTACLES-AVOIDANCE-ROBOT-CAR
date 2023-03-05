#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_
/*Options:
 * 			1- LOW_LEVEL
 * 			2- ON_CHANGE
 * 			3- FALLING_EDGE
 * 			4- RISING_EDGE
 */

#define INT0_SENSE		RISING_EDGE

/*Options:
 * 			1- ENABLE
 * 			2- DISABLE

 */

#define INT0_INITIAL_STATE 	ENABLE


/*Options:
 * 			1- LOW_LEVEL
 * 			2- ON_CHANGE
 * 			3- FALLING_EDGE
 * 			4- RISING_EDGE
 */
#define INT1_SENSE		RISING_EDGE

/*Options:
 * 			1- ENABLE
 * 			2- DISABLE
 */

#define INT1_INITIAL_STATE 	ENABLE


/*Options:
 * 			1- FALLING_EDGE
 * 			2- RISING_EDGE
 */
#define INT2_SENSE		RISING_EDGE

/*Options:
 * 			1- ENABLE
 * 			2- DISABLE
 */

#define INT2_INITIAL_STATE 	ENABLE

#define INT0				1
#define INT1				2
#define INT2				3
#endif
