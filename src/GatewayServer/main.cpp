#include "GatewayApp.h"
void main()
{
	GatewayApp* gateway = new GatewayApp();
	gateway->Start(2034);
	while (true)
	{
		boost::this_thread::sleep(boost::posix_time::milliseconds(100));
	}
}