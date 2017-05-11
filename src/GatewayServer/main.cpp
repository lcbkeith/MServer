#include "GatewayApp.h"
int main()
{
	GatewayApp* gateway = new GatewayApp;
	gateway->Start(10011);
	while (true)
	{
		gateway->Tick();
		boost::this_thread::sleep(boost::posix_time::milliseconds(100));
	}
	return 0;
}