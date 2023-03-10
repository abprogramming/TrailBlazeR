#pragma once

#include <memory>

#include <glkit/core/shaders/shaderprogram.hpp>
#include <glkit/core/uniforms/uniformiface.hpp>

#include <glkit/functors/camera.hpp>
#include <glkit/functors/model.hpp>
#include <glkit/functors/projection.hpp>
#include <glkit/functors/basiclightning_color.hpp>
#include <glkit/functors/basiclightning_position.hpp>

#include <glkit/mesh/glkcube.hpp>
#include <glkit/mesh/glksphere.hpp>


namespace trailblazer::presentation
{

class RenderPipeline_i
{
public:
    static glkit::functors::ProjectionConfig_s ProjectionConfig;
    static glkit::functors::CameraConfig_s CameraConfig;
    
    static glkit::functors::LightningColorConfig_s LightningColorConfig;
    static glkit::functors::LightningPositionConfig_s LightningPositionConfig;
    static glkit::functors::LightningPositionConfig_s CameraPositionConfig;
    
    glkit::functors::ModelConfig_s ModelConfig;
    glkit::functors::LightningColorConfig_s ModelColorConfig;

protected:
    glkit::core::shaders::ShaderSourceList_s SSL;
    
    std::unique_ptr<glkit::mesh::GLKMesh_i> Mesh;
    std::unique_ptr<glkit::core::shaders::ShaderProgram_c> ShaderProgram;
    std::unique_ptr<glkit::core::uniforms::ShaderUniformInterface_c> Uniforms;
    
    virtual void constructMesh() = 0;
    virtual void setupSSL() = 0;

public:
    void run();

    void setup();
};

} //trailblazer::presentation