
cmake_minimum_required(VERSION 3.20)

project("generated_code")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find requirements
find_package(fastcdr REQUIRED)
find_package(fastrtps 2.12 REQUIRED)


message(STATUS "Configuring DDSBase...")
add_library(DDSBase_lib DDSBase.cxx)
target_link_libraries(DDSBase_lib fastcdr fastrtps)

add_executable(DDSBase DDSBasePubSubTypes.cxx DDSBasePublisher.cxx DDSBaseSubscriber.cxx DDSBasePubSubMain.cxx)
target_link_libraries(DDSBase fastcdr fastrtps
        DDSBase_lib )


