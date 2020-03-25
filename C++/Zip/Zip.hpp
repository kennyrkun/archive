#ifndef ZIP_HPP
#define ZIP_HPP

#include <string>

// TODO: Design Choices
// Should functions have two parameters "Filename", and "Destination"
// Filename being the file in the archive, and destination being outside of the archive.
// For instance, should exrtactFileFromArchive extract to a specific destination and filename,
// or should it just extract to the working directory with the same filename?

// A wrapper for miniz ZIP library.
// Purpose: Use miniz more easily and with object orientation.
class Zip
{
public:
	enum Status
	{
		Fail = -1,
		Success = 1
	};
	
	Zip(std::string workingPath = "./");
	~Zip();

	// Will be inserted before all filenames. 
	std::string workingPath;

	// Creates a new empty archive at file name.
	int createArchive(std::string archiveName, std::string filename);

	// Add a single file to the archive
	// filename must include path.
	int addFileToArchive(std::string archiveName, std::string filename);

	// Remove a single file from the archive.
	// filename must include path.
	int removeFileFromArchive(std::string archiveName, std::string filename);
	
	// Add a single directory to the archive.
	// name must include path if archive is not top level.
	int addDirectoryToArchive(std::string archiveName, std::string name);
	// Removes a single directory from the archive by name.
	// name must include path if archive is not top level.
	int removeDirectoryFromArchive(std::string archiveName, std::string name, bool removeIfNotEmpty = false);

	// Decompresses the archive. Blocking unless run in another thread.
	int decompressArchive(std::string archiveName, std::string destination = "");

	// Extracts a specific file from the archive.
	// - Extracts to the working path. (If filename does not include paths (it should never))
	// - Exrtacts with the same filename.
	int extractFileFromArchive(std::string archiveName, std::string filename);
};

#endif // !ZIP_HPP
