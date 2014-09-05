#include "vtkConeSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"
#include "vtkCamera.h"
#include "vtkActor.h"
#include "vtkRenderer.h"
#include "vtkShader2.h"
#include "vtkShaderProgram2.h"
#include "vtkShader2Collection.h"
#include "vtkSmartPointer.h"
#include "vtkOpenGLRenderWindow.h"
#include "vtkOpenGLProperty.h"

int main(){
    vtkSmartPointer<vtkConeSource> cone = vtkConeSource::New();

    vtkSmartPointer<vtkPolyDataMapper> coneMapper = vtkPolyDataMapper::New();
    coneMapper->SetInputConnection( cone->GetOutputPort() );

    vtkSmartPointer<vtkActor> coneActor = vtkActor::New();
    coneActor->SetMapper( coneMapper );

    vtkSmartPointer<vtkRenderer> ren= vtkRenderer::New();
    ren->AddActor( coneActor );

    vtkSmartPointer<vtkRenderWindow> renWin = vtkRenderWindow::New();
    renWin->AddRenderer( ren );

    // Apply a fragment shader from within VTK!
    const char* frag = "void propFuncFS(void){ gl_FragColor = vec4(255,0,0,1);}";

    vtkSmartPointer<vtkShaderProgram2> pgm = vtkShaderProgram2::New();
    pgm->SetContext(renWin);

    vtkSmartPointer<vtkShader2> shader=vtkShader2::New();
    shader->SetType(VTK_SHADER_TYPE_FRAGMENT);
    shader->SetSourceCode(frag);
    shader->SetContext(pgm->GetContext());
    pgm->GetShaders()->AddItem(shader);

    vtkSmartPointer<vtkOpenGLProperty> openGLproperty = 
    static_cast<vtkOpenGLProperty*>(coneActor->GetProperty());
    openGLproperty->SetPropProgram(pgm);
    openGLproperty->ShadingOn();

    for (int i = 0; i < 360; ++i){
        renWin->Render();
        ren->GetActiveCamera()->Azimuth( 1 );
    }
    return 0;
}
