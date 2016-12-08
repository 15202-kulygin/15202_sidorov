#ifndef _FEILD_WIDGET_H_
#define _FEILD_WIDGET_H_

#include <QtGui>
#include "feild.h"
	
class FeildWidget: public QWidget
{
	Q_OBJECT
public:	
	explicit FeildWidget(	QWidget *parent, 
							int length_, 
							int height_,
							std::vector<int> alive_cells );
	~FeildWidget();

public slots:
	void StepOnce();
	void StartPlay() {state = PLAY; time->start(0); time->setInterval(time_interval_ms);};
	void StopPlay() {state = REST; time->stop();};
	void Clear();

protected:
	void paintEvent(QPaintEvent *) override;
	void mousePressEvent(QMouseEvent *event) override;

private:
	Feild *feild;
	enum{ PLAY, REST }state;
	int dx_cell,dy_cell;
	void DrawGrid(QPainter *painter);
	void DrawCells(QPainter *painter);

	QTimer *time;
	
	//how much are the feild is going to stay from main window
	const int step_from_parent_x = 60;
	const int step_from_parent_y = 160;
	int time_interval_ms = 75;
};

#endif