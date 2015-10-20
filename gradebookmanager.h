#ifndef GRADEBOOKMANAGER_H
#define GRADEBOOKMANAGER_H
//#include "gradebook.h"
#include <string>
#include <fstream>
#include <vector>

class GradebookManager
{
public:
	GradebookManager(const std::string &filename);

	bool addClassname(const std::string &classname);
	bool deleteClassname(const std::string &classname);
	bool classExists(const std::string &classname);
	std::vector<std::string> getClassnames() const;

	// DEBUG FUNCTIONS
	void DEBUG_printClassnames() const;
private:
	std::string classnameFile;
	std::vector<std::string> classnameList;

	// Utility functions
	bool loadClassnames();
	bool writeClassnames() const;
};
#endif
