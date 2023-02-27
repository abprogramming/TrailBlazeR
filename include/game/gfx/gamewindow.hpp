#pragma once

#include <glkit/window/glwindow.hpp>
#include <game/gfx/renderpipeline.hpp>


namespace trailblazer::gfx
{

class GameWindow_c : public glkit::window::GLWindow_i
{
public:
    using glkit::window::GLWindow_i::GLWindow_i;

protected:
    trailblazer::gfx::TilePipeline_c ppl;

    void initEvents() override
    {
        RenderPipeline_i::CameraConfig.Position.X = -3;
        RenderPipeline_i::CameraConfig.Position.Y = 0;
        RenderPipeline_i::CameraConfig.Position.Z = 0;
        RenderPipeline_i::CameraConfig.Direction.X = 1;
        RenderPipeline_i::CameraConfig.Direction.Y = 0;
        RenderPipeline_i::CameraConfig.Direction.Z = 0;

        RenderPipeline_i::ProjectionConfig.FOV = 45.F;
        RenderPipeline_i::ProjectionConfig.ScreenWidth = 640;
        RenderPipeline_i::ProjectionConfig.ScreenHeight = 480;
        RenderPipeline_i::ProjectionConfig.NearPlane = 0.1F;
        RenderPipeline_i::ProjectionConfig.FarPlane = 100.F;

        ppl.setup();
    }

    void drawEvents() override
    {
        ppl.run();
    }

    void keypressEvents() override
    {
        if (isPressed(GLFW_KEY_W))
        {
            RenderPipeline_i::CameraConfig.Position.Z += .05;
        }
        else if (isPressed(GLFW_KEY_S))
        {
            RenderPipeline_i::CameraConfig.Position.Z -= .05;
        }
        else if (isPressed(GLFW_KEY_A))
        {
            RenderPipeline_i::CameraConfig.Position.Y -= .05;
        }
        else if (isPressed(GLFW_KEY_D))
        {
            RenderPipeline_i::CameraConfig.Position.Y += .05;
        }
    }
};

} // namespace trailblazer::gfx