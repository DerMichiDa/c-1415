/**
 * @file Transformable.cpp
 *
 * @author Michael Micke
 * @author Frank Mehne
 */

#include "Transformable.hpp"

Transformable::Transformable()
{
    // Setup rotation and position
    m_xAxis         = Vertex(1.0, 0.0, 0.0);
    m_yAxis         = Vertex(0.0, 1.0, 0.0);
    m_zAxis         = Vertex(0.0, 0.0, 1.0);
    m_position      = Vertex(0.0, 0.0, 0.0);
 
    m_rotation.fromAxis(Vertex(0.0, 0.0, 1.0), 0.0f);

    // Set tranformation matrix to unit matrix
    for(int i = 0; i < 16; i++)
    {
        m_transformation[i] = 0.0f;
    }
    m_transformation[0 ] = 1.0f;
    m_transformation[5 ] = 1.0f;
    m_transformation[10] = 1.0f;
    m_transformation[15] = 1.0f;
}

void TriangleMesh::rotate(int axis, float s)
{

    Quaternion nq;

    // Get the wanted operation and calculate the new coordinates
    switch(axis)
    {
    case PITCH:
        nq.fromAxis(m_yAxis, s);
        m_xAxis = nq * m_xAxis;
        m_zAxis = nq * m_zAxis;
        break;
  
    case YAW:
        nq.fromAxis(m_xAxis, s);
        m_yAxis = nq * m_yAxis;
        m_zAxis = nq * m_zAxis;
        break;
  
    case ROLL:
        nq.fromAxis(m_zAxis, s);
        m_yAxis = nq * m_yAxis;
        m_xAxis = nq * m_xAxis;
        break;
    }
 
    // Update mesh rotation 
    m_rotation = m_rotation * nq;
}

void TriangleMesh::move(int axis, float speed)
{
    Vertex direction;

    // Determine the correct axis of the local system
    switch(axis)
    {
    case ACCEL:
        direction = m_zAxis;
        break;
    case STRAFE:
        direction = m_xAxis;
        break;
    case LIFT:
        direction = m_yAxis;
    }

    // Update mesh position
    m_position = m_position + direction * speed;
}

