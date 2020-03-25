#include "Zip.hpp"

#if defined(__GNUC__)
	// Ensure we get the 64-bit variants of the CRT's file I/O calls
	#ifndef _FILE_OFFSET_BITS
		#define _FILE_OFFSET_BITS 64
	#endif

	#ifndef _LARGEFILE64_SOURCE
		#define _LARGEFILE64_SOURCE 1
	#endif
#endif

#include "miniz.h"

#include <stdio.h>
#include <iostream>
#include <filesystem>

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint;

Zip::Zip(std::string workingPath) : workingPath(workingPath)
{
	std::cout << "miniz.c version: " << MZ_VERSION << ", working path: " << workingPath << std::endl;
}

Zip::~Zip()
{
}

int Zip::createArchive(std::string archiveName, std::string filename)
{
	// TODO: figure out how to make an archive

	return 0;
}

int Zip::addFileToArchive(std::string archiveName, std::string filename)
{
	mz_zip_archive zip_archive;
	mz_bool operation_success;

	// convert the file name to a cstring so that miniz can read it
	std::string temp_filename = workingPath + archiveName;
	const char *archiveFilename = temp_filename.c_str();

	// allocate space on the heap for the archive
	memset(&zip_archive, 0, sizeof(zip_archive));

	operation_success = mz_zip_reader_init_file(&zip_archive, archiveFilename, 0);
	if (!operation_success)
	{
		std::cerr << "mz_zip_reader_init_file() failed!" << std::endl;
		mz_zip_reader_end(&zip_archive);
		return Fail;
	}

	// TODO: see example2.c

	mz_zip_reader_end(&zip_archive);
	return Success;
}

int Zip::removeFileFromArchive(std::string archiveName, std::string filename)
{
	mz_zip_archive zip_archive;
	mz_bool operation_success;

	// convert the file name to a cstring so that miniz can read it
	std::string temp_filename = workingPath + archiveName;
	const char *archiveFilename = temp_filename.c_str();

	// allocate space on the heap for the archive
	memset(&zip_archive, 0, sizeof(zip_archive));

	operation_success = mz_zip_reader_init_file(&zip_archive, archiveFilename, 0);
	if (!operation_success)
	{
		std::cerr << "mz_zip_reader_init_file() failed!" << std::endl;
		mz_zip_reader_end(&zip_archive);
		return Fail;
	}

	// TODO: miniz does not provide a way to remove a file from an archive.
	// in order to do this, we might try decompressing the archive,
	// then compressing the archive with 

	mz_zip_reader_end(&zip_archive);
	return Success;
}

int Zip::addDirectoryToArchive(std::string archiveName, std::string name)
{
	std::cout << "adding directory " << name << " to archive" << std::endl;

	mz_zip_archive zip_archive;
	mz_bool operation_success;

	// convert the file name to a cstring so that miniz can read it
	std::string temp_filename = workingPath + archiveName;
	const char *archiveFilename = temp_filename.c_str();

	// allocate space on the heap for the archive
	memset(&zip_archive, 0, sizeof(zip_archive));

	operation_success = mz_zip_reader_init_file(&zip_archive, archiveFilename, 0);
	if (!operation_success)
	{
		std::cerr << "mz_zip_reader_init_file() failed!" << std::endl;
		mz_zip_reader_end(&zip_archive);
		return Fail;
	}

	// TODO: this is an in place operation, might fuck us if something goes wrong.
	// TODO: more than top level
	operation_success = mz_zip_add_mem_to_archive_file_in_place(archiveFilename, "name", NULL, 0, "no comment", (uint16)strlen("no comment"), MZ_BEST_COMPRESSION);
	if (!operation_success)
	{
		std::cerr << "mz_zip_add_mem_to_archive_file_in_place() failed!" << std::endl;
		mz_zip_reader_end(&zip_archive);
		return Fail;
	}

	// TODO: see example2.c

	mz_zip_reader_end(&zip_archive);
	return Success;
}

int Zip::removeDirectoryFromArchive(std::string archiveName, std::string name, bool removeIfNotEmpty)
{
	mz_zip_archive zip_archive;
	mz_bool operation_success;

	// convert the file name to a cstring so that miniz can read it
	std::string temp_filename = workingPath + archiveName;
	const char *archiveFilename = temp_filename.c_str();

	// allocate space on the heap for the archive
	memset(&zip_archive, 0, sizeof(zip_archive));

	operation_success = mz_zip_reader_init_file(&zip_archive, archiveFilename, 0);
	if (!operation_success)
	{
		std::cout << "mz_zip_reader_init_file() failed!" << std::endl;
		mz_zip_reader_end(&zip_archive);
		return Fail;
	}

	// TODO: see example2.c

	mz_zip_reader_end(&zip_archive);
	return Success;
}

