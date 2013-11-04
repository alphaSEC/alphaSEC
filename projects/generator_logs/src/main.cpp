// place your code here

#include <QFile>
#include <QDir>
#include <QDateTime>
#include <QCoreApplication>
#include <QTextStream>

#include <iostream>
#include <math.h>

// ---------------------------------------------------------------------------

int randInt(int low, int high)
{
    // Random number between low and high
    return qrand() % ((high + 1) - low) + low;
};

// ---------------------------------------------------------------------------

QStringList typeOfEvents;
QStringList ourEvents;

int main(int /*argc*/, char **/*argv[]*/)
{
	// 
	typeOfEvents << "try login";
	typeOfEvents << "login success";
	typeOfEvents << "login fail";
	typeOfEvents << "access to file";
	typeOfEvents << "access to deveice";
	typeOfEvents << "connected USB";
	typeOfEvents << "run program";
	typeOfEvents << "closed program";
	typeOfEvents << "disconnected USB";
	typeOfEvents << "print page";
	typeOfEvents << "scan page";

	// emulation brutforce
	int process_id = 2678;
	for(int i = 0; i < 35; i++)
		ourEvents << "try login";
	ourEvents << "login success";
	
	{
		QTime time = QTime::currentTime();
		qsrand((uint)time.msec());
	}
	QDateTime dtNow = QDateTime::currentDateTime();

	QDir dir("./");
	if(!QDir("logs").exists())
		dir.mkdir("logs");
	
	//QCoreApplication app(argc, argv);  //(we don't use these)
	QFile file("logs/" + dtNow.toString("yyyy-MM-dd-hh-mm-ss") + "_out.log");
	file.open(QIODevice::WriteOnly | QIODevice::Text);
	QTextStream out(&file);
	
	out << "var logs = [ \r\n";
	
	int sch = 0;
	
	while(sch < ourEvents.size())
	{
		dtNow = dtNow.addSecs(randInt(1,10));
		int choose = randInt(0,3);
		out << "\t{ \"datetime\" : \"" << dtNow.toString("yyyy-MM-dd hh:mm:ss ") << "\", \"user\" : \"SYSTEM\", \"process_id\" : ";
		
		if(choose == 0)
		{
			out << "\"" << process_id << "\", \"event\": \"" << ourEvents[sch] << "\"";
			sch++;
		}
		else
		{
			int t = randInt(0,typeOfEvents.size()-1);
			out << "\"" << randInt(1000,9999) << "\", \"event\": \"" << typeOfEvents[t] << "\"";
		}
		out << "},\r\n";
	}
	
	
	for(int i = 0; i < 100; i++)
	{
		dtNow = dtNow.addSecs(randInt(1,10));
		out << "\t{ \"datetime\" : \"" << dtNow.toString("yyyy-MM-dd hh:mm:ss ") << "\", \"user\" : \"SYSTEM\", \"process_id\" : ";
		int t = randInt(0, typeOfEvents.size()-1);
		out << "\"" << randInt(1000,9999) << "\", \"event\": \"" << typeOfEvents[t] << "\"";
		
		if(i == 99 )
			out << "}\r\n";
		else
		 	out << "},\r\n";
	}
	out << "];";
	
	file.close(); 
 
	return 0;
}
