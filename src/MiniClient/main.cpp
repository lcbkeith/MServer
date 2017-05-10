#include "MiniClient.h"

void CreateClient(int index)
{
	int clientCount = 1000;
	io_service* service = new io_service;
	std::vector<MiniClient*> clients;
	for (int idx = 0; idx < clientCount; idx++)
	{
		boost::this_thread::sleep(boost::posix_time::milliseconds(20));
		MiniClient* client = new MiniClient;
		client->SetID(index * 10000 + idx + 1);
		client->SetIOService(*service);
		client->Start("192.168.6.128", 2034, 0);

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
	for (int idx = 0; idx < 10 ; idx++)
	{
		boost::thread thrd(&CreateClient, idx + 1);
	}
	
	while (true)
	{
		boost::this_thread::sleep(boost::posix_time::milliseconds(100));
	}
	return 0;
}