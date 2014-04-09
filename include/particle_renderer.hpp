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

#include <nyx/object/vertex_buffer_object.hpp>
#include <nyx/vis/widget.hpp>

/*
 * particle_renderer.cpp
 *
 *  Created on: Apr 9, 2014
 *      Author: alex
 */


template <typename T>
class particle_renderer : public nyx::widget<T>
{
public:
    typedef Eigen::Matrix<T,2,1> Vector2;
    typedef Eigen::Matrix<T,3,1> Vector3;
    typedef Eigen::Matrix<T,4,1> Vector4;
    typedef Eigen::Matrix<T,4,4> Matrix4;
    typedef nyx::vertex_buffer_object<T,unsigned int> VBO;

public:
    particle_renderer();
    virtual ~particle_renderer();

    virtual void draw();

protected:
    void init();
    void step();
    void update();

protected:
    static const size_t m_count = 1024;
    std::vector<T> m_positions;
    std::vector<T> m_directions;
    std::vector<T> m_colors;
    std::vector<T> m_age;

    VBO m_vbo;
};


/////
// Implementation
///

template <typename T>
inline particle_renderer<T>::particle_renderer()
{

}


template <typename T>
inline particle_renderer<T>::~particle_renderer()
{

}


template <typename T>
inline void particle_renderer<T>::draw()
{
    // clear buffer
    glClearColor( 128,128,128,255 );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the mvp matrix
    nyx::widget<T>::setView();

    step();
    m_vbo.draw();
}


template <typename T>
inline void particle_renderer<T>::init()
{
    // storage
    m_positions.resize( m_count*3 );
    m_colors.resize( m_count*4 );
    m_age.resize( m_count );

    // init values
    for( size_t i=0; i<m_count; i++ )
    {
        // this is now both our position and color
        Vector3 rand3 = Vector3::Random();

        // position, direction & color
        for( size_t j=0; j<3; j++ )
        {
            m_positions[i*3+j] = rand3(j);
            m_directions[i*3+j] = rand3(j);
            m_colors[i*4+j] = fabs( rand3(j) );
        }

        // age & alpha
        m_age[i] = fabs(rand3(2));
        m_colors[i*4+3] = cos( m_age[i]*3.141592654 );
    }

    // init VBO
    m_vbo.configure( 3, 4, 2, GL_POINTS );
    m_vbo.initVertices( m_positions.data(), m_count );
    m_vbo.initColors( m_colors.data );
}


template <typename T>
inline void particle_renderer<T>::step()
{

}

