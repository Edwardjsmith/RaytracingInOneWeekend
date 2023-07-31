#include "Colour.h"
#include "Vector3.h"

int main()
{
	//Image constants 
	const int imageWidth = 256;
	const int imageHeight = 256;

	//Render image
	std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

	for (int j = imageHeight - 1; j >= 0; --j)
	{
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;

		for (int i = 0; i < imageWidth; ++i)
		{
			const Colour pixelColour(static_cast<double>(i) / (imageWidth - 1), static_cast<double>(j) / (imageHeight - 1), 0.25);
			WriteColour(std::cout, pixelColour);
		}
	}

	std::cerr << "\nDone.\n";

	return 0;
}