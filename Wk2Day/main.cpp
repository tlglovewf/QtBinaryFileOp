#include <QtCore/QCoreApplication>
#include <qdebug.h>
#include <QString>
#include <map>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	while (1)
	{
		qDebug() << "please input time : " ;

		float time;

		scanf("%f", &time);


		double day = fmod(time, 86400);

		qDebug() << day << endl;

		day -= 18;
		int hour = day / 3600;
		int min = (day - (hour * 3600)) / 60;
		float sec = fmod(day, 60);

		qDebug() << hour << ":" << min << ":" << sec << endl;

		qDebug() << "quick?0(y):1(n)" << endl;

		scanf("%f", &time);
		if (time < 1)
		{
			exit(-1);
		}

	}



	exit(-1);
    return a.exec();
}
