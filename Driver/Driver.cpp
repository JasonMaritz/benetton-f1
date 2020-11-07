#include "Driver.h"

Driver::Driver(string name)
{
	Name = name;
}

void Driver::generateReport()
{

}

void Driver::setResult(Result* result)
{
	this->result = result;
}
