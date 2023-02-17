#pragma once
#include <glkit/core/glad/glad.h>
#include <GLFW/glfw3.h>


namespace glkit::core
{

/////////////////////////////////////////////////////////////////////////////////////////
// Common acestor for all objects wrapping OpenGL features, providing the unique ID

class GLObject_i
{
protected:
    unsigned int Id;
    static const size_t INFOLOG_BUFSZ = 0x200;

    GLObject_i() : Id(0U)
    {}

public:
    decltype(Id) getId() const
    {
        return Id;
    }
};

} // namespace glkit::core
