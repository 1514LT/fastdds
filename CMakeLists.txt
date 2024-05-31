
cmake_minimum_required(VERSION 3.20)

project("generated_code")
include_directories(/dataacquisition/lib
                    /usr/include/jsoncpp
                    ${CMAKE_CURRENT_SOURCE_DIR}
                    )   
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find requirements
find_package(fastcdr REQUIRED)
find_package(fastrtps 2.12 REQUIRED)

find_package(PkgConfig REQUIRED)
find_package(jsoncpp REQUIRED)

message(STATUS "Configuring DDSBase...")
add_library(DDSBase_lib 
            SHARED DDSBase.cxx 
            sqlite3/sqlite3.c 
            DDSBasePubSubTypes.cxx 
            DDSBasePublisher.cxx 
            DDSBaseSubscriber.cxx 
            DDSBasePubSubMain.cxx
            SQLite.cpp
            )
target_link_libraries(DDSBase_lib 
                      jsoncpp 
                      /dataacquisition/lib/libdata_shared.so
                      )

add_executable(DDSServer 
DDSServer.cpp
)

target_link_libraries(DDSServer 
                      fastcdr 
                      fastrtps 
                      /dataacquisition/lib/libdata_shared.so
                      dl
                      DDSBase_lib 
                      )

add_executable(DDSClient 
DDSClient.cpp
)

target_link_libraries(DDSClient 
                      fastcdr 
                      fastrtps 
                      /dataacquisition/lib/libdata_shared.so
                      dl
                      DDSBase_lib 
                      )

add_executable(main 
main.cpp
)

target_link_libraries(main 
                      fastcdr 
                      fastrtps 
                      /dataacquisition/lib/libdata_shared.so
                      dl
                      DDSBase_lib 
                      )
