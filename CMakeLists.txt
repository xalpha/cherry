##############################################################################
#                                                                            #
# This file is part of cherry, a lightweight C++ particle engine             #
#                                                                            #
# Copyright (C) 2014 Alexandru Duliu                                         #
#                                                                            #
# cherry is free software: you can redistribute it and/or modify             #
# it under the terms of the GNU General Public License as published by       #
# the Free Software Foundation, either version 3 of the License, or          #
# (at your option) any later version.                                        #
#                                                                            #
# cherry is distributed in the hope that it will be useful,                  #
# but WITHOUT ANY WARRANTY; without even the implied warranty of             #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              #
# GNU General Public License for more details.                               #
#                                                                            #
# You should have received a copy of the GNU General Public License          #
# along with cherry.  If not, see <http://www.gnu.org/licenses/>.            #
#                                                                            #
##############################################################################

cmake_minimum_required(VERSION 2.8)
project(Cherry)

# guard against in-source builds
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. ")
endif()

# set some variabiles
#if( NOT WIN32 )
#    set( BUILD_SHARED_LIBS TRUE )
#endif()

# configure the project
include( CherryConfig.cmake )

# add the include files
list( APPEND Cherry_SRC src/main.cpp )

# set include directories
include_directories( ${Cherry_INCLUDE_DIRS} ${GLUT_LIBRARIES} ${Nyx_INCLUDE_DIRS} )

# add the target
add_executable( ${Cherry_TARGET} ${Cherry_SRC} )
target_link_libraries( ${Cherry_TARGET} ${Cherry_LINK_LIBRARIES} )

# install
#install(FILES ${Cherry_INC} DESTINATION "include/cherry" )

#install(FILES "${CMAKE_CURRENT_LIST_DIR}/cmake/FindCherry.cmake" DESTINATION share )
#install(FILES "${CMAKE_CURRENT_LIST_DIR}/cmake/FindGLEW.cmake" DESTINATION share )

# enable testing
#ENABLE_TESTING()

# add tests
#add_subdirectory(test)
