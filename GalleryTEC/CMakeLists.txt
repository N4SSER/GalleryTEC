cmake_minimum_required(VERSION 3.20)
project(GalleryTEC)
set(CMAKE_CXX_STANDARD 14)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable(GalleryTEC main.cpp hencoder.cpp hencoder.h converter.cpp converter.h RAID5.cpp RAID5.h)
target_link_libraries(GalleryTEC ${OpenCV_LIBS} )