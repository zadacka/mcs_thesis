// used for mouse callback
struct clientDataMouse{
    vtkCamera* camera;
    long unsigned int observerID;
    vtkCallbackCommand* observer;
};

static void CameraModifiedCallback (	
	vtkObject* caller,
	long unsigned int observerID,
    void* clientDataIn,
	void* vtkNotUsed(callData)  ){

    long unsigned int tempObserverID; 
    clientDataMouse* data = static_cast<clientDataMouse*>(clientDataIn);

    vtkCamera* camera = static_cast<vtkCamera*>(caller);
    vtkCamera* camera2 = data->camera;

    camera2->RemoveObserver(data->observerID);
    camera2->SetPosition(camera->GetPosition());
    camera2->SetFocalPoint(camera->GetFocalPoint());
    camera2->SetViewUp(camera->GetViewUp());
    tempObserverID = camera2->AddObserver(vtkCommand::ModifiedEvent, data->observer);
    data->observerID = tempObserverID;
}