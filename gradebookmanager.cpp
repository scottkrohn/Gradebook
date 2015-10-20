#include "gradebookmanager.h"
#include <algorithm>
#include <iostream>

GradebookManager::GradebookManager(const std::string &filename)
	: classnameFile(filename)
{
	loadClassnames();
}

bool GradebookManager::addClassname(const std::string &classname)
{
	// If the class name already exists, return false
	if(classExists(classname))
	{
		return false;
	}
	classnameList.push_back(classname);
	writeClassnames();
	return true;
}

bool GradebookManager::deleteClassname(const std::string &classname)
{
	// If the class doesn't exist, return false
	if(!classExists(classname))
	{
		return false;
	}
	std::vector<std::string>::iterator foundIter;
	foundIter = std::find(classnameList.begin(), classnameList.end(), classname);
	classnameList.erase(foundIter);
	writeClassnames();
	return true;
}

bool GradebookManager::loadClassnames()
{
	std::ifstream infile(classnameFile.c_str());
	// Was the file successfully opened?
	if(!infile)
	{
		return false;
	}

	std::string classname;
	while(std::getline(infile, classname))
	{
		classnameList.push_back(classname);
	}
	return true;
}

bool GradebookManager::writeClassnames() const
{
	std::ofstream outfile(classnameFile.c_str());
	if(!outfile)
	{
		return false;
	}
	for(std::vector<std::string>::const_iterator i = classnameList.begin();
		i != classnameList.end(); ++i)
	{
		outfile << *i << "\n";
	}
	return true;
}

bool GradebookManager::classExists(const std::string &classname)
{
	std::vector<std::string>::iterator foundIter;
	foundIter = std::find(classnameList.begin(), classnameList.end(), classname);
	// If the name wasn't found, return false
	if(foundIter == classnameList.end())
	{
		return false;
	}
	return true;
}

std::vector<std::string> GradebookManager::getClassnames() const
{
	return classnameList;
}

void GradebookManager::DEBUG_printClassnames() const
{
	std::cout << "DEBUG PRINT CLASS NAMES" << std::endl;
	for(std::vector<std::string>::const_iterator i = classnameList.begin();
		i != classnameList.end(); ++i)
	{
		std::cout << *i << std::endl;
	}
}
