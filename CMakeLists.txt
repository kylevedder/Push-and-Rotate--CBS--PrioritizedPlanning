cmake_minimum_required(VERSION 2.8)
project(ASearch)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2 -Wall -Wextra")
set(SOURCE_FILES
        agent.cpp
        agent_set.cpp
        conflict_avoidance_table.cpp
        conflict_based_search.cpp
        constraints_set.cpp
        prioritized_planning.cpp
        push_and_rotate.cpp
        tinyxml2.cpp
        xmllogger.cpp
        isearch.cpp
        mission.cpp
        map.cpp
        mdd.cpp
        dijkstra.cpp
        config.cpp
        astar.cpp
        main.cpp
        environmentoptions.cpp
        agent.h
        agent_move.h
        agent_set.h
        cbs_node.h
        conflict.h
        conflict_avoidance_table.h
        conflict_based_search.h
        constraint.h
        constraints_set.h
        multiagent_search_result.h
        prioritized_planning.h
        push_and_rotate.h
        tinyxml2.h
        node.h
        gl_const.h
        xmllogger.h
        isearch.h
        mission.h
        map.h
        ilogger.h
        dijkstra.h
        config.h
        astar.h
        searchresult.h
        environmentoptions.h
        )
add_executable(ASearch ${SOURCE_FILES})
