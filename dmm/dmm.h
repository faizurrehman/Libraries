/**
 * @file dmm.h
 * @author Faiz Ur Rehman
 * @brief Dynamic memory management library
 * @version 1.0
 * @date 2020-07-04
 *
 * @copyright Copyright (c) 2020
 *
 */


#ifndef DMM_H
#define DMM_H

/*	External header files *****************************************************/

#include <inttypes.h>

/*	External defines **********************************************************/
/*	External macros ***********************************************************/
/*	External enums ************************************************************/

/** @brief Enum for error handling in DMM library
 */
typedef enum
{
	eDMMSuccess,
	eDMMMallocFail,
	eDMMReallocFail,
    eDMMOutOfMemory,
    eDMMInvalidArgument
}
eDmmError_t;

/*	External structs **********************************************************/
/*	External variables ********************************************************/
/*	External function prototypes **********************************************/

/** @brief allocate memory
 *
 * @param	ppPtr: address of the pointer to allocate memory
 * @param	ulSize: size of memory
 * @return	eDmmError_t: error status
 *
 */
eDmmError_t eDmmMalloc( void** ppPtr, uint32_t ulSize );

/** @brief re-allocate memory
 *
 * @param	ppPtr: address of the pointer to reallocate memory
 * @param	ulSize: size of memory
 * @return	eDmmError_t: error status
 *
 */
eDmmError_t eDmmRealloc( void** ppPtr, uint32_t ulSize );


/** @brief free allocated memory
 *
 * @param	ppPtr: address of the pointer to free memory
 * @return	eDmmError_t: error status
 *
 */
eDmmError_t eDmmFree( void** ppPtr );

#endif
