#pragma once

enum class EventType
{
    CollisionEvent,
    AudioEvent  
};

class Event
{
public:
    Event(EventType e);
    EventType eventType;
};