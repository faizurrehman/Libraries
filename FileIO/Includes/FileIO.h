/**
 * @file FileIO.h
 * @author Faiz Ur Rehman
 * @brief Dynamic memory management library
 * @version 1.0
 * @date 2020-07-17
 *
 * @copyright Copyright (c) 2020
 *
 */


#ifndef FILEIO_H
#define FILEIO_H

/*	External header files *****************************************************/

#include <stdio.h>
#include <inttypes.h>

#include "FileIOAscii.h"
#include "FileIOBinary.h"

/*	External defines **********************************************************/
/*	External macros ***********************************************************/
/*	External enums ************************************************************/

/** \brief Enum for errors of FileIO library
 */
typedef enum
{
	eFileIOSuccess,
	eFileIOFileNotFound,
	eFileIOInvalidFormat,
	eFileIOInvalidArgument,
	eFileIOFileOpenFailure,
	eFileFileIOCloseFailure
}
eFileIOError_t;

/** \brief Enum for file types.
 */
typedef enum
{
	eBin,
	eTxt
}
eFileType_t;

/*	External typedefs *********************************************************/

typedef FILE xFileHandle_t;

/*	External structs **********************************************************/

typedef struct
{
	char* pucFileName;
	eFileType_t eFileType;
	xFileHandle_t* pxFileHandle;
}
xFile_t;

/*	External variables ********************************************************/
/*	External function prototypes **********************************************/

/** @brief create new file
 *
 * @param	pucFileName: Filename string
 * @param	eFileType: File type
 * @return	pxFile: pointer to created file structure
 *
 */
eFileIOError_t eFileIOCreateNewFile( char* pucFileName, eFileType_t eFileType, xFile_t* pxFile );
#endif

