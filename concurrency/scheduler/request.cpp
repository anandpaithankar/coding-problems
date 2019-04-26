#include "request.h"

void Request::process()
{
    _logger("Starting processing of a request " + std::to_string(_value) + "...");
}

void Request::finish()
{
    _logger("Finished request " + std::to_string(_value));
}