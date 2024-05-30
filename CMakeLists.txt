
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
add_library(DDSBase_lib SHARED DDSBase.cxx )
target_link_libraries(DDSBase_lib jsoncpp /dataacquisition/lib/libdata_shared.so)

add_executable(DDSBase DDSBasePubSubTypes.cxx DDSBasePublisher.cxx DDSBaseSubscriber.cxx DDSBasePubSubMain.cxx )
target_link_libraries(DDSBase fastcdr fastrtps /dataacquisition/lib/libdata_shared.so dl
        DDSBase_lib )


