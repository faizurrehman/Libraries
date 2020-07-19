/**
 * @file dmm.c
 * @author Faiz Ur Rehman
 * @brief Dynamic memory management library
 * @version 1.0
 * @date 2020-07-04
 *
 * @copyright Copyright (c) 2020
 *
 */
/*	header files	***********************************************************/

#include "dmm.h"
#include <stdlib.h>

/*	Private defines ***********************************************************/
/*	Private macros ************************************************************/
/*	Private enums *************************************************************/
/*	Private structs	***********************************************************/
/*	Private variables *********************************************************/
/*	Private function prototypes ***********************************************/
/*	Private function definitions **********************************************/
/*	Eternal function definitions **********************************************/


eDmmError_t eDmmMalloc( void** ppPtr, uint32_t ulSize )
{
	if ( ( *ppPtr != NULL ) || ( ppPtr == NULL ))
	{
		return eDMMInvalidArgument;
	}

    *ppPtr = malloc( ulSize );

    if ( *ppPtr == NULL )
	{
		return eDMMMallocFail;
	}

	return eDMMSuccess;
}
/******************************************************************************/

eDmmError_t eDmmRealloc( void** ppPtr, uint32_t ulSize )
{
	void *pIntermediatePtr = NULL;

	if ( ( *ppPtr != NULL ) || ( ppPtr == NULL ))
	{
		return eDMMInvalidArgument;
	}

    pIntermediatePtr = realloc( *ppPtr, ulSize );

    if ( pIntermediatePtr == NULL )
	{
		return eDMMReallocFail;
	}
	*ppPtr = pIntermediatePtr;

	return eDMMSuccess;
}
/******************************************************************************/

eDmmError_t eDmmFree( void** ppPtr )
{
	if ( ppPtr == NULL )
	{
		return eDMMInvalidArgument;
	}

	free( ( void * ) *ppPtr );
	*ppPtr = NULL;

	return eDMMSuccess;
}
/******************************************************************************/
