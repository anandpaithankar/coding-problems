#include "algo.h"

int read4(char buf[])
{
	memset(buf, 'a', (size_t)4);
	return 4;
}

int read(char buf[], int n)
{
	char buffer[4];
	int readBytes = 0; // number of bytes read.
	bool eof = false;

	while (!eof && readBytes < n)
	{
		// read 4 bytes into buffer
		int sz = read4(buffer);
		if (sz < 4)
		{
			eof = true;
		}
		// number of bytes already present in buffer
		// or number of bytes left in the buffer of size n.
		// Take the min of available bytes to read and number of bytes left to copy.
		int bytes = std::min(n - readBytes, sz);
		std::memcpy(buf + readBytes, buffer, bytes);
		readBytes += bytes;
	}
	return readBytes;
}

int main()
{
	constexpr int n = 10;
	char buff[n];
	std::cout << read(buff, n) << "\n";
	// for (auto x : buff)
	// {
	// 	std::cout << x << " ";
	// }
	std::cout << buff;
}