#include <QApplication>
#include <iostream>
#include "gradebookmaingui.h"

int main(int argc, char **argv)
{
	try
	{
		QApplication app(argc, argv);
		GradebookMain main;
		main.show();
		return app.exec();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


}