int Zip::decompressArchive(std::string archiveName, std::string destination)
{
	std::cout << "decompressing " << archiveName << " to " << (destination.empty() ? destination = archiveName.substr(0, archiveName.rfind('.')) : destination) << std::endl;

	if (!std::experimental::filesystem::exists(workingPath + destination))
	{
		try
		{
			std::experimental::filesystem::create_directories(workingPath + destination);
		}
		catch (const std::exception& e)
		{
			std::cerr << "failed to create destination directory: " << std::endl;
			std::cerr << "> " << e.what() << std::endl;

			return Fail;
		}
	}

	mz_zip_archive zip_archive;
	mz_bool operation_success;

	std::string temp_ArchiveFilename = workingPath + archiveName;
	const char *archiveFilename = temp_ArchiveFilename.c_str();

	// allocate space on the heap for the archive
	memset(&zip_archive, 0, sizeof(zip_archive));

	operation_success = mz_zip_reader_init_file(&zip_archive, archiveFilename, 0);
	if (!operation_success)
	{
		std::cerr << "mz_zip_reader_init_file() failed!" << std::endl;
		mz_zip_reader_end(&zip_archive);
		return Fail;
	}

	for (int i = 0; i < (int)mz_zip_reader_get_num_files(&zip_archive); i++)
	{
		if (!mz_zip_reader_is_file_supported(&zip_archive, i))
		{
			std::cout << "feature is not supported, skipping" << std::endl;
			continue;
		}

		mz_zip_archive_file_stat file_stat;
		if (!mz_zip_reader_file_stat(&zip_archive, i, &file_stat))
		{
			std::cerr << "mz_zip_reader_file_stat() failed, skipping " << i << std::endl;
			continue;
		}

		std::string temp_filename = workingPath;

		// we do this because miniz does not extract directories
		if (mz_zip_reader_is_file_a_directory(&zip_archive, i))
		{
			if (!std::experimental::filesystem::exists(workingPath + destination + "/" + file_stat.m_filename))
			{
				std::experimental::filesystem::create_directories(workingPath + destination + "/" + file_stat.m_filename);
			}
		}
		else
		{
			temp_filename += destination + "/" += file_stat.m_filename;

			// this function extracts only files
			if (!mz_zip_reader_extract_to_file(&zip_archive, i, temp_filename.c_str(), 0))
			{
				std::cerr << "failed to extract " << file_stat.m_filename << ", skipping." << std::endl;
			}
		}
	}

	mz_zip_reader_end(&zip_archive);
	return Success;
}

int Zip::extractFileFromArchive(std::string archiveName, std::string filename)
{
	std::cout << "extracting " << filename << " from " << workingPath + archiveName << std::endl;

	mz_zip_archive zip_archive;
	mz_bool operation_success;

	// convert the file name to a cstring so that miniz can read it
	std::string temp_filename = workingPath + archiveName;
	const char *archiveFilename = temp_filename.c_str();

	// allocate space on the heap for the archive
	memset(&zip_archive, 0, sizeof(zip_archive));

	operation_success = mz_zip_reader_init_file(&zip_archive, archiveFilename, 0);
	if (!operation_success)
	{
		std::cerr << "mz_zip_reader_init_file() failed!" << std::endl;

		mz_zip_reader_end(&zip_archive);
		return Fail;
	}

	for (int i = 0; i < (int)mz_zip_reader_get_num_files(&zip_archive); i++)
	{
		mz_zip_archive_file_stat file_stat;
		if (!mz_zip_reader_file_stat(&zip_archive, i, &file_stat))
		{
			std::cerr << "mz_zip_reader_file_stat() failed!" << std::endl;

			mz_zip_reader_end(&zip_archive);
			return Fail;
		}

		// TODO: find a better way to do this
		// see mz_zip_reader_locate_file
		if (filename == file_stat.m_filename)
		{
			std::string temp_filename = workingPath + filename;

			if (!mz_zip_reader_extract_to_file(&zip_archive, i, temp_filename.c_str(), 0))
			{
				std::cerr << "failed to extract file" << std::endl;

				mz_zip_reader_end(&zip_archive);
				return Fail;
			}

			break;
		}
	}

	mz_zip_reader_end(&zip_archive);
	return Success;
}
 