set(SOURCES
    client.cpp
    computer_club_params.cpp
    computer_club.cpp
    time.cpp
    event_queue.cpp
    event.cpp
    incoming_events.cpp
    outgoing_events.cpp
    table.cpp
    time.cpp
)

add_library(${PROJECT_NAME}Lib STATIC ${SOURCES} ${INCLUDES})
