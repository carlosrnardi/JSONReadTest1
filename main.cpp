#include <iostream>
#include <fstream>
#include "LibExample.hpp"
#include <nlohmann/json.hpp>
#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>
#include <boost/system/error_code.hpp>
#include <boost/system/system_error.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>

#define BUFSIZE 256
using json = nlohmann::json;
int main(int argc, char* argv[])
{
	std::cout << argv[0] << std::endl;
	std::ifstream f("example.json");
	//for (std::string line; std::getline(f, line); )
	//{
	//	std::cout << line << std::endl;
	//}
	try
	{
		// parsing input with a syntax error
		json data = json::parse(f);
		bool happy = data.value("happy", false);
		double pi = data.value("pi", 3.14);
		std::cout << happy << " " << pi << std::endl;
	}
	catch (json::parse_error& e)
	{
		// output exception information
		std::cout << "message: " << e.what() << '\n'
			<< "exception id: " << e.id << '\n'
			<< "byte position of error: " << e.byte << std::endl;
		exit(EXIT_FAILURE);
	}


	std::cout << "\nRead JSON File Example!!! " << AddFloat(float(1.1416), float(2.0)) << std::endl;

	boost::asio::io_service io;
	// Open serial port
	boost::asio::serial_port serial(io);
	try
	{
		serial.open("/dev/virtualcom0");
	}
	catch (boost::exception const& ex)
	{
		std::cout << "Serial port /dev/virtualcom0 not accessible\n";
		exit(EXIT_FAILURE);
	}
	
	// Configure basic serial port parameters: 115.2kBaud, 8N1
	serial.set_option(boost::asio::serial_port_base::baud_rate(115200));
	serial.set_option(boost::asio::serial_port_base::character_size(8 /* data bits */));
	serial.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
	serial.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
	// Read data in a loop and copy to stdout
	while (true) {
		char data[BUFSIZE];
		size_t n = serial.read_some(boost::asio::buffer(data, BUFSIZE));
		// Write data to stdout
		std::cout << "Data read -";
		std::cout.write(data, n);
		std::cout << std::endl;

		serial.write_some(boost::asio::buffer(data, n));
	}


	exit(EXIT_SUCCESS);
}