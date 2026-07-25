#pragma once
#include "EventTypeEnum.h"

class Event
{
public:
    Event(EventType e);
    EventType eventType;
};