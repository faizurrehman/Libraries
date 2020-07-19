/**
 * @file FileIOBinary.h
 * @author Faiz Ur Rehman
 * @brief Dynamic memory management library
 * @version 1.0
 * @date 2020-07-17
 *
 * @copyright Copyright (c) 2020
 *
 */


#ifndef FILEIOBINARY_H
#define FILEIOBINARY_H

/*	External header files *****************************************************/

#include "FileIO.h"

/*	External defines **********************************************************/
/*	External macros ***********************************************************/

/**
 *@brief Binary file formate table using Xmacro for scalability
 */
#define FileIOBinaryFormatTable	\
			X( eDotBin, ".bin")	\
			X( eDotAut, ".aut")

/*	External enums ************************************************************/

typedef enum
{
 eBinSuccess,
 eBinOutOfMemory,
 eBinFileNotFound,
 eBinFileModeInvalid,
 eBinInvalidArgument,
 eBinFileOpeningError,
 eBinFileClosingError,
 eBinSetFilenameError,
 eBinFileFormatInvalid
}
eFileIOBinaryError_t;

/**
 *@brief Binary file format enum expansion
 */
typedef enum
{
	#define X( a, b ) a,
		FileIOBinaryFormatTable
	#undef X
}
eFileIOBinaryFormat_t;

typedef enum
{
 eBinRead,
 eBinWrite,
 eBinAppend
}
eFileIOBinaryMode_t;

/*	External typedefs *********************************************************/

typedef FILE* xFileBinHandle_t;

/*	External structs **********************************************************/

typedef struct
{
    char* pucFilename;
    xFileBinHandle_t xFileHandle;
    eFileIOBinaryMode_t eFileMode;
}
xFileBin_t;

/*	External variables ********************************************************/
/*	External function prototypes **********************************************/

/** @brief Open binary file to read
 *
 * @param	pucFileName: Filename
 * @param	eFileMode: File mode
 * @return	pxFile: pointer of created file structure
 *
 */
//eFileIOBinaryError_t eFileIOBinaryGetFileHandle( char* pucFileName,eFileIOBinaryMode_t eFileMode, xFileBin_t* pxFile );

#endif

