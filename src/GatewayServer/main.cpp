#include "GatewayApp.h"
#include "../ServerBase/Tools/JsonConfig.h"

int main()
{
	JsonConfig config;
	if (!config.Parse("GatewayServer.setting"))
	{
		return 0;
	}
	int port = config.GetInt("port");

	GatewayApp* gateway = new GatewayApp;
	gateway->Start(port);
	while (true)
	{
		gateway->Tick();
		boost::this_thread::sleep(boost::posix_time::milliseconds(100));
	}
	return 0;
}