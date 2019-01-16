#include <iostream>
#include <thread>
#include "hash.h"
#include "webcam.h"

//password is 6fN8QQvLfO1oHBGKShHTmfdgO2LoAg7L
const std::string PASSWORD = "ffe9027e6e4aac5bf171820d26e5957578cb313497f18d417016e7fac803ff08";
const int MAX_TRIES = 3;

int main()
{
	bool logged_in = false;
	std::string pass;
	std::thread capture_thread;
	for(int i = 0; i < MAX_TRIES; i++)
	{
		std::cout << "Please Enter Your Password: ";
		std::cin >> pass;
		if(PASSWORD.compare(sha256(pass))) //Wrong password
		{
			capture_thread = std::thread(capture, generate_file_name());
			capture_thread.detach();
			std::cout << "\aERROR: " << pass << " is not the password!" << std::endl
					  << "Please Try Again, You have " << MAX_TRIES - i - 1 << " attempts left." << std::endl;
		}
		else
		{
			logged_in = true;
		}
	}

	if(logged_in)
	{
		std::cout << "Well done! You are logged in." << std::endl;
	}

	system("pause");
	return 0;
}
