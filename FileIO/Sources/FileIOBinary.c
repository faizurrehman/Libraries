/**
 * @file FileIOBinary.c
 * @author Faiz Ur Rehman
 * @brief File IO management source file
 * @version 1.0
 * @date 2020-07-04
 *
 * @copyright Copyright (c) 2020
 *
 */
/*	header files	***********************************************************/

#include "../Includes/FileIOBinary.h"
#include "dmm.h"

#include <stdlib.h>
#include <string.h>

/*	Private defines ***********************************************************/
#define NULL_CHARACTER				( '\0' )

#define FILE_MODE_STRING_SIZE		( 2U )
#define BINARY_MODE_READ 			( "rb" )
#define BINARY_MODE_WRITE			( "wb" )
#define BINARY_MODE_APPEND			( "ab" )

#define BINARY_FILENAME_MAX_SIZE	( 250U )
#define BINARY_FULL_FILENAME_SIZE	( 256U )

/*	Private macros ************************************************************/
/*	Private enums *************************************************************/
/*	External typedefs *********************************************************/
/*	Private structs	***********************************************************/
/*	Private variables *********************************************************/
/*	Private function prototypes ***********************************************/

/** \brief validate and get filename
 *
 * \param pucFilename: filename
 * \return success or error
 *
 */
static eFileIOBinaryError_t eprvFileIOBinaryValidateAndGetFilename( char* pucFilename, eFileIOBinaryFormat_t eFileFormat, xFileBin_t* pxFile );

/** \brief set file mode
 *
 * \param eFileBinMode: binary file mode
 * \param pucMode: file mode string
 * \return success or error
 *
 */
static eFileIOBinaryError_t eprvFileIOBinarySetFileMode( eFileIOBinaryMode_t eFileBinMode, char* pucMode );


/** \brief get file format
 *
 * \param eFileFormat: fie mormat enum
 * \param pucFormat: string pointer to store format
 * \return success or error
 *
 */
static eFileIOBinaryError_t eprvFileIOBinaryGetFormat( eFileIOBinaryFormat_t eFileFormat, char* pucFormat );

/*	Private function definitions **********************************************/

static eFileIOBinaryError_t eprvFileIOBinaryValidateAndGetFilename( char* pucFilename, eFileIOBinaryFormat_t eFileFormat, xFileBin_t* pxFile )
{
	uint8_t usSize;
	eDmmError_t eDmmError;
	eFileIOBinaryError_t eFileError;

	if ( pucFilename == NULL )
	{
		return eBinInvalidArgument;
	}

    usSize = strlen( pucFilename );

    if ( usSize <= BINARY_FILENAME_MAX_SIZE )
	{
		return eBinSuccess;
	}

	eDmmError = eDmmMalloc( ( void** ) &pxFile->pucFilename, BINARY_FULL_FILENAME_SIZE );
	if ( eDmmError != eDMMSuccess )
	{
        return eBinOutOfMemory;
	}

    memset( pxFile->pucFilename, NULL_CHARACTER, BINARY_FILENAME_MAX_SIZE );
	memcpy( pxFile->pucFilename, pucFilename, BINARY_FILENAME_MAX_SIZE );

	eFileError = eprvFileIOBinaryGetFormat( eFileFormat, ( pxFile->pucFilename + strlen( pxFile->pucFilename ) ) );
	if ( eFileError != eBinSuccess )
	{
        return eFileError;
	}

	return eBinSuccess;

}
/*----------------------------------------------------------------------------*/

static eFileIOBinaryError_t eprvFileIOBinarySetFileMode( eFileIOBinaryMode_t eFileBinMode, char* pucMode )
{
	if ( pucMode == NULL )
	{
		return eBinInvalidArgument;
	}

	switch ( eFileBinMode )
	{
		case eBinRead:
		{
			memcpy( pucMode, BINARY_MODE_READ, FILE_MODE_STRING_SIZE );
			break;
		}
		case eBinWrite:
		{
			memcpy( pucMode, BINARY_MODE_WRITE, FILE_MODE_STRING_SIZE );
			break;
		}
		case eBinAppend:
		{
			memcpy( pucMode, BINARY_MODE_APPEND, FILE_MODE_STRING_SIZE );
			break;
		}
		default:
		{
			return eBinFileModeInvalid;
		}
	}
	return eBinSuccess;
}
/*----------------------------------------------------------------------------*/

static eFileIOBinaryError_t eprvFileIOBinaryGetFormat( eFileIOBinaryFormat_t eFileFormat, char* pucFormat )
{
	if ( pucFormat == NULL )
	{
		return eBinInvalidArgument;
	}

	switch ( eFileFormat )
	{
		// get enum, and copy the relative format string to the pointer
		#define X( a, b ) case a: memcpy( pucFormat, #b, strlen( #b ) );
			FileIOBinaryFormatTable
		#undef X
		default: return eBinFileFormatInvalid;
	}
	return eBinSuccess;
}
/*----------------------------------------------------------------------------*/

/*	Eternal function definitions **********************************************/

eFileIOBinaryError_t eFileIOBinaryGetFileHandle( char* pucFileName, eFileIOBinaryFormat_t eFileFormat, eFileIOBinaryMode_t eFileMode, xFileBin_t* pxFile )
{
	char ucMode[3] = {0};
	eFileIOBinaryError_t eFileError;

	if ( ( pucFileName == NULL ) || ( pxFile == NULL ) )
	{
		return eBinInvalidArgument;
	}
	memset( pxFile, NULL_CHARACTER, sizeof( xFileBin_t ) );

    // set file mode
    pxFile->eFileMode = eFileMode;

    // set filename
	eFileError = eprvFileIOBinaryValidateAndGetFilename( pucFileName, eFileFormat, pxFile );
	if( eFileError != eBinSuccess )
	{
		return eFileError;
	}

	// set file mode string to open file
	eFileError = eprvFileIOBinarySetFileMode( pxFile->eFileMode, ucMode );
	if( eFileError != eBinSuccess )
	{
		return eFileError;
	}

	// open file
	pxFile->xFileHandle = fopen( pxFile->pucFilename, ucMode );

	if ( pxFile->xFileHandle == NULL )
	{
		eDmmFree( ( void** ) pxFile->pucFilename );
		return eBinFileOpeningError;
	}
	return eBinSuccess;
}
/*----------------------------------------------------------------------------*/
