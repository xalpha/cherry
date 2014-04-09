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

# Config file for the cherry library
# It defines the following variables
#
# Cherry_INCLUDE_DIR - include directory for cherry headers
# Cherry_INCLUDE_DIRS - all include directories cherry needs
# Cherry_LIBRARY - library
# Cherry_LIBRARIES -

# version
set(Cherry_MAJOR_VERSION 0)
set(Cherry_MINOR_VERSION 0)
set(Cherry_PATCH_VERSION 1)
set(Cherry_VERSION ${Cherry_MAJOR_VERSION}.${Cherry_MINOR_VERSION}.${Cherry_PATCH_VERSION})

# set path
set( Cherry_DIR ${CMAKE_CURRENT_LIST_DIR})
set( ENV{Cherry_DIR} ${Cherry_DIR} )

# add module paths
list( APPEND CMAKE_MODULE_PATH ${Cherry_DIR}/cmake ${CMAKE_INSTALL_PREFIX}/share $ENV{HOME}/.local/share )

# find GL stuff
find_package( OpenGL REQUIRED )
find_package( GLEW REQUIRED )
find_package( GLUT REQUIRED )

# add debug definition
if( CMAKE_BUILD_TYPE MATCHES Debug )
    add_definitions( -DDEBUG )
endif()

# set the include dir
set( Cherry_INCLUDE_DIR "${Cherry_DIR}/include")

# set target names
set( Cherry_TARGET cherry )

# set compile definitions
set( Cherry_COMPILE_DEFINITIONS CHERRY CACHE INTERNAL "all compile definitions cherry needs"  )

# set linker flags
if( WIN32 )
	list( APPEND Cherry_LINK_FLAGS " /MANIFEST:NO" )
endif()

# set library paths
set( Cherry_LIBRARY ${Cherry_TARGET} CACHE INTERNAL "the cherry lib" )

# set include directories
set( Cherry_INCLUDE_DIRS
    ${Cherry_INCLUDE_DIR}
    ${EIGEN3_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
    ${GLUT_INCLUDE_PATH}
    ${GLEW_INCLUDE_DIR}
    ${Cherry_DIR}/extern/nyx/include
    ${Cherry_DIR}/src CACHE INTERNAL "all include directories cherry needs" )

# link libraries
set( Cherry_LINK_LIBRARIES
    -lm
    -lc
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
    ${GLEW_LIBRARIES} CACHE INTERNAL "all libs cherry needs" )

# set libraries
set( Cherry_LIBRARIES ${Cherry_LIBRARY} ${Cherry_LINK_LIBRARIES} CACHE INTERNAL "the cherry lib" )

# enable C++11 support
if( NOT WIN32 )
    if( CMAKE_COMPILER_IS_GNUCXX )
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++0x")
    else( CMAKE_COMPILER_IS_GNUCXX )
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -std=c++11 -v")
    endif()
endif()



