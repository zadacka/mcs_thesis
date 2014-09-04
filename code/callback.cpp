// used for keypress callback
struct ClientData{
    Rift* rift;
    vtkRenderer* renderer_l;
    vtkRenderer* renderer_r;
    vtkSaliencyPass* pass_l;
    vtkSaliencyPass* pass_r;
};

void KeypressCallbackFunction (
    vtkObject* caller,
    long unsigned int vtkNotUsed(eventId),
    void* clientData,
    void* vtkNotUsed(callData) ){

    vtkRenderWindowInteractor *iren =
	static_cast<vtkRenderWindowInteractor*>(caller);

    char* key = iren->GetKeySym();
    // care! GetKeySym returns things like 'space'!
    cout << "Pressed: " << key << endl;

    ClientData* cd = (ClientData*) clientData;

    if( 0 == strcmp("space", (const char*) key)){
    	// reset Cameras
     }
}

int main(){
	...
    vtkSmartPointer<vtkCallbackCommand> keypressCallback =
		vtkSmartPointer<vtkCallbackCommand>::New();
    keypressCallback->SetCallback ( KeypressCallbackFunction );
    keypressCallback->SetClientData( &clientdata);

    renderWindowInteractor->AddObserver (
	vtkCommand::KeyPressEvent,
	keypressCallback );
    ...
}