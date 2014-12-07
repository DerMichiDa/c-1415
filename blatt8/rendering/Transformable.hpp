/**
 * @file Transformable
 *
 * @author Frank Mehne
 * @author Michael Micke
 */

#ifndef TRANSFORMABLE_HPP_
#define TRANSFORMABLE_HPP_

namespace 
{

/**
 * @brief 
 */
class Transformable : public Randerable
{
public:
    /**
     * @brief Default constructor.
     */
    Transformable();
    /**
     * @brief   Rotates a triangle mesh at the given axis with the giv    en speed
     * @param axis axis to rotate
     * @param speed speed of rotation
     */
    void rotate(int axis, float speed);
    /**
     * @brief   Moves a triangle mesh at the given axis with the given     speed
     * @param axis axis to move
     * @param speed speed of movement
     */
    void move(int axis, float speed);
private:
    /**
      * @brief The current orientation of the y axis
      */
    Vertex  m_yAxis;
    
    /**
     * @brief The current orientation of the z axis
     */
    Vertex  m_zAxis;
    
   
    /**
     * @brief The current position of the mesh object
     */
    Vertex  m_position;
  
    /**
     * @brief A quaternion representing the current rotation
     */
    Quaternion  m_rotation;
    /**
     * @brief The transformation matrix for this object
     */
    Matrix  m_transformation;


}

}

#endif
