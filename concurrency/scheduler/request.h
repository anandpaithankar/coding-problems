#pragma once
#ifndef REQUEST_H
#define REQUEST_H

#include <string>

#include "abstract_request.h"

typedef void (*logFunction)(const std::string &text);

class Request : public AbstractRequest
{
    int _value;
    logFunction _logger;

public:
    void setValue(int value) override { _value = value; }
    void setOutput(logFunction func) { _logger = func; }
    void process() override;
    void finish() override;
};

#endif