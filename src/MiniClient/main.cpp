#include "MiniClient.h"
void main()
{
	MiniClient* miniClient = new MiniClient;
	miniClient->Start("127.0.0.1", 2034);
	while (true)
	{
		boost::this_thread::sleep(boost::posix_time::milliseconds(100));
	}
}