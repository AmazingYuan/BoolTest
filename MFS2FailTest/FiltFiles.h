#pragma once
#include <string>
class FiltFiles : public TraverseFolder
{
private:
	std::string writeloc;
public:
	void TraverseFiles();
	FiltFiles(std::string, std::string, std::string);
	~FiltFiles();
};

