vtkRenderPassCollection *passes = vtkRenderPassCollection::New();
passes->AddItem(defalt_pass);
passes->AddItem(lights_pass);
vtkSequencePass *sequence=vtkSequencePass::New();
sequence->SetPasses(passes);
vtkCameraPass *camera_pass=vtkCameraPass::New();
camera_pass->SetDelegatePass(sequence);

// THIS PASS CONTAINS EXTRA GLSL PROCESSING!
vtkSaliencyPass* saliency_pass = vtkSaliencyPass::New();
saliency_pass->SetDelegatePass(camera_pass);

// Now render the window as normal...