cmake_minimum_required(VERSION 3.3)

# This entire CMakeLists.txt is based on the great sample project at: 
#
#   https://github.com/ComicSansMS/GhulbusBase/
#

project(timeseries)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TIMESERIES_BASE_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(TIMESERIES_BASE_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(TIMESERIES_BASE_TEST_DIR ${PROJECT_SOURCE_DIR}/test)

set(TIMESERIES_BASE_HEADER_FILES
    ${TIMESERIES_BASE_INCLUDE_DIR}/TimeSeriesUtils.hpp
)

set(TIMESERIES_BASE_SOURCE_FILES
    ${TIMESERIES_BASE_SOURCE_DIR}/TimeSeriesUtils.cpp
)

set(TIMESERIES_BASE_TEST_SOURCES
    ${TIMESERIES_BASE_TEST_DIR}/TimeSeriesUtilsTestBase.cpp
    ${TIMESERIES_BASE_TEST_DIR}/SimilarityMeasuresTest.cpp
)

add_library(ts ${TIMESERIES_BASE_SOURCE_FILES} ${TIMESERIES_BASE_HEADER_FILES})

option(TIMESERIES_BUILD_TESTS "Determines wether to build tests." ON)
if(TIMESERIES_BUILD_TESTS)
    enable_testing()

    if(NOT TARGET Catch)
        
        include(ExternalProject)
    
        set(TIMESERIES_FETCH_EXTERNAL_CATCH
            URL https://github.com/philsquared/Catch/archive/v1.2.1-develop.12.zip
            URL_HASH MD5=cda228922a1c9248364c99a3ff9cd9fa)
            
        ExternalProject_Add(Catch-External
            PREFIX ${CMAKE_BINARY_DIR}/external/Catch
                ${TIMESERIES_FETCH_EXTERNAL_CATCH}
                CONFIGURE_COMMAND ""
                BUILD_COMMAND ""
                INSTALL_COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/external/Catch/src/Catch-External/single_include/catch.hpp
                                                         ${CMAKE_BINARY_DIR}/external/Catch/include/catch.hpp
        ) 
        add_library(Catch INTERFACE)
        add_dependencies(Catch Catch-External)
        target_include_directories(Catch INTERFACE ${CMAKE_BINARY_DIR}/external/Catch/include)
    endif()
    
    add_executable(ts_test ${TIMESERIES_BASE_TEST_SOURCES})
    target_link_libraries(ts_test ts Catch)
    
endif()  