////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// This file is part of cherry, a lightweight C++ particle engine             //
//                                                                            //
// Copyright (C) 2014 Alexandru Duliu                                         //
//                                                                            //
// cherry is free software: you can redistribute it and/or modify             //
// it under the terms of the GNU General Public License as published by       //
// the Free Software Foundation, either version 3 of the License, or          //
// (at your option) any later version.                                        //
//                                                                            //
// cherry is distributed in the hope that it will be useful,                  //
// but WITHOUT ANY WARRANTY; without even the implied warranty of             //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              //
// GNU General Public License for more details.                               //
//                                                                            //
// You should have received a copy of the GNU General Public License          //
// along with cherry.  If not, see <http://www.gnu.org/licenses/>.            //
//                                                                            //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdint.h>

#include <GL/glew.h>
#include <GL/glut.h>


/*
 * test_plot.cpp
 *
 *  Created on: Aug 21, 2012
 *      Author: alex
 */



/////
// GLUT callbacks
///
void idlefunc(void){ glutPostRedisplay(); }
void reshapefunc(int width,int height){  }
void motionfunc(int x,int y){  }
void keyboardfunc(unsigned char key,int x,int y){  }
void displayfunc(){ glClearColor(255,255,255,255);
                    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
                    glutSwapBuffers();}
void mousefunc(int button,int state,int x,int y)
{
    }


int main( int argc, char** argv )
{
    // init glut
    glutInit(&argc,argv);

    // initial size of viewport (client area of window)
    glutInitWindowSize(800,600);

    // Requests a double RGB-framebuffer with depth- and stencil-buffer
    glutInitDisplayMode( GLUT_MULTISAMPLE| GLUT_RGBA| GLUT_DEPTH );

    // Creates the window.
    glutCreateWindow( "nox: test plot" );

    // init GLEW
    int err = glewInit();
    if (GLEW_OK != err)	{
        // problem: glewInit failed, something is seriously wrong
        std::cerr << "nox::test_widget: GLEW error: \"" << glewGetErrorString(err) << "\"." << std::endl;

        exit(-1);
    }

    // Register the callback-functions. These are then executed by GLUT
    // as soon as the main loop is entered (see below)
    glutDisplayFunc(displayfunc);
    glutReshapeFunc(reshapefunc);
    glutMouseFunc(mousefunc);
    glutMotionFunc(motionfunc);
    glutKeyboardFunc(keyboardfunc);
    glutIdleFunc(idlefunc);

    // Enter GLUT main loop. Main loop will be terminated only
    // on user request by exit(0). Other means do not currently exist in GLUT.
    glutMainLoop();

    return 0;
}
