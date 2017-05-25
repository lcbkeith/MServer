#include "MiniClient.h"
#include "../ServerBase/Tools/JsonConfig.h"

int THREAD_COUNT = 1;
int CLIENT_PER_THREAD = 1;
std::string SERVER_IP = "127.0.0.1";
int SERVER_PORT = 10234;

void CreateClient(int index)
{
	io_service* service = new io_service;
	std::vector<MiniClient*> clients;
	for (int idx = 0; idx < CLIENT_PER_THREAD; idx++)
	{
		boost::this_thread::sleep(boost::posix_time::milliseconds(20));
		MiniClient* client = new MiniClient;
		client->SetID(index * 10000 + idx + 1);
		client->SetIOService(*service);
		client->Start(SERVER_IP.c_str(), SERVER_PORT);

		clients.push_back(client);
		std::cout << "client:" << client->GetID() << " create"<<std::endl;
	}

	while (true)
	{
		boost::this_thread::sleep(boost::posix_time::milliseconds(100));
		for (size_t idx = 0; idx < clients.size(); idx++)
		{
			clients[idx]->Tick();
		}
	}
}

int main()
{
	JsonConfig config;
	if (!config.Parse("MiniClient.setting"))
	{
		return 0;
	}

	SERVER_IP			= config.GetString("GateIP");
	SERVER_PORT			= config.GetInt("port");
	THREAD_COUNT		= config.GetInt("ThreadCount");
	CLIENT_PER_THREAD	= config.GetInt("ClientPerThread");

	for (int idx = 0; idx < THREAD_COUNT ; idx++)
	{
		boost::thread thrd(&CreateClient, idx + 1);
	}
	
	while (true)
	{
		boost::this_thread::sleep(boost::posix_time::milliseconds(100));
	}
	return 0;
}