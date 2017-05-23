#include "MiniClient.h"
#include "../ServerBase/Tools/JsonConfig.h"

void CreateClient(int index)
{
	JsonConfig config;
	if (!config.Parse("MiniClient.setting"))
	{
		return;
	}

	std::string serverIP = config.GetString("GateIP");
	int port = config.GetInt("port");
	
	int clientCount = 1;
	io_service* service = new io_service;
	std::vector<MiniClient*> clients;
	for (int idx = 0; idx < clientCount; idx++)
	{
		boost::this_thread::sleep(boost::posix_time::milliseconds(20));
		MiniClient* client = new MiniClient;
		client->SetID(index * 10000 + idx + 1);
		client->SetIOService(*service);
		client->Start(serverIP.c_str(), port, 0);

		clients.push_back(client);
		std::cout << "client:" << client->GetID() << " create"<<std::endl;
	}

	while (true)
	{
		boost::this_thread::sleep(boost::posix_time::milliseconds(100));
		for (size_t idx = 0; idx < clients.size(); idx++)
		{
			clients[idx]->Update();
		}
	}
}

int main()
{
	for (int idx = 0; idx < 1 ; idx++)
	{
		boost::thread thrd(&CreateClient, idx + 1);
	}
	
	while (true)
	{
		boost::this_thread::sleep(boost::posix_time::milliseconds(100));
	}
	return 0;
}