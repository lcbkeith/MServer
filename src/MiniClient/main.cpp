#include "MiniClient.h"
void main()
{

	io_service svc;
	for (int index = 0; index < 1000 ; index++)
	{
		MiniClient* miniClient = new MiniClient;
		miniClient->SetIOService(svc);
		miniClient->Start("127.0.0.1", 2034);
	}
	
	while (true)
	{
		boost::this_thread::sleep(boost::posix_time::milliseconds(100));
	}
}