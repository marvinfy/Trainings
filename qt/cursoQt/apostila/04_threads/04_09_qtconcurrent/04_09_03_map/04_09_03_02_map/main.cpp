
 #include <QtGui>

 #ifndef QT_NO_CONCURRENT

 using namespace QtConcurrent;

 const int iterations = 500;

 void spin(int &iteration)
 {
	const int work = 1000 * 1000 * 40;
	volatile int v = 0;
	for (int j = 0; j < work; ++j)
		++v;

	qDebug() << "iteration" << iteration << "in thread" 
									<< QThread::currentThreadId();
 }

 int main(int argc, char **argv)
 {
	QApplication app(argc, argv);

	// Prepare the vector.
	QVector<int> vector;
	vector.reserve( iterations);
	for (int i = 0; i < iterations; ++i)
		vector.append(i);

	// Create a progress dialog.
	QProgressDialog dialog;
	dialog.setLabelText(
		QString("Progressing using %1 thread(s)...").arg(
												QThread::idealThreadCount()));

	// Create a QFutureWatcher and connect signals and slots.
	QFutureWatcher<void> futureWatcher;

	QObject::connect(&futureWatcher, SIGNAL(finished()), 
											&dialog, SLOT(reset()));

	QObject::connect(&dialog, SIGNAL(canceled()), 
							&futureWatcher, SLOT(cancel()));

	QObject::connect(&futureWatcher, 
				SIGNAL(progressRangeChanged(int, int)), 
					&dialog, SLOT(setRange(int, int)));

	QObject::connect(&futureWatcher,
		SIGNAL(progressValueChanged(int)), 
				&dialog, SLOT(setValue(int)));

	// Start the computation.
	futureWatcher.setFuture(QtConcurrent::map(vector, spin));

	// Display the dialog and start the event loop.
	dialog.exec();

	futureWatcher.waitForFinished();

	// Query the future to check if was canceled.
	qDebug() << "Canceled?" << futureWatcher.future().isCanceled();

	return 0;
}

 #else

 int main()
 {
         qDebug() << "Qt Concurrent is not yet supported on this platform";
		 return 0;
 }

 #endif
