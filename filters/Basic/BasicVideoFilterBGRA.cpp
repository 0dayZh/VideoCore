
#include <videocore/filters/Basic/BasicVideoFilterBGRA.h>

#include <TargetConditionals.h>


#ifdef TARGET_OS_IPHONE

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES3/gl.h>
#include <videocore/sources/iOS/GLESUtil.h>

#endif

namespace videocore { namespace filters {
 
    BasicVideoFilterBGRA::BasicVideoFilterBGRA()
    : IVideoFilter()
    {
        
    }
    BasicVideoFilterBGRA::~BasicVideoFilterBGRA()
    {
        
    }
    
    const char * const
    BasicVideoFilterBGRA::vertexKernel() const
    {
        
        KERNEL(GL_ES2_3, m_language,
               attribute vec2 aPos;
               attribute vec2 aCoord;
               varying vec2 vCoord;
               uniform mat4 uMat;
               void main(void) {
                gl_Position = uMat * vec4(aPos,0.,1.);
                vCoord = aCoord;
               }
        )
        
        return nullptr;
    }
    
    const char * const
    BasicVideoFilterBGRA::pixelKernel() const
    {
        
         KERNEL(GL_ES2_3, m_language,
               precision mediump float;
               varying vec2 vCoord;
               uniform sampler2D uTex0;
               void main(void) {
                   gl_FragData[0] = texture2D(uTex0, vCoord);
               };
        )
        
        return nullptr;
    }
    void
    BasicVideoFilterBGRA::initialize()
    {
        switch(m_language) {
            case GL_ES2_3:
            case GL_2:
                setProgram(build_program(vertexKernel(), pixelKernel()));
                
                break;
            case GL_3:
                break;
        }
    }
    void
    BasicVideoFilterBGRA::apply()
    {
        switch(m_language) {
            case GL_ES2_3:
            case GL_2:
                
                break;
            case GL_3:
                break;
        }
    }
}
}